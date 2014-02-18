
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "answer07.h"

// Many of the required functions are defined in:
// testcases/test_support_functions.c

static int test_merge(List * lhs, List * rhs, 
		      int (*compar)(const char *, const char *))
{
    int success = TRUE; // until proven otherwise

    // First make sure our lists are sorted...
    lhs = List_sort_sol(lhs, compar);
    rhs = List_sort_sol(rhs, compar);

    // What are we testing?
    printf("Testing List_merge(lhs, rhs, compar), where:\n\n");
    printf("+ compar is: ");
    print_compar(compar);
    printf("\n");
    printf("+ lhs is: ");
    List_print(lhs);
    printf("\n");
    printf("+ rhs is: ");
    List_print(rhs);
    printf("\n");

    // Check that the student doesn't reallocate nodes... store lhs/rhs pointers
    int len = List_length_sol(lhs) + List_length_sol(rhs);
    List * * nodeArr = malloc(len * sizeof(List *));
    int ind = 0;
    List * node = NULL;
    node = lhs;
    while(node != NULL) {
	nodeArr[ind++] = node;
	node = node->next;
    }
    node = rhs;
    while(node != NULL) {
	nodeArr[ind++] = node;
	node = node->next;
    }
    
    // Clone lhs, rhs, and get the solution
    List * solution = List_merge_sol(List_clone(lhs), List_clone(rhs), compar);

    // Run the students code
    List * merged = List_merge(lhs, rhs, compar);

    printf("\nmerged is  : ");
    List_print(merged);
    printf("\nsolution is: ");
    List_print(solution);
    printf("\n");
    
    // Are we the correct length?
    int merged_len = List_length_sol(merged);
    if(merged_len != len) {
	printf("Error: merged solution has length %d, but it should be %d\n",
	       merged_len, len);
	success = FALSE;
    }

    // Check the solution is in order, and that every Node pointer is in nodeArr
    List * sol_node = solution;
    node = merged;
    while(node != NULL && sol_node != NULL) {
	int found = FALSE;
	for(ind = 0; ind < len && !found; ++ind)
	    found = (nodeArr[ind] == node);
	if(!found) {
	    printf("Error: merged list contained a node with pointer %p; \n"
		   "however, this pointer was not in either of the inputs.\n"
		   "(i.e., 'lhs', or 'rhs'.) You must not create or destroy\n"
		   "any nodes when writing the merge function.\n", node);
	    success = FALSE;
	}
	if(strcmp(node->str, sol_node->str) != 0) {
	    printf("Error: merged list not in order (!)\n");
	    success = FALSE;
	}
	sol_node = sol_node->next;
	node = node->next;
    }

    // Cleanup.
    free(nodeArr);
    List_destroy_sol(solution);
    List_destroy_sol(merged);
    return success;
}

int tests_List_merge(int test_number)
{
    int n_tests = 11;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests)
	return n_tests; // return how many distinct test-cases we have.
    
    switch(test_number) {
    case  0: return test_merge(NULL, NULL, strcmp_forward); 

    case  1: return test_merge(make_list(0), NULL, strcmp_forward); 
    case  2: return test_merge(NULL, make_list(0), strcmp_forward); 

    case  3: return test_merge(make_list(0), make_list(1), strcmp_forward); 
    case  4: return test_merge(make_list(0), make_list(1), strcmp_reverse); 

    case  5: return test_merge(make_list(2), make_list(3), strcmp_forward);
    case  6: return test_merge(make_list(2), make_list(3), strcmp_reverse);
    case  7: return test_merge(make_list(2), make_list(3), strcmp_int);

    case  8: return test_merge(make_list(4), make_list(5), strcmp_forward);
    case  9: return test_merge(make_list(4), make_list(5), strcmp_reverse);

    case 10: return test_merge(make_list(6), make_list(7), strcmp_length);
    }

    return FALSE;
}

