
#include "answer05.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>

// ------------------------------------------------------------------ Predefines

/*
 * BMP files are laid out in the following fashion:
 *   --------------------------
 *   |          Header        |   54 bytes
 *   |-------------------------
 *   |    Palette (optional)  |   0 bytes (for 24-bit RGB images)
 *   |-------------------------
 *   |       Image Data       |   file size - 54 (for 24-bit images)
 *   --------------------------
 */

#define BMP_MAGIC_NUMBER 0x4d42
#define DEFAULT_DPI_X 3780
#define DEFAULT_DPI_Y 3780

#define FALSE 0
#define TRUE 1

/** 
 * BMP header (54 bytes).
 */

// Tell gcc that it should not add any padding to the BMP_Header struct
// Padding is sometimes (automagically) added to structs which can 
// sometimes help in high-performance code.
#pragma pack(push)
#pragma pack(1)  
typedef struct {
    uint16_t type;                      // Magic identifier
    uint32_t size;                      // File size in bytes
    uint16_t reserved1;                 // Not used
    uint16_t reserved2;                 // Not used
    uint32_t offset;                    // Offset to image data in bytes
    uint32_t header_size;               // Header size in bytes
    int32_t  width;                     // Width of the image
    int32_t  height;                    // Height of image
    uint16_t planes;                    // Number of color planes
    uint16_t bits;                      // Bits per pixel
    uint32_t compression;               // Compression type
    uint32_t imagesize;                 // Image size in bytes
    int32_t  xresolution;               // Pixels per meter
    int32_t  yresolution;               // Pixels per meter
    uint32_t ncolors;                  // Number of colors  
    uint32_t importantcolors;          // Important colors
} BMP_Header;
#pragma pack(pop)

static int BMP_checkValid(BMP_Header * header);
static void BMP_printHeader(BMP_Header * header);

// --------------------------------------------------------------- Image_loadbmp

Image * Image_loadbmp(const char * filename)
{    
    FILE * fp = NULL;
    size_t read;
    BMP_Header header;
    Image * tmp_im = NULL, * im = NULL;
    size_t n_bytes = 0;
    int err = FALSE;

    if(!err) { // Open filename
	fp = fopen(filename, "rb");
	if(!fp) {
	    fprintf(stderr, "Failed to open file '%s'\n", filename);
	    err = TRUE;
	}
    }

    if(!err) { // Read the header
	read = fread(&header, sizeof(BMP_Header), 1, fp);
	if(read != 1) {
	    fprintf(stderr, "Failed to read header from '%s'\n", filename);
	    err = TRUE;
	}
    }

    if(!err) { // Print the header
	BMP_printHeader(&header);
    }

    if(!err) { // We're only interested in a subset of valid bmp files
	if(!BMP_checkValid(&header)) {
	    fprintf(stderr, "Invalid header in '%s'\n", filename);
	    err = TRUE;
	}
    }

    if(!err) { // Allocate Image struct
	tmp_im = malloc(sizeof(Image));			
	if(tmp_im == NULL) {
	    fprintf(stderr, "Failed to allocate im structure\n");
	    err = TRUE;
	} 
    }

    if(!err) { // Init the Image struct
	tmp_im->width = header.width;
	tmp_im->height = header.height;

	// Handle the comment
	char * filename_cpy = strdup(filename);	// we want to call basename
	char * file_basename = basename(filename_cpy); // requires editable str
	const char * prefix = "Original BMP file: ";
	n_bytes = sizeof(char) * (strlen(prefix) + strlen(file_basename) + 1);
	tmp_im->comment = malloc(n_bytes);
	if(tmp_im->comment == NULL) {
	    fprintf(stderr, "Failed to allocate %zd bytes for comment\n",
		    n_bytes);
	    err = TRUE;
	} else {
	    sprintf(tmp_im->comment, "%s%s", prefix, file_basename);
	}
	free(filename_cpy); // this also takes care of file_basename

	// Handle image data
	n_bytes = sizeof(uint8_t) * header.width * header.height;
	tmp_im->data = malloc(n_bytes);
	if(tmp_im->data == NULL) {
	    fprintf(stderr, "Failed to allocate %zd bytes for image data\n",
		    n_bytes);
	    err = TRUE;
	}
    }

    if(!err) { // Seek the start of the pixel data
	if(fseek(fp, header.offset, SEEK_SET) != 0) {
	    fprintf(stderr, "Failed to seek %d, the data of the image data\n",
		    header.offset);
	    err = TRUE;
	}
    }

    if(!err) { // Read pixel data
	size_t bytes_per_row = ((header.bits * header.width + 31)/32) * 4;
	n_bytes = bytes_per_row * header.height;
	uint8_t * rawbmp = malloc(n_bytes);
	if(rawbmp == NULL) {
	    fprintf(stderr, "Could not allocate %zd bytes of image data\n",
		    n_bytes);
	    err = TRUE;
	} else {
	    read = fread(rawbmp, sizeof(uint8_t), n_bytes, fp);
	    if(n_bytes != read) {
		fprintf(stderr, "Only read %zd of %zd bytes of image data\n", 
			read, n_bytes);
		err = TRUE;
	    } else {
		// Must convert RGB to grayscale
		uint8_t * write_ptr = tmp_im->data;
		uint8_t * read_ptr;
		int intensity;
		int row, col; // row and column
		for(row = 0; row < header.height; ++row) {
		    read_ptr = &rawbmp[row * bytes_per_row];
		    for(col = 0; col < header.width; ++col) {
			intensity  = *read_ptr++; // blue
			intensity += *read_ptr++; // green
			intensity += *read_ptr++; // red	
			*write_ptr++ = intensity / 3; // now grayscale
		    }
		}
	    }
	}
	free(rawbmp);
    }

    if(!err) { // We should be at the end of the file now
	uint8_t byte;
	read = fread(&byte, sizeof(uint8_t), 1, fp);
	if(read != 0) {
	    fprintf(stderr, "Stray bytes at the end of bmp file '%s'\n",
		    filename);
	    err = TRUE;
	}
    }

    if(!err) { // We're winners... 
	im = tmp_im;  // bmp will be returned
	tmp_im = NULL; // and not cleaned up
    }

    // Cleanup
    if(tmp_im != NULL) {
	free(tmp_im->comment); // Remember, you can always free(NULL)
	free(tmp_im->data);
	free(tmp_im);
    }
    if(fp) {
	fclose(fp);
    }

    return im;
}

