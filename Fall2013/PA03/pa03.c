/* 
 * Do not modify this file.
 */

#include "pa03.h"

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
	   "   Usage: %s <inputfile>\n"
	   "\n"
	   "         Reads file <inputfile> (of integers), sorts them and prints them.\n"
	   "         Then, returns the ordinal position of the first number (unsorted) in the sorted list,\n"
	   "         and the ordinal position of the number 1 greater than that (if it exists).\n"
	   "\n",
	   exec);
}

const char * oridinalSuffix(int index)
{
    if(index % 10 == 1 && index != 11)
	return "st";
    if(index % 10 == 2 && index != 12) 
	return "nd";
    return "th";
}

void printSearchResult(int key, int index, int okay)
{
    printf("Integer '%d' ", key);
    if(index >= 0)
	printf("in the %d%s position in the sorted array", index, oridinalSuffix(index));
    else
	printf("not found");
    if(okay)
	printf(" -- pass.\n");
    else
	printf(" -- FAIL.\n");
}

int isSortedAscending(int * arr, int len)
{
    int i;
    for(i = 1; i < len; ++i)
	if(arr[i] < arr[i-1])
	    return FALSE;
    return TRUE;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
	printUsage(argv[0]);
	return EXIT_FAILURE;
    }

    // Parse command-line arguments
    if (argc == 2 && (strcmp(argv[0], "-h") == 0 || strcmp(argv[0], "--help") == 0)) 
	{
	    printUsage(argv[0]);
	    return EXIT_SUCCESS;
	}
    
    // Read and sort integers, then find 'index'
    const char * filename = argv[1];
    int length = 0;
    int * integers = readIntegers(filename, &length);
    if(integers == NULL || length <= 0) 
	{
	    fprintf(stderr, "Failed to read integer-file '%s', aborting\n", filename);
	    return EXIT_FAILURE;
	}

    // This is what we will search for
    int key = integers[0];
    int key2 = key + 1;

    // -- Print the unsorted array
    printf("Unsorted array:");
    int i;
    for(i = 0; i < length; ++i) 
	{
	    printf(" % 3d", integers[i]);
	}
    printf("\n");
    
    // -- Sort (and search)
    sort(integers, length);
    int index = search(integers, length, key);
    int index2 = search(integers, length, key2);

    // -- Use a linear search to find the correct index2
    int index2_res = -1;
    for(i = 0; i < length && index2_res == -1; ++i)
	if(integers[i] == key2)
	    index2_res = i;

    // -- Did we do everything correctly?
    int is_sorted = isSortedAscending(integers, length);
    int key1_okay = index >= 0 && index < length && integers[index] == key;
    int key2_okay = index2 == index2_res;

    // -- Print results
    printf("Sorted array:  ");
    for(i = 0; i < length; ++i) 
	{
	    printf(" % 3d", integers[i]);
	}
    if(is_sorted)
	printf(" -- correct.\n");
    else
	printf(" -- FAIL (not sorted).\n");

    printSearchResult(key, index, key1_okay);
    printSearchResult(key2, index2, key2_okay);

    // -- Clean up
    free(integers);

    if(is_sorted && key1_okay && key2_okay)
	return EXIT_SUCCESS;
    return EXIT_FAILURE;
}
