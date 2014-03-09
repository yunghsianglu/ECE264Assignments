#ifndef ANSWER09_H
#define ANSWER09_H

#include <stdio.h>

// -------------------------------------------------------------------- HuffNode

/**
 * A Huffman coding tree. We must implement two small functions... 
 *
 * (1) HuffNode_create(value);         // create a new HuffNode
 * (2) HuffNode_destory(tree);         // free all memory safely
 */
typedef struct leaf {
    int value;
    struct leaf * left;  // left sub-tree
    struct leaf * right; // right sub-tree
} HuffNode;

/**
 * Create a new, properly intialized HuffNode
 */
HuffNode * HuffNode_create(int value);

/**
 * Destroy a tree, including all sub-children. Must handle NULL values safely.
 */
void HuffNode_destroy(HuffNode * tree);

// ----------------------------------------------------------------------- Stack

/**
 * We need a "Stack" to build the tree structure that is used to decode
 * a Huffman encoding. Stacks are very simple to implement with linked lists.
 * We must implement the following functions (given below). Each of these 
 * functions should only be a few lines of code.
 *
 * (1) Stack_create();              // Allocate a brand new stack.
 * (2) Stack_destroy(stack);        // Clean up memory for the stack.
 * (3) TreeStack_isEmpty(stack);    // TRUE iff (if and only if) the stack is empty.
 * (4) TreeStack_pushFront(stack, tree); // push a tree onto the stack.
 * (6) TreeStack_popFront(stack);  // remove a tree from the stack and return it.
 *
 * Altogether, these six functions should be around 40 lines of code.
 */
typedef struct StackNode_st
{
    HuffNode * tree;
    struct StackNode_st * next;
} StackNode;

typedef struct Stack_st
{
    StackNode * head; // head node of a linked-list
} Stack;

/**
 * Returns a pointer to a new empty stack struct
 */
Stack * Stack_create();

/**
 * Frees all memory associated with the stack. 
 * Don't forget that you must free the entire contained linked-list.
 * Also, you must safely do nothing if stack == NULL. 
 */
void Stack_destroy(Stack * stack);

/**
 * Returns TRUE (something other than zero) if the stack is empty.
 */
int Stack_isEmpty(Stack * stack);

/**
 * Pop the front 'value' from the stack.
 *
 * More precisely, this function must do two things:
 * (1) Return the value of the head node of the stack's list
 * (2) Remove the head node of the stack's list, freeing it.
 */
HuffNode * Stack_popFront(Stack * stack);

/**
 * Push a 'value' onto the front of the stack.
 *
 * More precisely, this function must:
 * (1) Create a new StackNode with 'tree' for its tree.
 * (2) Push that new StackNode onto the front of the stack's list.
 */
void Stack_pushFront(Stack * stack, HuffNode * tree);

// -------------------------------------------------------- Pop Pop combine Push

/**
 * This function helps simplify building a Huffman Coding Tree from the header
 * information. It takes a stack as input. As a precondition, you can assume 
 * that the stack has at least two nodes. This function pops two nodes, combines
 * them into a single node, and pushes the new node back onto the stack. See
 * the Huffman_Coding.pdf to understand conceptually how this should be done.
 */
void Stack_popPopCombinePush(Stack * stack);

// ---------------------------------------------------- Reading HuffTree headers

/**
 * Read a Huffman Coding Tree (in text format) from 'fp'.
 */
HuffNode * HuffTree_readTextHeader(FILE * fp);

/**
 * Read a Huffman Coding Tree (in binary format) from 'fp'.
 * You will need to (conceptually) read a file a bit at a time. See the README
 * for hints on how to do this.
 */
HuffNode * HuffTree_readBinaryHeader(FILE * fp);

#endif

