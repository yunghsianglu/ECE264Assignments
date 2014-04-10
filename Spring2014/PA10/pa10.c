
#include "answer10.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#define TRUE 1
#define FALSE 0

void printUsage(char * argv0)
{
    printf("\n"
	   "   Usage: %s <cmd> <arg>\n"
	   "\n"
	   "      <cmd> can be one of 'sort', 'sortable',\n"
	   "      or 'shapes'.\n"
	   "\n"
	   "      If <cmd> is 'sort' or 'sortable', then\n"
	   "      <arg> must be a unique sequence of\n"
	   "      digits from [0-9]. 'sort' will sort them,\n"
	   "      and 'sortable' will print 'Y' or 'N'\n"
	   "      depending on whether they are stack-\n"
	   "      sortable.\n"
	   "\n"
	   "      If <cmd> is 'shapes', then <arg> must be\n"
	   "      a digit from [1..9] inclusive, and will\n"
	   "      print all the _unique_ shapes of binary\n"
	   "      trees with that many nodes.\n"
	   "\n"
	   , basename(argv0));
}

int charcmp(const void * a, const void * b)
{
    return *((char*)a) - *((char*)b);
}

/**
 * A way to check if an input string is a valid array of integers [0..9]
 */
int checkArrayStr(const char * str)
{
    int len = strlen(str);
    if(len == 0)
	return FALSE;

    int ret = TRUE;
    char * cpy = strdup(str);
    qsort(cpy, len, sizeof(char), charcmp);

    if(cpy[0] < '0' || cpy[len-1] > '9')
	ret = FALSE;

    // Now just check for duplicates...
    int i;
    for(i = 1; i < len && ret; ++i)
	if(cpy[i] == cpy[i-1])
	    ret = FALSE;

    free(cpy);
    return ret;
}

int main(int argc, char * * argv)
{
    if(argc != 3) {
	printUsage(argv[0]);
	if(argc == 2 && strcmp("--help", argv[1]) == 0)
	    return EXIT_SUCCESS;
	return EXIT_FAILURE;
    }

    int ret = EXIT_SUCCESS; // until otherwise noted
    const char * cmd = argv[1];
    int * array = NULL;
    int len = 0;
    int i;

    // Read array if integers (if applicable)
    if(strcmp(cmd, "sort") == 0 || strcmp(cmd, "sortable") == 0) {
	const char * arrstr = argv[2];
	if(!checkArrayStr(arrstr)) {
	    fprintf(stderr, "Invalid array, aborting\n");
	    return EXIT_FAILURE;
	}
	len = strlen(arrstr);
	array = malloc(sizeof(int) * len);
	for(i = 0; i < len; ++i) 
	    array[i] = arrstr[i] - '0';
    }

    if(strcmp(cmd, "sort") == 0) { // -- Sort command
	stackSort(array, len);
	for(i = 0; i < len; ++i)
	    printf("%d", array[i]);
	printf("\n");
    } else if(strcmp(cmd, "sortable") == 0) { // -- Sortable command
	if(isStackSortable(array, len))
	    printf("Y\n");
	else
	    printf("N\n");
    } else if(strcmp(cmd, "shapes") == 0) { // -- Shapes command
	len = strtol(argv[2], NULL, 10);
	if(len < 1 || len > 9) {
	    fprintf(stderr, "Invalid number of shapes... aborting\n");
	    ret = EXIT_FAILURE;
	} else {
	    genShapes(len);
	}
    } else { // -- An error
	fprintf(stderr, "Invalid command: '%s', aborting\n", cmd);
    }

    free(array);

    return ret;
}

