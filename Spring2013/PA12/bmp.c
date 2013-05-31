#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "bmp.h"

#define SUCCESS 0
#define FAILURE -1

/* a region as the indexes for the pixels */
typedef struct 
{
	int index1; /* inclusive */
	int index2; /* inclusive */
	char * data;
} Region;

BMP_Image *BMP_create(BMP_Header *header)
{
    // FILL IN CODE HERE!

    // allocate memory for the image structure
    // copy the header
    // image size is file size minus the size of the header
    // allocate memory for the data
    // return the image structure
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
}

void * invert_Region(void * reg){
	// FILL IN CODE HERE!
	
	// loop through each byte in the image data region
	// replace each byte "value" the image data with "255 - value"
	
	//exit the thread with with a return value of SUCCESS)
}
void BMP_invert(BMP_Image *image, int numThread)
{
	// loop through the number of threads the program will spawn
		
		//Calculate the starting and ending indices for the data region
		//the thread will be inverting
	
		//Store the location of the image data into the data region
		
		//Initialize the attributes for the thread
	
	//Make sure the ending index of the last thread is within the bounds 
	//of the image data
	
	// loop through the number of threads the program will spawn
	
		//Print the starting and ending indicies of the data region for 
		//the thread
	
		//Create the thread 
	
	// loop through the number of threads the program will spawn
		
		//Wait for all of the threads to finish executing
	
	
}

int BMP_save(BMP_Image *image, const char *filename)
{
    // FILL IN CODE HERE!
    
    // write the BMP header

    // write the image data
}

// == DO NOT MODIFY ANYTHING BELOW THIS POINT ==============

int BMP_checkValid(BMP_Header *header)
{
    // Make sure this is a BMP file
    if (header->type != 0x4d42) return 0;

    // Make sure we are getting 24 bits per pixel
    if (header->bits != 24) return 0;

    // Make sure there is only one image plane
    if (header->planes != 1) return 0;

    // Make sure there is no compression
    if (header->compression != 0) return 0;

    return 1;
}

void BMP_printHeader(BMP_Header *header)
{
    printf("file type (should be 0x4d42): %x\n", header->type);
    printf("file size: %d\n", header->size);
    printf("offset to image data: %d\n", header->offset);
    printf("header size: %d\n", header->header_size);
    printf("width: %d\n", header->width);
    printf("height: %d\n", header->height);
    printf("planes: %d\n", header->planes);
    printf("bits: %d\n", header->bits);
}
