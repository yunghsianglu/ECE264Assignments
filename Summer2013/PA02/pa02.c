/* 
 * Do not modify this file.
 */
#include "pa02.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  if (argc < 2)
    {
      printf("need the list of files\n");
      return EXIT_FAILURE;
    }
  FILE * fileList = fopen(argv[1], "r");
  char inName[LINELENGTH];
  char outName[LINELENGTH];
  while ((fgets(inName, LINELENGTH, fileList) != NULL) &&
	 (fgets(outName, LINELENGTH, fileList) != NULL))
    {
      // remove the '\n' character
      // the character at [strlen(*) - 1] is '\n'
      // printf("\n\n\nin=%sout=%s\n", inName, outName);
      inName[strlen(inName) - 1] = '\0';
      outName[strlen(outName) - 1] = '\0';
      printf("in=%s, out=%s\n", inName, outName);
      if (strstr(inName, "str") != NULL)
	{
	  sortString(inName, outName);
	}
      else
	{
	  sortInt(inName, outName);
	}
    }
  fclose(fileList);
  return EXIT_SUCCESS;
}

int mainx(int argc, char** argv)
{
    sortString("inputs/strinput01", "stroutput01");
    sortInt("inputs/intinput01", "intoutput01");
    return EXIT_SUCCESS;
}



