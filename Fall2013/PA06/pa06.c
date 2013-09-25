/* 
 * Do not modify this file.
 */

#include "pa06.h"

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void printUsage(char * exec_path)
{
    const char * exec = basename(exec_path);
    printf("\n"
	   "   Usage: %s <image-file> <output-filename>\n"
	   "\n"
	   "      Loads <image-file> which is a black and white\n"
	   "      image file in ee264 file. Then applies linear\n"
	   "      normalization, and saves the output in\n"
	   "      <output-filename> in ppm format.\n"
	   "\n",
	   exec);
}

static int writePPM(struct Image * image, const char * filename)
{
    // Save the image in "ppm" format
    int result = FALSE; // Assume failure

    // PPMs are 3-channel 
    const int im_size = image->width * image->height;
    uint8_t * pixels = malloc(sizeof(uint8_t) * im_size * 3); 
    if(!pixels)
	return 0; // i.e., faiture to allocate memory
    const uint8_t * im_data = image->data;
    const uint8_t * end = image->data + im_size;
    uint8_t * itr = pixels;
    for( ; im_data < end; ++im_data) 
	{
	    *itr++ = *im_data; // R
	    *itr++ = *im_data; // G
	    *itr++ = *im_data; // B
	}
    
    // Now write the image in PPM format. 
    // You can read PPMs with "gimp" of "feh"
    FILE* fp = fopen(filename, "wb");
    if(fp) 
	{
	    fprintf(fp, "P6\n# %s\n%d %d 255\n", 
		    image->comment, image->width, image->height);
	    if(fwrite(pixels, im_size * 3, 1, fp) == 1)
		result = TRUE; // i.e., success
	    fclose(fp);
	}

    free(pixels);
    return result;
}

int main(int argc, char *argv[])
{
    // Parse command-line arguments
    if (argc >= 2 && (strcmp(argv[0], "-h") == 0 
		      || strcmp(argv[0], "--help") == 0))
	{
	    printUsage(argv[0]);
	    return EXIT_SUCCESS;
	}
    if (argc != 3) 
	{
	    printUsage(argv[0]);
	    return EXIT_FAILURE;
	}

    int ret = EXIT_FAILURE; // Assume failure

    const char * in_filename = argv[1];
    const char * out_filename = argv[2];

    struct Image * image = loadImage(in_filename);
    if(image == NULL) 
	{
	    fprintf(stderr, 
		    "Failed to load image file '%s'\n", argv[1]);
	}
    else 
	{
	    linearNormalization(image);
	    if(writePPM(image, out_filename))
		ret = EXIT_SUCCESS; // we're winners!
	}
    freeImage(image);
    
    return ret;
}


