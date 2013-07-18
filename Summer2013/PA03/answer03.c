/*
 * For this assigment you will write some functions that help 
 * accomplishing the following procedure:
 * (1) Load two images from disk
 * (2) Run a convolution, returning the [x, y] co-ordiantes of the peak value
 * (3) Save the image back to disk, with a bounding box drawn around the peak.
 *
 * You DO NOT need to write part (3). To complete the assignment you need
 * to fill out the functions in this file, which accomplish (1) and (2).
 * These functions are called by the main(...) function in pa03, which
 * also performs (3). Please refer to that file (but do not change it).
 *
 * Hint: 
 * You can write additonal functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "pa03.h"

/*
 * ============================================================================
 * This function loads in image from disk. The file is stored in a custom image 
 * file format that supports 8-bit grayscale images. That means that every 
 * pixel in the image has a single 8-bit value (0..255), which denotes the 
 * intensity, or amount of whiteness at that pixel.
 *
 * The file has a 16 byte header whose binary layout is given by the struct 
 * ImageHeader in the file "pa03.h". The full explanation of this header is:
 * + 4 byte integer: "magic number" 0x00343632. The first 4 bytes of the file
 * always start with this number (in little-endian format). If this number is
 * absent, then there is something wrong with the file.
 * + 4 byte integer: width of the image
 * + 4 byte integer: height of the image
 * + 4 byte integer: length of an ASCII string file comment including NULL-byte
 *
 * The next N bytes is a null-termianted ASCII string. The length of the string
 * is specified in the last field of the header. The length inclues the 
 * trailing NULL byte.
 *
 * After the ASCII string, there are width*height bytes of sequential data.
 * Each byte is /unsigned/, and represents the intensity of a pixel in the
 * range [0..255]. The intensity of the pixel is its "whiteness". A value of
 * 255 denotes a fully white pixel, and a value of 0 denotes a fully black 
 * pixel. 
 *
 * The pixels are stored in "row-major-order" from top-to-bottom. That means 
 * that the first byte if the intensity of pixel [0, 0], which is the top-left
 * corner of the image. After reading "width" number of pixels, you will arrive
 * at the start of the second row of pixels, which is the intensity of
 * coordinate [0, 1]: the first pixel of the second line of the image.
 *
 * In general, pixel[x, y] == image->data[x + y*width] where (x, y) is the x-y
 * co-ordinate of the pixel, with x increasing left-to-right, and y increasing
 * top-to-bottom.
 *
 * To complete this function, you must use fopen to open the file, check that
 * the file was truly opened, and then read the image into memory. To read the
 * image, you must first read the 16 byte header (checking that 16 bytes were
 * read) and then check the magic-bits. You must then allocate memory for a new
 * Image pointer, fill in the width and height, and read the comment and data
 * from disk.
 *
 * If /any/ error occurs at all, then return NULL. Return NULL even if the 
 * image header looks good, but you don't read all the byte from the file. 
 * Return NULL even if you read every byte successfully, but fail t reached 
 * the end of the file. If there are no errors, then return a pointer to a
 * newly allocated Image struct.
 * 
 * LEAK NO RESOURCES
 *
 * Good luck.
 */
struct Image* loadImage(const char* filename)
{
<<<<<<< HEAD
	return NULL;
=======
    return NULL;
>>>>>>> fc8a43cb050e9320bc696adb69bf34207ecf4601
}


/*
 * ============================================================================
 * loadImage(...) (above) allocates memory for an image structure. This 
 * function must clean up any allocated resources. If image is NULL, then you 
 * do nothing. If you do not write this function correctly, then valgrind will 
 * report an error. 
 */
void freeImage(struct Image* image)
{

}

/*
 * ============================================================================
 * Convolve image2 with image1 and return the co-ordinates of the peak value.
 * Convolutions in discrete space are essentially dot-products of vectors,
 * except that you have "vectors" that are in fact two different sized 
 * matrices of 8-bit integers. The convolution works as follows:
 * (1) For every (x, y) value in image1 you calculate a dot-product with the 
 * all the pixels in image2. 
 * (2) To calculate the dot-product, you must (conceptually) place the corner
 * co-ordinate of image2 (0, 0) at point (x, y) in image1.
 * (3) The pixels in image2 will now have corresponding pixels in image1.
 * (4) Multiply the corresponding pixels together, sum the results, and that
 * is the convolution result for point (x, y). (Your job is to return the 
 * (x, y) co-ordinates with the maximum value.)
 * 
 * For example, say image1 is 640x480 pixels, and image2 is RGB 3x3 pixels, 
 * and you want to calculate the convolution result at pixel (20, 39). In this 
 * case:
 * 
 * // For C(20, 39)
 * uint convolution = image1[20, 39] * image2[0, 0]  
 *                  + image1[21, 39] * image2[1, 0]  
 *                  + image1[22, 39] * image2[2, 0]  
 *                  + image1[20, 40] * image2[0, 1]  
 *                  + image1[21, 40] * image2[1, 1]  
 *                  + image1[22, 40] * image2[2, 1]  
 *                  + image1[20, 41] * image2[0, 2]  
 *                  + image1[21, 41] * image2[1, 2]  
 *                  + image1[22, 41] * image2[2, 2]  
 *
 * Where image1[20, 39] == image1->data[20 + 39*640]
 *
 * To avoid a memory violation, you must make sure that you never access memory
 * outside the bounds of the pixel data in the image. (i.e., don't try 
 * image1[701, 100] for a 640x480 image).
 *
 * For more information on convolutions see: 
 * http://en.wikipedia.org/wiki/Convolution
 */
<<<<<<< HEAD

struct Point convolutionMax(const struct Image* image1, 
			    const struct Image* image2)
{
	struct Point peak;
	peak.x = 0;
	peak.y = 0;

	return peak;
=======
struct Point convolutionMax(const struct Image* image1, 
			    const struct Image* image2)
{
    struct Point peak;
    peak.x = 0;
    peak.y = 0;

    return peak;
>>>>>>> fc8a43cb050e9320bc696adb69bf34207ecf4601
}




