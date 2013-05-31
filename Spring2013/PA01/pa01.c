/* 
 * Do not modify this file.
 */
#include "pa01.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
  if (argc != 2)
    {
      return EXIT_FAILURE;
    }
  FILE * fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      return EXIT_FAILURE;
    }
  int length = 0;
  int value;
  while (fscanf(fptr, "%d", & value) == 1)
    {
      length ++;
    }
  fseek (fptr, 0, SEEK_SET);
  int * arr = malloc(length * sizeof(int));
  length = 0;
  while (fscanf(fptr, "%d", & (arr[length])) == 1)
    {
      // printf("arr[%d] = %d\n", length, arr[length]);
      length ++;
    }
  int sum = addElement(arr, length);
  int neg = countNegative(arr, length);
  int inc = isIncreasing(arr, length);
  printf("sum = %d.\n", sum);
  printf("The array has %d negative elements.\n", neg);
  printf("The elements are ");
  if (inc == 0)
    {
      printf("not ");
    }
  printf("increasing.\n");
  printf("\n");
  free (arr);
  fclose (fptr);
  return EXIT_SUCCESS;
}
