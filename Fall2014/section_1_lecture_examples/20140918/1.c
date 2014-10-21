#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_all_zero(char** s, char* zero) {
	s[0] = zero;
	s[1] = zero;
	s[2] = zero;
}

int main(int argc, char *argv[]) {
	char* strs[] = { "zero", "one", "two" };
	printf("%p\n", strs[0]);
	printf("%c\n", strs[2][1]);

	char** m;
	// Array of pointers
	m = malloc(3 * sizeof(char*));

	// Array of characters (strings) for each pointer
	m[0] = malloc(5 * sizeof(char));
	m[1] = malloc(5 * sizeof(char));
	m[2] = malloc(5 * sizeof(char));

	strcpy(m[0], "zero");
	strcpy(m[1], "one");
	strcpy(m[2], "two");

	make_all_zero(m, "zero");
	printf("%s, %s, %s\n", m[0], m[1], m[2]);

	free(m[0]);
	free(m[1]);
	free(m[2]);
	free(m);
	
	return 0;
}
