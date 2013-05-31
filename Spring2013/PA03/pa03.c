/* 
 * Do not modify this file.
 */
#include "pa03.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  char set[] ={'A', 'B', 'C', 'D', 
	       'E', 'F', 'G', 'H'};
  if (argc != 3) 
    {
      printf("usage: pa03 p|s|u <number>\n");
      return EXIT_FAILURE;
    }
  int val = (int) strtol(argv[2], NULL, 10);;
  if ((val < MINLENGTH) || (val > MAXLENGTH))
    {
      printf("usage: pa03 p|s|u <number>, number between %d and %d\n",
	     MINLENGTH, MAXLENGTH);
      return EXIT_FAILURE;
    }
  if (strcmp(argv[1], "p") == 0)
    {
      partition(val);
    }
  if (strcmp(argv[1], "s") == 0)
    {
      subset(set, val);
    }
  if (strcmp(argv[1], "u") == 0)
    {
      permute(set, val);
    }
  return EXIT_SUCCESS;
}
