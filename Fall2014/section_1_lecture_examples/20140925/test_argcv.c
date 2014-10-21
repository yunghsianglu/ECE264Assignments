
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
	printf("argc == %d\n\n", argc);
	int i=0;
	for(i=0; i<argc; i++) {
		printf("argv[%d] == %s\n", i, argv[i]);
	}
   return EXIT_SUCCESS;
}


