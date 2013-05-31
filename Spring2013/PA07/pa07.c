#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

/* ======== DO NOT MODIFY THIS FILE! ======== */

int main(int argc, char **argv)
{
    // Check arguments
    if (argc < 3) {
	printf("Usage: pa07 <source> <destination>\n");
	return EXIT_FAILURE;
    }

    // Load the input file
    BMP_Image *image = BMP_load(argv[1]);
    if (image == NULL) {
	printf("Input file invalid!\n");
	return EXIT_FAILURE;
    }

    // Invert the file
    BMP_invert(image);

    // Save the file
    if (!BMP_save(image, argv[2])) {
	printf("Output file invalid!\n");
	BMP_destroy(image);
	return EXIT_FAILURE;	
    }
    
    // Destroy the BMP image
    BMP_destroy(image);

    return EXIT_SUCCESS;
}
