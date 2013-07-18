#ifndef TREE_H
#define TREE_H

typedef struct leaf {
    int value;
    struct leaf *left;
    struct leaf *right;
} HuffNode;

void Huff_postOrderPrint(HuffNode *tree);

#endif /* tree.h */

