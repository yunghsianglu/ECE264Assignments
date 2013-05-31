/* 
 * Do not modify this file.
 */
#include "pa01.h"
#include <stdio.h>
#include <stdlib.h>
void createArray(int length, int incr, int neg, 
		 char * filename1, char * filename2)
{
  int iter;
  int sum = 0;
  int negcount = 0;
  int val = rand() % 1000 + 500; 
  FILE * fptr1;
  FILE * fptr2;
  fptr1 = fopen(filename1, "w");
  fptr2 = fopen(filename2, "w");
  if (neg == 1)
    {
      val *= -1;
    }
  if (val < 0) { negcount ++; }
  sum += val;
  fprintf(fptr1, "%d\n", val);
  for (iter = 1; iter < length; iter ++)
    {
      if (incr == 1)
	{
	  val += rand() % 100 + 1;
	}
      else
	{
	  val = rand() % 1000 - neg * 500;
	}
      sum += val;
      if (val < 0) { negcount ++; }
      fprintf(fptr1, "%d\n", val);
    }
  fprintf(fptr2, "sum = %d.\n", sum);
  fprintf(fptr2, "The array has %d negative elements.\n", negcount);
  fprintf(fptr2, "The elements are ");
  if (incr == 0)
    {
      fprintf(fptr2, "not ");
    }
  fprintf(fptr2, "increasing.\n");
  fprintf(fptr2, "\n");
  fclose (fptr1);
  fclose (fptr2);
}
int main(int argc, char * * argv)
{
  srand(0); /* set the seed of random numbers */
  int cnt;
  for (cnt = 0; cnt < 20; cnt ++)
    {
      char filename1[80];
      char filename2[80];
      sprintf(filename1, "input%d", cnt);
      sprintf(filename2, "expected%d", cnt);
      createArray(rand() % 100 + 10, cnt % 2, 
		  (cnt + rand()) % 2, filename1, filename2);
    }
  return EXIT_SUCCESS;
}
