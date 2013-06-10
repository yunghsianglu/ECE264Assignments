/*
 * randomly select words from a dictionary
 *
 */

#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 80
#define fileName "dictionary"
int readDictionary(char * filename, char * * * dict)
{
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL)
    {
      return 0;
    }
  /* count the lines */
  char oneWord[LINE_LENGTH];
  int wordCount = 0;
  char * * words;
  while (fgets(oneWord, LINE_LENGTH, fptr) != NULL)
    {
      if (strlen(oneWord) > 3)
	{
	  wordCount ++;
	}
    }
  fseek(fptr, 0, SEEK_SET);
  words = malloc(sizeof(char *) * wordCount);
  int counter = 0;
  while (fgets(oneWord, LINE_LENGTH, fptr) != NULL)
    {
      if (strlen(oneWord) > 3)
	{
	  int length = strlen(oneWord) + 1;
	  words[counter] = malloc(sizeof(char) * length);
	  strcpy(words[counter], oneWord);
	  /* make first letter uppercase because sort in Linux is case
	     insensitive */
	  if (islower(oneWord[0]))
	    {
	      words[counter][0] = oneWord[0] - 'a' + 'A';
	    }
	  counter ++;
	}
    }
  fclose (fptr);
  * dict = words;
  return wordCount;
}
int main(int argc, char ** argv)
{
  srand(time(NULL));
  if (argc < 2)
    {
      printf("how many words?\n");
      return EXIT_FAILURE;
    }
  int num = (int) strtol(argv[1], NULL, 10);
  char * * words;
  int numWords;
  numWords = readDictionary(fileName, & words);
  if (numWords == 0)
    {
      printf("cannot read dictionary\n");
      return EXIT_FAILURE;
    }
  int iter;
  for (iter = 0; iter < num; iter ++)
    {
      printf("%s", words[rand() % numWords]);
    }
  return EXIT_SUCCESS;
}
