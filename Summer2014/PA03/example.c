
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
   // We want some variables to store which "switches" were set
   int showHelp = FALSE;
   int serveIceCream = FALSE;
   int badSwitch = FALSE;

   // Loop through the arguments, looking for our switches...
   int ind = 1; // we always skip 0, which is the program path
   for( ; ind < argc; ++ind) {
      if(strcmp(argv[ind], "--help") == 0) 
         showHelp = TRUE;
      else if(strcmp(argv[ind], "-i") == 0)
         serveIceCream = TRUE;
      else if(strcmp(argv[ind], "--serve-icecream") == 0)
         serveIceCream = TRUE;
      else {
         badSwitch = TRUE; // best not to run if there's an error
         fprintf(stderr, "Unknown switch: '%s'\n", argv[ind]);
      }
   }

   // Usually you want to bail if the switches aren't perfect...
   // because this helps developers make more reliable software.
   if(badSwitch) {
      fprintf(stderr, "Aborting...\n");
      return EXIT_FAILURE;
   }

   // If --help is passed, you usually show help and do nothing else
   if(showHelp) {
      printf("Usage: ./icecream OPTIONS...\n"
             "   -i, --serve-icecream  Not as exciting as it sounds\n"
	     "\n");
      return EXIT_SUCCESS;
   }

   // And here we do something intelligent:
   printf("Do you get icecream? ");
   if(serveIceCream)
      printf("YES!!!\n");
   else
      printf("Sorry, try again next-time.\n");

   return EXIT_SUCCESS;
}


