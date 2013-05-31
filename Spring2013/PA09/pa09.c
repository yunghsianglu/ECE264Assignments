/* 
 * You need to modify this file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main(int argc, char ** argv)
{
  /* 
   * This program takes two additional arguments
   * argv[1] is the name of the input file
   * argv[2] is the name of the output file
   */
     
  /* 
   * check whether there are enough arguments. Before using argv[1]
   * and argv[2], the program must check whether argc is large enough.
   * If there are not enough arguments, the program returns
   * EXIT_FAILURE;
   */



  /* do not modify anything below */
  Tree * root = readTree(argv[1]);
  int rval = writeTree(argv[2], root);
  destroyTree(root);
  return rval;
}
