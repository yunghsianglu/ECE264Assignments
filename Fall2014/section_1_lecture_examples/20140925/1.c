#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	FILE* fp = fopen("1.txt", "r");
	if(fp == NULL) {
		printf("ERROR\n");
		return 1;
	}

	int i;
	for(i=0; i < 100; i++) {
		char ch = fgetc(fp);
		if(ch == EOF) {
			break;
		}
		printf("%c\n", ch);
	}
	fclose(fp);
	return 0;
}
