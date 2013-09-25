/* 
 * Do not modify this file.
 */
#ifndef PA06_H
#define PA06_H

#include <stdint.h>

#define FALSE 0
#define TRUE 1

#define ECE264_IMAGE_MAGIC_BITS 0x21343632

struct ImageHeader {
    uint32_t magic_bits; // Should be ECE264_IMAGE_MAGIC_BITS
    uint32_t width;      // [width x height], cannot be zero
    uint32_t height;
    uint32_t comment_len;// A comment added to the file
};

struct Image {
    int width;
    int height;
    char * comment;
    uint8_t * data;
};

// -- Load an image from disk
struct Image * loadImage(const char* filename);

// -- Deletes any resources allocated to the image
void freeImage(struct Image * image);

void linearNormalization(struct Image * image);

#endif /* pa06.h */

