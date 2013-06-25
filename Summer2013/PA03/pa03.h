/*
 * Do not modify this file
 */

#pragma once

#include <stdint.h>

#define ECE264_IMAGE_MAGIC_BITS 0x00343632

struct ImageHeader {
    uint32_t magic_bits; // Should be ECE264_IMAGE_MAGIC_BITS
    uint32_t width; // [width x height] image, cannot be zero
    uint32_t height;
    uint32_t comment_len;
};

struct Image {
    int width;
    int height;
    char* comment;
    uint8_t* data;
};

struct Point {
    int x, y;
};

// -- Load an image from disk
struct Image* loadImage(const char* filename);

// -- Deletes any resources allocated to the image
void freeImage(struct Image* image);

// -- Perform a convolution, returning the co-ordinates of the peak value
struct Point convolutionMax(const struct Image* image1, 
			    const struct Image* image2);






