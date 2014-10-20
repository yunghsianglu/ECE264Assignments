/**
 * Do not modify this file.
 */
#ifndef PA07_H
#define PA07_H

#include <stdint.h>

#define ECE264_IMAGE_MAGIC_NUMBER 0x21343632

// Tell gcc not to pad structs with extra bytes.
// Padding is sometimes included for performance reasons.
#pragma pack(1)

typedef struct ImageHeader_st {
    uint32_t magic_number; // Should be ECE264_IMAGE_MAGIC_NUMBER
    uint32_t width;        // [width x height], cannot be zero
    uint32_t height;
    uint32_t comment_len;  // A comment embedded in the file
} ImageHeader;

typedef struct Image_st {
    int width;
    int height;
    char * comment;
    uint8_t * data;
} Image;

/**
 * Loads a bmp (windows bitmap) image, returning an Image structure.
 * Will return NULL if there is any error.
 *
 * Note: This function is written for you and appears in image-bmp.c
 */
Image * Image_loadbmp(const char * filename);

/**
 * Saves an Image structure to a file. Returns TRUE if success, or
 * FALSE if there is any error.
 *
 * Note: This function is written for you and appears in image-bmp.c
 */
int Image_savebmp(const char * filename, Image * image);

/**
 * Loads an ECE264 image file, returning an Image structure.
 * Will return NULL if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
Image * Image_load(const char * filename);

/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image);

/**
 * Free memory for an image structure
 *
 * Image_load(...) (above) allocates memory for an image structure. 
 * This function must clean up any allocated resources. If image is 
 * NULL, then it does nothing. (There should be no error message.) If 
 * you do not write this function correctly, then valgrind will 
 * report an error. 
 */
void Image_free(Image * image);

/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity);

#endif