// --------------------------------------------------------------- Image_savebmp

int Image_savebmp(const char * filename, Image * image)
{
    int err = FALSE; 
    FILE * fp = NULL;
    uint8_t * buffer = NULL;    
    size_t written = 0;

    // Attempt to open file for writing
    fp = fopen(filename, "wb");
    if(fp == NULL) {
	fprintf(stderr, "Failed to open '%s' for writing\n", filename);
	return FALSE; // No file ==> out of here.
    }

    // Number of bytes stored on each row
    size_t bytes_per_row = ((24 * image->width + 31)/32) * 4;

    // Prepare the header
    BMP_Header header;
    header.type = BMP_MAGIC_NUMBER;
    header.size = sizeof(BMP_Header) + bytes_per_row * image->height;
    header.reserved1 = 0;
    header.reserved2 = 0;
    header.offset = sizeof(BMP_Header);
    header.header_size = sizeof(BMP_Header) - 14;
    header.width = image->width;
    header.height = image->height;
    header.planes = 1;
    header.bits = 24; // BGR
    header.compression = 0; // no compression
    header.imagesize = bytes_per_row * image->height;
    header.xresolution = DEFAULT_DPI_X;
    header.yresolution = DEFAULT_DPI_Y;
    header.ncolors = 1 << header.bits;
    header.importantcolors = 0; // i.e., every color is important

    if(!err) {  // Write the header
	written = fwrite(&header, sizeof(BMP_Header), 1, fp);
	if(written != 1) {
	    fprintf(stderr, 
		    "Error: only wrote %zd of %zd of file header to '%s'\n",
		    written, sizeof(BMP_Header), filename);
	    err = TRUE;	
	}
    }

    if(!err) { // Before writing, we'll need a write buffer
	buffer = malloc(bytes_per_row);
	if(buffer == NULL) {
	    fprintf(stderr, "Error: failed to allocate write buffer\n");
	    err = TRUE;
	} else {
	    // not strictly necessary, we output file will be tidier.
	    memset(buffer, 0, bytes_per_row); 
	}
    }

    if(!err) { // Write pixels	
	uint8_t * read_ptr = image->data;	
	int row, col; // row and column
	for(row = 0; row < header.height && !err; ++row) {
	    uint8_t * write_ptr = buffer;
	    for(col = 0; col < header.width; ++col) {
		*write_ptr++ = *read_ptr; // blue
		*write_ptr++ = *read_ptr; // green
		*write_ptr++ = *read_ptr; // red
		read_ptr++; // advance to the next pixel
	    }
	    // Write line to file
	    written = fwrite(buffer, sizeof(uint8_t), bytes_per_row, fp);
	    if(written != bytes_per_row) {
		fprintf(stderr, "Failed to write pixel data to file\n");
		err = TRUE;
	    }
	}
    }
    
    // Cleanup
    free(buffer);
    if(fp)
	fclose(fp);

    return !err;
}

// -------------------------------------------------------------- BMP_checkValid

/**
 * We are only interested in a subset of BMP functionality.
 */
static int BMP_checkValid(BMP_Header * header)
{
    // Make sure this is a BMP file
    if (header->type != BMP_MAGIC_NUMBER) return FALSE;

    // Make sure we are getting 24 bits per pixel
    if (header->bits != 24) return FALSE;

    // Make sure there is only one image plane
    if (header->planes != 1) return FALSE;

    // Make sure there is no compression
    if (header->compression != 0) return FALSE;

    // We're winners!!!
    return TRUE;
}

// ------------------------------------------------------------- BMP_printHeader

static void BMP_printHeader(BMP_Header * header)
{
    printf("Printing BMP header information:\n");
    printf("  file type (should be %x): %x\n", BMP_MAGIC_NUMBER, header->type);
    printf("  file size: %d\n", header->size);
    printf("  offset to image data: %d\n", header->offset);
    printf("  header size: %d\n", header->header_size);
    printf("  width: %d\n", header->width);
    printf("  height: %d\n", header->height);
    printf("  planes: %d\n", header->planes);
    printf("  bits: %d\n", header->bits);    
}

