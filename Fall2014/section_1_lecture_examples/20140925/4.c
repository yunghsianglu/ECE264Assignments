#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	FILE* fp = fopen("4.txt", "r");
	if(fp == NULL) {
		printf("ERROR\n");
		return 1;
	}

	printf("%c", fgetc(fp));
	printf("%c", fgetc(fp));
	printf("%c", fgetc(fp));
	int res=fseek(fp, -1, SEEK_SET);
	printf("\n%d\n", res);
	perror(fp);
	//printf("%c", fgetc(fp));
	fclose(fp);
	return 0;
}
