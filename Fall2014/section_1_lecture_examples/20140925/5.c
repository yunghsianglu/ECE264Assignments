#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	FILE* fp = fopen("5.txt", "r");
	if(fp == NULL) {
		printf("ERROR\n");
		return 1;
	}
	
	int limit = 80;
	char* s = malloc(limit *
		sizeof(char));

	while(!feof(fp)) {
		fgets(s, limit, fp);

		if(!feof(fp)) {
			printf("%s\n", s);
		}
	}

	fclose(fp);
	return 0;
}
