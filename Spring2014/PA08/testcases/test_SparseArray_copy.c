#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_copy(int test_number) {
    int n_tests = 8;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests) {
        //return how many distinct test-cases we have.
        return n_tests; 
    }

    // Assume failure unless otherwise noted
    int success = FALSE;

    printf("Testing: SparseNode_copy(a%d)\n", test_number);
    SparseNode * orig_node = NULL;
    SparseNode * sol_node = NULL;
    SparseNode * stu_node = NULL;

    //build the array to be copied
    orig_node = make_array(test_number);

    printf("Built array a%d:\n", test_number);
    print_array(orig_node, 0);

    printf("Copy Node:\n");
    sol_node = SparseArray_copy_sol(orig_node);
    stu_node = SparseArray_copy(orig_node);
    printf("Student result after copy:\n");
    print_array(stu_node, 0);
    printf("Solution result after copy:\n");
    print_array(sol_node, 0);

    printf("Checking if result tree is the same...\n");
    if(cmp_array(stu_node, sol_node)) {
        success = TRUE;
    }

    // Cleanup
    if(orig_node) {
        SparseArray_destroy_sol(orig_node);
    }
    if(sol_node) {
        SparseArray_destroy_sol(sol_node);
    }
    if(stu_node) {
        SparseArray_destroy_sol(stu_node);
    }
    return success;
}
