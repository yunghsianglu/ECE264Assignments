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

	while(feof(fp)) {
		printf("%c\n", fgetc(fp));
	}
	return 0;
}
