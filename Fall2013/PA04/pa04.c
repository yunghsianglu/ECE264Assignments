/* 
 * Do not modify this file.
 */
#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{

  printf("input file format:\n<method> <value to partition>\n\n");
  printf("methods:\n1. All\n2. Increasing\n3. Decreasing\n4. Odd\n5. Even\n6. OddAndEven\n7. Prime\n\n");

  if (argc < 2)
    {
      printf("usage: ./pa04 <input file>\n");
      return EXIT_FAILURE;
    }

  FILE* fin = fopen(argv[1], "r");
  if (!fin)
    {
      printf("file error\n");
      return EXIT_FAILURE;
    }

  int val = 1;
  int method = 0;
  fscanf(fin, "%d", &method);
  fscanf(fin, "%d", &val);

  printf("current method: %d\ncurrent value: %d\nStart Partitioning...\n", method, val);

  switch(method)
    {
    case 1: partitionAll(val);
      break;
    case 2: partitionIncreasing(val);
      break;
    case 3: partitionDecreasing(val);
      break;
    case 4: partitionOdd(val);
      break;
    case 5: partitionEven(val);
      break;
    case 6: partitionOddAndEven(val);
      break;
    case 7: partitionPrime(val);
      break;
    }

  fclose(fin);

  return EXIT_SUCCESS;
}
