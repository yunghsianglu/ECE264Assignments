 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include "answer07.h"

void print_usage(char * argv0)
{
    printf("\n"
	   "   Usage: %s <in-filename> <out-filename>\n"
	   "\n"
	   "      Reads bmp image file <in-filename> and then:\n"
	   "      (1) Converts it to grayscale\n"
	   "      (2) Inverts pixel intensity\n"
	   "      (3) Writes inverted image to bmp file <out-filename>\n"
	   "\n",
	   basename(argv0));
}

/**
 * Welcome to PA07.
 *
 * This file is an example to help you get started.
 * It works on BMP files and inverts the pixel intensity (whiteness)
 * You will need to write routines to read and write the simpler
 * ece264 format, and perform linear normalization.
 */
int main(int argc, char * * argv)
{
    int ret = EXIT_SUCCESS; // unless otherwise noted

    // Parse input arguments
    if(argc != 3) {
	print_usage(argv[0]);
	if(argc == 2 && strcmp(argv[1], "--help") == 0)
	    return EXIT_SUCCESS;
	return EXIT_FAILURE;
    }

    const char * in_filename = argv[1];
    const char * out_filename = argv[2];

    // Read the file
    Image * im = Image_loadbmp(in_filename);
    if(im == NULL) {
	fprintf(stderr, "Error: failed to read '%s'\n", in_filename);
	return EXIT_FAILURE;
    }

    // Invert pixel intensity
    int n_pixels = im->width * im->height;
    int ind;
    for(ind = 0; ind < n_pixels; ++ind)
	im->data[ind] = 255 - im->data[ind];

    // Write out a new file
    if(!Image_savebmp(out_filename, im)) {
	fprintf(stderr, "Error attempting to write '%s'\n", out_filename);
	ret = EXIT_FAILURE;
    }

    Image_free(im); // a memory leak until you write this function

    return ret;
}

