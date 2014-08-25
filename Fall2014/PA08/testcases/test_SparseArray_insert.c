#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_insert(int test_number) {
    const int indices[] = {4,1,0,40000,6,30,2,5,4};
    const int values[] = {30,22,100,3,5,-7,-30,0,20};

    int sparseArrayLen = sizeof(indices) / sizeof(int);

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= sparseArrayLen) {
        //return how many distinct test-cases we have.
        return sparseArrayLen; 
    }

    // Assume failure unless otherwise noted
    int success = FALSE;
    
    const int ind = indices[test_number];
    const int val = values[test_number];

    printf("Testing: SparseNode_insert(array, %d, %d)\n", ind, val);
    SparseNode * stu_node = NULL;
    SparseNode * sol_node = NULL;
    int i;
    for(i = 0; i < test_number+1; i++) {
        stu_node = SparseArray_insert(stu_node, indices[i], values[i]);
        sol_node = SparseArray_insert_sol(sol_node, indices[i], values[i]);
    }

    printf("Student result:\n");
    print_array(stu_node, 0);
    printf("Solution result:\n");
    print_array(sol_node, 0);

    if(cmp_array(stu_node, sol_node)){
        success = TRUE;
    }

    // Cleanup
    if(stu_node) {
        SparseArray_destroy_sol(stu_node);
    }
    if(sol_node) {
        SparseArray_destroy_sol(sol_node);
    }
    return success;
}
