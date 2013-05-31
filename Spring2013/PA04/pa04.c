/*
 * Do not modify this file.
 */

#include <string.h>
#include "pa04.h"

int main(int argc, char** argv)
{
  /* 
     argv[1]: function
         "c" count characters
         "s" count strings
         "p" determine whether the input file is a palindromes
     argv[2]: input file name
     argv[3]: output file name
     argv[4]: string to search, needed only if argv[1] is "s"
   */

  if (argc < 4)
    {
      return EXIT_FAILURE;
    }
  if (strcmp(argv[1], "c") == 0)
    {
      return countLetter(argv[2], argv[3]);
    }
  if (strcmp(argv[1], "s") == 0)
    {
      if (argc < 5)
	{
	  return EXIT_FAILURE;
	}
      return countString(argv[2], argv[3], argv[4]);
    }
  if (strcmp(argv[1], "p") == 0)
    {
      return isPalindrome(argv[2], argv[3]);
    }
  /* argv[1] is not one of the three valid command */
  return EXIT_FAILURE;
}


