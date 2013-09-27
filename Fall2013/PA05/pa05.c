/*
 * Do not modify this file.
 * If you modify this file, your program will fail in grading.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"
int main(int argc, char ** argv)
{
    if (argc < 4)
	{
	    printf("\n"
		   "   Usage: ./pa05 <option> <input-file> <output-file>\n"
		   "\n"
		   "      <option> can be either 's' for a string sort, or 'i'\n"
		   "      for an integer sort.\n"
		   "\n"
		   );
	    return EXIT_FAILURE;
	}
    if (strcmp(argv[1], "i") == 0) /* sort integers */
	{
	    int numInteger = 0;
	    int * arrInteger = NULL;
	    arrInteger = readInteger(argv[2], & numInteger);
	    if (numInteger == 0)
		{
		    return EXIT_FAILURE;
		}
	    printf("\n");
	    printInteger(arrInteger, numInteger);
	    printf("\n\n   // ~ Printing Sorted Output ~ //\n\n");
	    sortInteger(arrInteger, numInteger);
	    printInteger(arrInteger, numInteger);
	    printf("\n");
	    saveInteger(argv[3], arrInteger, numInteger);
	    freeInteger(arrInteger, numInteger);
	    return EXIT_SUCCESS;
	}
    else if (strcmp(argv[1], "s") == 0) /* sort strings */
	{
	    int numString = 0;
	    char * * arrString = NULL;
	    arrString = readString(argv[2], & numString);
	    if (numString == 0)
		{
		    return EXIT_FAILURE;
		}
	    printf("\n");
	    printString(arrString, numString);
	    sortString(arrString, numString);
	    printf("\n\n   // ~ Printing Sorted Output ~ //\n\n");
	    printString(arrString, numString);
	    printf("\n");
	    saveString(argv[3], arrString, numString);
	    freeString(arrString, numString);
	    return EXIT_SUCCESS;
	}
    else 
	{
	    fprintf(stderr, "Unknown <option>, '%s'. Should be either 's' or 'i'\n",
		    argv[1]);
	}
    /* unknown type */
    return EXIT_FAILURE;
}
