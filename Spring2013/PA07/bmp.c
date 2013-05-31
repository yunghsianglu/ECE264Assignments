#include <stdlib.h>
#include <stdio.h>

#include "bmp.h"
#define BMP_HEADER_TYPE 0x4d42
#define BMP_HEADER_BITS 24
#define BMP_HEADER_PLANE 1

/*
 * 	You cannot use any "mysterious constants" below.
 * 	You need to define symbols above and use the symbols.
 * 	0 or 1 below are acceptable.
 */

BMP_Image *BMP_create(BMP_Header *header)
{
    // FILL IN CODE HERE!

    // allocate memory for the image structure
    // copy the header
    // image size is file size minus the size of the header
    // allocate memory for the data
    // return the image structure

    return NULL;
}

void BMP_destroy(BMP_Image *image)
{
    // FILL IN CODE HERE!
    
    // deallocate the allocated memory
}

BMP_Image *BMP_load(const char *filename)
{
    // FILL IN CODE HERE!

    // read the header from the file

    // print the header information (use BMP_printHeader)

    // make sure the header is valid before proceeding (use BMP_checkValid)
    
    // create the image structure (BMP_create)

    // read all of the image data

    // return the image

    return NULL; 
}

void BMP_invert(BMP_Image *image)
{
    // FILL IN CODE HERE!

    // loop through each byte in the image data
    // replace each byte "value" the image data with "255 - value"
}

int BMP_save(BMP_Image *image, const char *filename)
{
    // FILL IN CODE HERE!
    
    // write the BMP header

    // write the image data

    return 0;
}

// == DO NOT MODIFY ANYTHING BELOW THIS POINT ==============

int BMP_checkValid(BMP_Header *header)
{
    // Make sure this is a BMP file
    if (header->type != BMP_HEADER_TYPE) return 0;

    // Make sure we are getting 24 bits per pixel
    if (header->bits != BMP_HEADER_BITS) return 0;

    // Make sure there is only one image plane
    if (header->planes != BMP_HEADER_PLANE) return 0;

    // Make sure there is no compression
    if (header->compression != 0) return 0;

    return 1;
}

void BMP_printHeader(BMP_Header *header)
{
    printf("file type (should be %x): %x\n", BMP_HEADER_TYPE, header->type);
    printf("file size: %d\n", header->size);
    printf("offset to image data: %d\n", header->offset);
    printf("header size: %d\n", header->header_size);
    printf("width: %d\n", header->width);
    printf("height: %d\n", header->height);
    printf("planes: %d\n", header->planes);
    printf("bits: %d\n", header->bits);
}
