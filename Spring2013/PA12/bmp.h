#ifndef _BMP_H_
#define _BMP_H_

// ====== DO NOT MODIFY THIS FILE ===========

// Set data alignment to 1 byte boundary
#pragma pack(1)     

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

/** 
 * BMP header (54 bytes).
 */

typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef int int32_t;

typedef struct {
    uint16_t type;                      // Magic identifier
    uint32_t size;                      // File size in bytes
    uint16_t reserved1;     // Not used
    uint16_t reserved2;       // Not used
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
    uint32_t ncolours;                  // Number of colors  
    uint32_t importantcolours;          // Important colors

} BMP_Header;

typedef struct {
    BMP_Header header;
    int data_size;
    int width;
    int height;
    int bytes_per_pixel; // This amount should be equals to number of bits/8
    char *data;
} BMP_Image;

// Constructor - creates a new BMP image structure
BMP_Image *BMP_create(BMP_Header *header);

// Load a BMP image given a filename (will create a new BMP image structure)
// Returns NULL if failure.
BMP_Image *BMP_load(const char *filename);

// Save a BMP image given a filename, 
// returns 0 if failure
// returns 1 if success
int BMP_save(BMP_Image *image, const char *filename);

// Destructor - deallocates a BMP image structure
void BMP_destroy(BMP_Image *image);

// Invert all of the image data in a BMP image (value = 255 - value)
void BMP_invert(BMP_Image *image, int numThread);

// Print the contents of the BMP header (provided)
void BMP_printHeader(BMP_Header *header);

// Check whether the BMP file is a valid file (provided)
int BMP_checkValid(BMP_Header *header);

#endif /* bmp.h */
