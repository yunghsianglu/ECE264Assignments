#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_getMax(int test_number) {
    int n_tests = 7;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests) {
        //return how many distinct test-cases we have.
        return n_tests; 
    }

    // Assume failure unless otherwise noted
    int success = FALSE;

    printf("Testing: SparseNode_getMax(a%d)\n", test_number);
    SparseNode * sol_node = NULL;

    //build the array to be searched 
    sol_node = make_array(test_number);

    printf("Built array a%d:\n", test_number);
    print_array(sol_node, 0);

    int stu = SparseArray_getMax(sol_node);
    int sol = SparseArray_getMax_sol(sol_node);
    printf("Student getMax: %d\n", stu);
    printf("Solution getMax: %d\n", sol);

    if(stu == sol) {
        success = TRUE;
    }

    // Cleanup
    if(sol_node) {
        SparseArray_destroy_sol(sol_node);
    }
    return success;
}
