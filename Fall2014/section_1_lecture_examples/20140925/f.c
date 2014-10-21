#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	FILE* fp = fopen("6.txt", "w");
	if(fp == NULL) {
		printf("ERROR\n");
		return 1;
	}

	// Write a character.
	fputc('X', fp);

	fclose(fp);
	return 0;
}
