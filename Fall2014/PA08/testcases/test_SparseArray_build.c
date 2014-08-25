#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int tests_SparseArray_build(int test_number) {
    int testind0[] = {4,1,0,40000,6,30,2,5,4};
    int testval0[] = {30,22,100,3,5,-7,-30,0,20};

    int testind1[] = {50,25,75,12,30,60,80};
    int testval1[] = {4,7,-3,9,80,-7,-30};

    int testind2[] = {30,40,50,60,70,80,90,28,25,22,20,15,0};
    int testval2[] = {30,2,3,7,30,80,-70,-300,10,200,44,22,65};

    int testind3[] = {20,30,25,8,19,18,17,15,16};
    int testval3[] = {59,3,100,-3,0,2,7,-3,4};

    int testind4[] = {1,10,25,8,4,7,11};
    int testval4[] = {5,3,3,4,-30,20,-4};

    int testind5[] = {100,36,0,12,9,120};
    int testval5[] = {50,33,3,100,-6,4};

    int testind6[] = {1,3,0,8};
    int testval6[] = {5,3,6,4};

    int testind7[] = {};
    int testval7[] = {};

    int * arrind[] = { 
        testind0, testind1, testind2, testind3, 
        testind4, testind5, testind6, testind7, 
    };
    int * arrval[] = {
        testval0, testval1, testval2, testval3,
        testval4, testval5, testval6, testval7,
    };

    int arrLen = sizeof(arrind) / sizeof(int *);
    int arrSizeOf[] = {
        sizeof(testind0), sizeof(testind1), sizeof(testind2), sizeof(testind3),
        sizeof(testind4), sizeof(testind5), sizeof(testind6), sizeof(testind7)
    };

    // If test_number is out of range, then...
    if(test_number < 0 || test_number >= arrLen) {
        //return how many distinct test-cases we have.
        return arrLen; 
    }

    int testLen = arrSizeOf[test_number] / sizeof(int);

    // Assume failure unless otherwise noted
    int success = FALSE;
    
    printf("Testing: SparseNode_build(testind%d, testval%d, len=%d)\n", 
	   test_number, test_number, testLen);
    SparseNode * stu_node = NULL;
    SparseNode * sol_node = NULL;
    stu_node = SparseArray_build(arrind[test_number], arrval[test_number], testLen);
    sol_node = SparseArray_build_sol(arrind[test_number], arrval[test_number], testLen);

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
