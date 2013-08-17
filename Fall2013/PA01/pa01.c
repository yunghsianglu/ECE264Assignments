/* 
 * Do not modify this file.
 */
#include "pa01.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

static void printUsage(char * exec_path)
{
    const char * exec_name = basename(exec_path);
    printf("\n"
	   "   Usage: %s <filename>\n"
	   "\n"
	   "   Input files are in the \"inputs\" directory. Thus you can\n"
	   "   try something like:\n"
	   "\n"
	   "      aturing > ./%s inputs/input0\n"
	   "\n"
	   "   and you should get something like:\n"
	   "\n"
	   "      sum = -3772.\n"
	   "      The array has 54 negative elements.\n"
	   "      The elements are not increasing.\n"
	   "\n", 
	   exec_name, exec_name);
}

int main(int argc, char * * argv)
{
    if (argc != 2)
	{
	    printUsage(argv[0]);
	    return EXIT_FAILURE;
	}
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
	{
	    printUsage(argv[0]);
	    return EXIT_SUCCESS;
	}
    FILE * fptr = fopen(argv[1], "r");
    if (fptr == NULL)
	{
	    fprintf(stderr, "Failed to open file '%s', aborting!\n", argv[1]);
	    return EXIT_FAILURE;
	}
    int length = 0;
    int value;
    while (fscanf(fptr, "%d", & value) == 1)
	{
	    length ++;
	}
    fseek (fptr, 0, SEEK_SET);
    int * arr = malloc(length * sizeof(int));
    length = 0;
    while (fscanf(fptr, "%d", & (arr[length])) == 1)
	{
	    // printf("arr[%d] = %d\n", length, arr[length]);
	    length ++;
	}
    int sum = addElement(arr, length);
    int neg = countNegative(arr, length);
    int inc = isIncreasing(arr, length);
    printf("sum = %d.\n", sum);
    printf("The array has %d negative elements.\n", neg);
    printf("The elements are ");
    if (inc == 0)
	{
	    printf("not ");
	}
    printf("increasing.\n");
    printf("\n");
    free (arr);
    fclose (fptr);
    return EXIT_SUCCESS;
}

