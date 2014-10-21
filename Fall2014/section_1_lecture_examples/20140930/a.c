#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE* fp = fopen("a.txt", "r");
	char ch;
	int is_feof;
	is_feof = feof(fp);
	ch = fgetc(fp);
	printf("feof(fp)==%d, %c == EOF --> %d\n",
						is_feof, ch, ch==EOF); 

	is_feof = feof(fp);
	ch = fgetc(fp);
	printf("feof(fp)==%d, %c == EOF --> %d\n",
						is_feof, ch, ch==EOF); 

	is_feof = feof(fp);
	ch = fgetc(fp);
	printf("feof(fp)==%d, %c == EOF --> %d\n",
						is_feof, ch, ch==EOF); 
	return 0;
}
