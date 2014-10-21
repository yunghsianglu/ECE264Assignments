#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_zero(char* s, char* zero) { // bad
	s = zero;
}
void fixed(char** ps, char* zero) { // okay
	*ps = zero;
}

int main(int argc, char *argv[]) {
	// TODO:  fix memory leak
	char *zero = malloc(5*sizeof(char));
	strcpy(zero, "zero");

	char *s = malloc(5*sizeof(char));
	strcpy(s, "");
	make_zero(s, zero);
	printf("after bad one:  %s\n", s);
	
	fixed(&s, zero);
	printf("after fixed:  %s\n", s);

	return 0;
}
