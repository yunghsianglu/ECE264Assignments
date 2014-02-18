
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer07.h"

#define TRUE 1
#define FALSE 0

int tests_List_createNode(int test_number)
{
    const char * strings[] = {
	"",
	"The quick brown Fox",
	"jumped over the",
	"lazy dog."
    };
    int stringsLen = sizeof(strings) / sizeof(char *);

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= stringsLen)
	return stringsLen; // return how many distinct test-cases we have.

    // Assume failure unless otherwise noted
    int success = FALSE; 

    // The string for this testcase
    const char * s = strings[test_number];

    printf("Testing: List_createNode(\"%s\")\n", s);
    List * list = List_createNode(s);
    if(list == NULL) {
	printf("Error: NULL result detected.\n");
    } else if(list->next != NULL) {
	printf("Error: list->next must be NULL.\n");
    } else if(list->str == s) {
	printf("Error: must copy the passed string!\n");
    } else if(list->str == NULL) {
	printf("Error: NULL string detected\n");
    } else if(strcmp(list->str, s) != 0) {
	printf("Error: list->str is not \"%s\"\n", s);
    } else {
	success = TRUE;
    }

    // Cleanup
    if(list) {
	if(list->str && list->str != s)
	    free(list->str);
	free(list);
    }

    return success;
}

