#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_destroy(int test_number) {
    int n_tests = 8;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests) {
        //return how many distinct test-cases we have.
        return n_tests; 
    }

    printf("Testing: SparseNode_destroy(a%d)\n", test_number);
    SparseNode * sol_node = NULL;

    //build the array to be destroyed
    sol_node = make_array(test_number);

    printf("Built array a%d:\n", test_number);
    print_array(sol_node, 0);

    // Cleanup
    printf("Destroy array...\n");
    if(sol_node) {
        SparseArray_destroy(sol_node);
    }
    return TRUE;
}
