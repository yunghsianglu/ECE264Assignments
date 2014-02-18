
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer07.h"

#define TRUE 1
#define FALSE 0

int tests_List_destroyNode(int test_number)
{
    const char * test1[] = { "single node" };
    const char * test2[] = { "one", "two", "three", "four", "five", "six" };
    const char * test3[] = {}; // empty
    const char * * arrs[] = { test1, test2, test3 };
    int arrsLen = sizeof(arrs) / sizeof(char * *);
    int arrsSizeOf[] = { sizeof(test1), sizeof(test2), sizeof(test3) };

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= arrsLen)
	return arrsLen; // return how many distinct test-cases we have.

    const char * * arr = arrs[test_number];
    int len = arrsSizeOf[test_number] / sizeof(char * *);
    int ind;

    // Create the list of interest
    List * list = NULL;
    List * tail = NULL;
    for(ind = 0; ind < len; ++ind) {
	if(list == NULL) {
	    list = List_createNode_sol(arr[ind]);
	    tail = list; 
	} else {
	    tail->next = List_createNode_sol(arr[ind]);
	    tail = tail->next;
	}
    }
   
    // Explain what's about to happen
    printf("Testing: List_destroyNode(list), where list is: ");
    tail = list;
    while(tail != NULL) {
	printf("\"%s\" ==> ", tail->str);    
	tail = tail->next;
    }
    printf("NULL\n");

    // Call List_destroy(list)
    List_destroy(list);

    return TRUE;
}

