#ifndef TREE_PRINT_H
#define TREE_PRINT_H

#include "answer11.h"

/**
 * Prints a tree to 'fp'. 
 * Will 'printPlain' if the tree is more than 6 nodes deep. Otherwise will
 * 'printPretty'.
 */
void HuffNode_print(FILE * fp, HuffNode * tree);

/**
 * Neatly print a tree to 'fp'. 
 */
void HuffNode_printPlain(FILE * fp, HuffNode * tree);

/**
 * Print a tree to 'fp' in a visually appealing way. Deep trees will quickly
 * generate very wide output.
 */
void HuffNode_printPretty(FILE * fp, HuffNode * tree);

/**
 * Prints a stack of Huffman trees.
 * You may want to use this to help debug your program.
 */
void Stack_print(FILE * fp, Stack * stack);

/**
 * Given a Huffman Coding Tree, and a correctly positioned 'fp', decode the data
 * 
 * Parameters:
 * 'fp'    File to read from. The file must be positioned just past the tree
 * 'tree'  The Huffman coding tree
 * 'len'   A pointer to size_t, which is intialized to the length of the result
 *
 * Returns:
 * An array, which is the decoded contents of the file. Caller must free this
 * array.
 */
unsigned char * Huffman_applyTree(FILE * fp, HuffNode * tree, size_t * len);

#endif
