#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXVALUE 100000
int main(int argc, char * * argv)
{
  if (argc < 2)
    {
      printf("need a number\n");
      return EXIT_FAILURE;
    }
  int num = (int) strtol(argv[1], NULL, 10);
  if (num <= 0)
    {
      printf("need a positive number\n");
      return EXIT_FAILURE;
    }
  srand(time(NULL)); 
  while (num > 0)
    {
      printf("%d\n", rand() % MAXVALUE);
      num --;
    }
  return EXIT_SUCCESS;
} 
