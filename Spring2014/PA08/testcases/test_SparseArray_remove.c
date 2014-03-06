#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_remove(int test_number) {
    int n_tests = 8;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests) {
        //return how many distinct test-cases we have.
        return n_tests; 
    }

    // Assume failure unless otherwise noted
    int success = FALSE;

    printf("Testing: SparseNode_remove(a%d)\n", test_number);
    SparseNode * sol_node = NULL;
    SparseNode * stu_node = NULL;

    //build the arrays for removal
    sol_node = make_array(test_number);
    stu_node = make_array(test_number);

    printf("Built array a%d:\n", test_number);
    print_array(sol_node, 0);

    printf("Remove Node with index %d:\n", test_number+test_number);
    stu_node = SparseArray_remove(stu_node, test_number+test_number);
    sol_node = SparseArray_remove_sol(sol_node, test_number+test_number);
    printf("Student result after remove:\n");
    print_array(stu_node, 0);
    printf("Solution result after remove:\n");
    print_array(sol_node, 0);

    printf("Checking if result tree is the same...\n");
    if(cmp_array(stu_node, sol_node)) {
        success = TRUE;
    }

    // Cleanup
    if(sol_node) {
        SparseArray_destroy_sol(sol_node);
    }
    if(stu_node) {
        SparseArray_destroy_sol(stu_node);
    }
    return success;
}
