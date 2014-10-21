#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	FILE* fp = fopen("3.txt", "r");
	if(fp == NULL) {
		printf("ERROR\n");
		return 1;
	}

	int n;
	// char ch = fgetc(fp);
	// printf("%d", ch);
	fscanf(fp, "%d", &n);
	printf("%d", n);
	fclose(fp);
	return 0;
}
