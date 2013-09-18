/*
 * Do not modify this file.
 * If you modify this file, your program will fail in grading.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"
int main(int argc, char ** argv)
{
  if (argc < 4)
    {
      printf("need four file names: type, input, output");
      return EXIT_FAILURE;
    }
  if (strcmp(argv[1], "i") == 0) /* sort integers */
    {
      int numInteger = 0;
      int * arrInteger = NULL;
      arrInteger = readInteger(argv[2], & numInteger);
      if (numInteger == 0)
	{
	  return EXIT_FAILURE;
	}
      printInteger(arrInteger, numInteger);
      sortInteger(arrInteger, numInteger);
      printInteger(arrInteger, numInteger);
      saveInteger(argv[3], arrInteger, numInteger);
      freeInteger(arrInteger, numInteger);
      return EXIT_SUCCESS;
    }
  if (strcmp(argv[1], "s") == 0) /* sort strings */
    {
      int numString = 0;
      char * * arrString = NULL;
      arrString = readString(argv[2], & numString);
      if (numString == 0)
	{
	  return EXIT_FAILURE;
	}
      printString(arrString, numString);
      sortString(arrString, numString);
      printString(arrString, numString);
      saveString(argv[3], arrString, numString);
      freeString(arrString, numString);
      return EXIT_SUCCESS;
    }
  /* unknown type */
  return EXIT_FAILURE;
}
