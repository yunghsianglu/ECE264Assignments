#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
 * In this program, you must NOT use while, for, goto.  If you need to
 * traverse the tree, you must use recursion.
 *
 * You cannot use global or static variables.  You will lose 1 point
 * (25% of the full score) for each global or static variable.
 *
 * You cannot use "mysterious" constants in the program. If you need
 * a constant, you have to define a symbol at the top of this file.
 *
 * You will probably write many "helper" functions in order to
 * simplify the code in readTree and writeTree.
 */ 

Tree * Tree_insert(Tree * root, int val)
/*
 * Hint: read 10.2.2 of the course handout.
 */
{
  return root; 
}

Tree * Tree_delete(Tree * root, int val)
/*
 * Hint: Check the last question in the final exam of Fall
 * 2012. Blackboard - Past Exams - FinalFall2012.pdf.
 * 
 * When deleting a node, we have to consider different scenarios:
 *
 * 1. If this node has no child, release the memory occupied by this
 * node.  
 *
 * 2. If this node has only one child, make this node's parent * point
 * to this node's child and release the memory occupied by this * node.
 *
 * 3. If this node has two children, find this node's successor. The
 * successor is the node that appears immediately after this node in
 * in-order traversal. The successor must be on the right side of this
 * node.  Exchange the values of this node and the successor. Delete
 * the successor.
 *
 */
{
  return root;  
}

Tree * readTree(char * infile)
/*
 * The function opens a file whose name is given by the argument.
 * If fopen fails, this function returns NULL.
 *
 * The input file's format:
 * Each line contains a command an an integer.
 * c n
 * c is a command, either i (insert) or r (remove)
 * n is an integer
 *
 * If the input file contains an empty line (i.e., does not have a
 * command and an integer), the tree is not changed.
 *
 * You do not need to worry about the possibility of an invalid
 * command.  For example,
 *
 * m 34 
 *
 * will not occur in the input file.
 *
 * The function inserts or deletes the numbers based on the commands
 * in the input file.  The function returns the binary search tree
 * built based on these commands.
 *
 * Remember to close the file.
 *
 * Hint: The file may be empty. In this case, the function should
 * return NULL. It is possible that the first command is r.  Your
 * program must not crash when deleting a number from an empty tree.
 * 
 */
{
  return NULL;
}

int preOrder(char * outfile, Tree * root)
{
  return EXIT_SUCCESS;
}

int inOrder(char * outfile, Tree * root)
{
  return EXIT_SUCCESS;
}

int postOrder(char * outfile, Tree * root)
{
  return EXIT_SUCCESS;
}

int writeTree(char * outfile, Tree * root)
/*
 * If the tree is empty, the function creates an empty file
 * and returns EXIT_SUCCESS.
 *
 * The function opens a file whose name is given by the argument.
 *
 * If fopen fails, this function returns EXIT_FAILURE;
 *
 * The function writes the root in three traverse orders:
 * pre-order, in-order, and post-order.  
 *
 * The function closes the file and returns EXIT_SUCCESS.
 *
 * Hint: You may open the output file multiple times.  The first fopen
 * needs to use "w" and the following fopen should use "a" so that the
 * previously written content is not erased.
 *
 */
{
  return EXIT_SUCCESS;
}

