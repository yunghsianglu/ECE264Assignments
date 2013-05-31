/* 
 * Do not modify this file.
 */
#ifndef _TREE_H_
#define _TREE_H_
typedef struct treenode
{
  int value;
  struct treenode * left;
  struct treenode * right;
} Tree;

Tree * readTree(char * infile);
int writeTree(char * outfile, Tree * root);
void destroyTree(Tree * root);
#endif
