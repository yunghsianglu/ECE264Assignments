#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_merge(int test_number) {
    int n_tests = 8;

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= n_tests) {
        //return how many distinct test-cases we have.
        return n_tests; 
    }
    
    int arr1 = 0;
    int arr2 = 0;
    switch(test_number) {
        case 0:
            arr1 = 0;
            arr2 = 4;
            break;
        case 1:
            arr1 = 1;
            arr2 = 5;
            break;
        case 2:
            arr1 = 2;
            arr2 = 6;
            break;
        case 3:
            arr1 = 3;
            arr2 = 7;
            break;
        case 4:
            arr1 = 0;
            arr2 = 1;
            break;
        case 5:
            arr1 = 2;
            arr2 = 3;
            break;
        case 6:
            arr1 = 4;
            arr2 = 5;
            break;
        case 7:
            arr1 = 6;
            arr2 = 7;
            break;
    };

    // Assume failure unless otherwise noted
    int success = FALSE;

    printf("Testing: SparseNode_merge(a%d)\n", test_number);
    SparseNode * array_1 = NULL;
    SparseNode * array_2 = NULL;
    SparseNode * sol_merge = NULL;
    SparseNode * stu_merge = NULL;

    //build the arrays to be merged
    array_1 = make_array(arr1);
    array_2 = make_array(arr2);

    printf("Built array_1 a%d:\n", arr1);
    print_array(array_1, 0);

    printf("Built array_2 a%d:\n", arr2);
    print_array(array_2, 0);

    printf("Merge Node:\n");
    sol_merge = SparseArray_merge_sol(array_1, array_2);
    stu_merge = SparseArray_merge(array_1, array_2);
    printf("Student result after merge:\n");
    print_array(stu_merge, 0);
    printf("Solution result after merge:\n");
    print_array(sol_merge, 0);

    printf("Checking if result tree is the same...\n");
    if(cmp_array(stu_merge, sol_merge)) {
        success = TRUE;
    }

    // Cleanup
    if(array_1) {
        SparseArray_destroy_sol(array_1);
    }
    if(array_2) {
        SparseArray_destroy_sol(array_2);
    }
    if(sol_merge) {
        SparseArray_destroy_sol(sol_merge);
    }
    if(stu_merge) {
        SparseArray_destroy_sol(stu_merge);
    }
    return success;
}
