/*
 * remove non-English words from a dictionary
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE  1
#define FALSE 0
#define LINELENGTH 80
#define fileName "dictionary"
int hasASCIIOnly(char * word)
{
  int ind = strlen(word);
  ind -= 2;
  // word[ind - 1] is '\n'
  while (ind >= 0)
    {
      char c = word[ind]; 
      if (! isalpha(c))
	{
	  // printf("ind = %d, %c %d is not alpha\n", ind, c, c);
	  return FALSE;
	}
      ind --;
    }
  return TRUE;
}
int main(int argc, char ** argv)
{
  char oneLine[LINELENGTH];
  FILE * fptr = fopen(fileName, "r");
  while (! feof(fptr))
    {
      fgets(oneLine, LINELENGTH, fptr);
      // printf("%s", oneLine);
      if (hasASCIIOnly(oneLine) == TRUE)
	{
 	  printf("%s", oneLine);
	}
    }
  return EXIT_SUCCESS;
}
