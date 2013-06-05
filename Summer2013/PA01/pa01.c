/* 
 * Do not modify this file.
 */
#include "pa01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  int val;
  for (val = MINLENGTH; val <= MAXLENGTH; val ++)
    {
      partitionAll(val);
      partitionIncreasing(val);
      partitionUnique(val);
      char * charset = malloc(sizeof(char) * val);
      int ind;
      for (ind = 0; ind < val; ind ++)
	{
	  charset[ind] = 'A' + ind;
	}
      permute(charset, val);
      free (charset);
    }
  return EXIT_SUCCESS;
}
