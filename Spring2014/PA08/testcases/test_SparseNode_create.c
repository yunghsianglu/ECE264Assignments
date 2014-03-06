#include "answer08.h"

#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int tests_SparseNode_create(int test_number) {
    const int indices[] = {4,1,0,40000};
    const int values[] = {30,22,100,3};

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

    printf("Testing: SparseNode_create(%d, %d)\n", ind, val);
    SparseNode * snode = SparseNode_create(ind, val);
    if(snode == NULL) {
        printf("Error: NULL result detected.\n");
    }
    else if(snode->left != NULL) {
        printf("Error: snode->left must be NULL.\n");
    }
    else if(snode->right != NULL) {
        printf("Error: snode->right must be NULL.\n");
    }
    else if(snode->index != ind) {
        printf("Error: snode->index != %d.\n", ind);
    }
    else if(snode->value != val) {
        printf("Error: snode->value != %d.\n", val);
    }
    else {
        success = TRUE;
    }

    // Cleanup
    if(snode) {
        free(snode);
    }

    return success;
}

