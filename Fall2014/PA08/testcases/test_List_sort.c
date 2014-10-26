
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer08.h"

#define TRUE 1
#define FALSE 0

// Many of the required functions are defined in:
// testcases/test_support_functions.c

static int test_sort(List * list, int (*compar)(const char *, const char *))
{
    int success = TRUE; // until proven otherwise

    printf("Testing List_sort(list, compar), where:\n\n");
    printf("+ compar is: ");
    print_compar(compar);
    printf("\n");
    printf("+ list is: ");
    List_print(list);
    printf("\n");

    // Check that the student doesn't reallocate nodes... store list pointers
    int len = List_length_sol(list);
    List * * nodeArr = malloc(len * sizeof(List *));
    int ind = 0;
    List * node = NULL;
    node = list;
    while(node != NULL) {
	nodeArr[ind++] = node;
	node = node->next;
    }

    // Clone lhs, rhs, and get the solution
    List * solution = List_sort_sol(List_clone(list), compar);

    // Run the students code
    List * sorted = List_sort(list, compar);

    // Display what we got
    printf("\nsorted is  : ");
    List_print(sorted);
    printf("\nsolution is: ");
    List_print(solution);
    printf("\n");

    // Are we the correct length?
    int sorted_len = List_length_sol(sorted);
    if(sorted_len != len) {
	printf("Error: sorted solution has length %d, but it should be %d\n",
	       sorted_len, len);
	success = FALSE;
    }

    // Check the solution is in order, and that every Node pointer is in nodeArr
    List * sol_node = solution;
    node = sorted;
    while(node != NULL && sol_node != NULL) {
	int found = FALSE;
	for(ind = 0; ind < len && !found; ++ind)
	    found = (nodeArr[ind] == node);
	if(!found) {
	    printf("Error: sorted list contained a node with pointer %p; \n"
		   "however, this pointer was not in the input list. You must\n"
		   "not create or destroy nodes when merge-sorting linked\n"
		   "lists.\n", node);
	    success = FALSE;
	}
	if(strcmp(node->str, sol_node->str) != 0) {
	    printf("Error: sorted list not in order (!)\n");
	    success = FALSE;
	}
	sol_node = sol_node->next;
	node = node->next;
    }

    // Cleanup memory
    free(nodeArr);
    List_destroy_sol(solution);
    List_destroy_sol(sorted);
    return success;
}

int tests_List_sort(int test_number)
{
    int n_tests = 16;

     // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests)
	return n_tests; // return how many distinct test-cases we have.
    
    switch(test_number) {

    case  0: return test_sort(NULL, strcmp_forward);

    case  1: return test_sort(make_list(0), strcmp_forward);
    case  2: return test_sort(make_list(0), strcmp_reverse);

    case  3: return test_sort(make_list(1), strcmp_forward);
    case  4: return test_sort(make_list(1), strcmp_reverse);

    case  5: return test_sort(make_list(2), strcmp_forward);
    case  6: return test_sort(make_list(2), strcmp_reverse);
    case  7: return test_sort(make_list(2), strcmp_int);

    case  8: return test_sort(make_list(3), strcmp_forward);
    case  9: return test_sort(make_list(3), strcmp_reverse);
    case 10: return test_sort(make_list(3), strcmp_int);

    case 11: return test_sort(make_list(4), strcmp_forward);
    case 12: return test_sort(make_list(4), strcmp_reverse);

    case 13: return test_sort(make_list(5), strcmp_forward);
    case 14: return test_sort(make_list(5), strcmp_reverse);

    case 15: return test_sort(make_list(6), strcmp_length);
    }

    return FALSE;
}


