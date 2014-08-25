#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_getNode(int test_number) {
    int n_tests = 8;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests) {
        //return how many distinct test-cases we have.
        return n_tests; 
    }

    // Assume failure unless otherwise noted
    int success = FALSE;

    printf("Testing: SparseNode_getNode(a%d)\n", test_number);
    SparseNode * sol_node = NULL;
    SparseNode * stu_get = NULL;
    SparseNode * sol_get = NULL;

    //build the array to search
    sol_node = make_array(test_number);

    printf("Built array a%d:\n", test_number);
    print_array(sol_node, 0);

    printf("Find Node with index %d:\n", test_number*test_number);
    stu_get = SparseArray_getNode(sol_node, test_number*test_number);
    sol_get = SparseArray_getNode_sol(sol_node, test_number*test_number);
    if(stu_get != NULL){
        printf("Student  getNode index: %d, value: %d\n", stu_get->index, stu_get->value);
    }
    else {
        printf("Student  getNode returned NULL\n");
    }
    if(sol_get != NULL){
        printf("Solution getNode index: %d, value: %d\n", sol_get->index, sol_get->value);
    }
    else {
        printf("Solution getNode returned NULL\n");
    }

    printf("Checking if node is the same...\n");
    if(stu_get == sol_get && cmp_array(stu_get, sol_get)) {
        success = TRUE;
    }

    // Cleanup
    if(sol_node) {
        SparseArray_destroy_sol(sol_node);
    }
    return success;
}
