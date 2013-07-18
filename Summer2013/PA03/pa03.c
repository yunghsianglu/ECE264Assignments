/* 
 * Do not modify this file.
 */
#include "pa03.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void showUsage()
{
    printf("\n"
	   "   Usage: pa03 <image-file-1> <image-file-2> <output-filename>\n"
	   "\n"
	   "      (1) Loades image-file-1 and image-file-2\n"
	   "      (2) Convolves 2 with 1\n"
	   "      (3) Draws a bounding box around the convolution peak\n"
	   "      (4) Saves the result to \"output-filename\" in PPM format\n"
	   "\n");
}

static void setPixel(uint8_t* pixels, int width, int height, int x, int y, int c, uint8_t value)
{
    if(x < 0 || y < 0 || c < 0 || x >= width || y >= width || c >= 3)
	return; // index out of bounds
    int idx = (x + y * width)*3 + c; // three bytes per pixel. i.e., RGB
    pixels[idx] = value;
}

static int processResult(struct Image* image, struct Point peak, int width, int height, const char* filename)
{
    // Save the image in "ppm" format
    int result = 0; // i.e., failure

    // Firstly, we want to draw a bounding box around 'peak', in the read channel.
    // We'll need to convert the image data to RGB...
    uint8_t* pixels = (uint8_t*) malloc(image->width * image->height * 3);
    if(!pixels)
	return 0; // i.e., faiture to allocate memory
    const int im_size = image->width * image->height;
    const uint8_t* im_data = image->data;
    const uint8_t* end = image->data + im_size;
    uint8_t* itr = pixels;
    for( ; im_data < end; ++im_data) {
	*itr++ = *im_data; // R
	*itr++ = *im_data; // G
	*itr++ = *im_data; // B
    }
 

    // Now draw the red box
    int x, y;
    int pad = 3;
    for(x = peak.x - pad; x <= peak.x + width + pad; ++x) {
	setPixel(pixels, image->width, image->height, x, peak.y - pad, 0, 0xff);
	setPixel(pixels, image->width, image->height, x, peak.y + height + pad, 0, 0xff);
    }
    for(y = peak.y - pad; y <= peak.y + height + pad; ++y) {
	setPixel(pixels, image->width, image->height, peak.x - pad, y, 0, 0xff);
	setPixel(pixels, image->width, image->height, peak.x + width + pad, y, 0, 0xff);
    }
   
    // Now write the image in PPM format. You can read PPM with "gimp" of "feh"
    FILE* fp = fopen(filename, "wb");
    if(fp) {
	fprintf(fp, "P6\n# %s\n%d %d 255\n", image->comment, image->width, image->height);
	fwrite(pixels, image->width * image->height * 3, 1, fp);
	fclose(fp);
	result = 1; // i.e, success
    }

    free(pixels);
    return result;
}

int main(int argc, char * * argv)
{
    int result = EXIT_SUCCESS;
    struct Image* image1 = NULL;
    struct Image* image2 = NULL;

    // parse command-line arguments
    if(argc != 4) {
	showUsage();
    } else {
	image1 = loadImage(argv[1]);
	if(!image1) {
	    fprintf(stderr, "Failed to load image file '%s'\n", argv[1]);
	    result = EXIT_FAILURE;
	}
	image2 = loadImage(argv[2]);
	if(!image2) {
	    fprintf(stderr, "Failed to load image file '%s'\n", argv[2]);
	    result = EXIT_FAILURE;
	}
	if(image1 && image2) {
	    struct Point peak = convolutionMax(image1, image2);
	    if(!processResult(image1, peak, image2->width, image2->height, argv[3]))
		result = EXIT_FAILURE;
	}
    }

    freeImage(image1);
    freeImage(image2);
    return result;
}
