#include <stdio.h>

// What does this do?

void f(int n) {

	printf("f(%d);\n", n);

	if(n == 0) {
		return;   // BASE CASE
	}
	else {
		f(n - 1); // RECURSIVE CALL
	}
}

int main(int argc, char *argv[]) {

	f(3);

	return 0;
}

