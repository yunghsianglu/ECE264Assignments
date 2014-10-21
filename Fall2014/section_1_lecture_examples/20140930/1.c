#include <stdio.h>

// What does this do?

void f(int n) {
	printf("f(%d)\n", n);

	f(n-1); // RECURSIVE CALL
}

int main(int argc, char *argv[]) {

	f(5);

	return 0;
}
