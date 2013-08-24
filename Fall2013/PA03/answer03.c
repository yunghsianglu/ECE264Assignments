
#include "pa03.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Read a file of integers.
 *
 * Parameters:
 * @filename A filename containing a list of integers (one per line)
 * @numberOfIntegers A pointer to store the number of integers in the file
 *
 * Returns:
 * A properly filled array of integers, or NULL if /any/ error is encountered.
 *
 * Comments:
 * You do NOT know how many integers are in the file until after you have read
 * it. Once you know how many integers there are, you can initialise the
 * "numberOfIntegers" variable. (Note that this is a pointer, not an integer!)
 * You can also allocate memory to store the return result.
 * 
 * Once memory is allocated to contain the resulting integers, you will need
 * to re-read them from the file. To do this, you must reset the read-pointer
 * to the start of the file using the function "fseek". You can google fseek
 * to see how to use it.
 *
 * The easiest way to read integeres is to use the "fscanf" function.
 *
 * The interwebs is your friend.
 */
int * readIntegers(const char * filename, int * numberOfIntegers)
{
    return NULL;
}

/**
 * Sort an (ascending) array of integers
 *
 * Parameters:
 * @arr    The array to search
 * @length Number of elements in the array
 *
 * Comments:
 * Uses "quicksort" to sort "arr". Wikipedia has an excellent article 
 * on quicksort. Use the first element of the array as the pivot.
 */
void sort(int * arr, int length)
{
    
}

/**
 * Use a binary search to find 'key' in a sorted array of integers
 *
 * Parameters:
 * @arr    The array to search. Must be sorted ascending.
 * @length Number of elements in the array
 * @key    Value to search for in @arr
 *
 * Returns:
 * The index of 'key', or -1 if key is not found.
 *
 * Comments:
 * Don't forget that arrays are 'zero-indexed'. Also, you must
 * use a binary search to pass this question.
 */
int search(int * arr, int length, int key)
{
    return -1;
}


