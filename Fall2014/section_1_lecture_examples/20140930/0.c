#include <stdio.h>

// What does this do?

void f() {
	f();
}

int main(int argc, char *argv[]) {

	f();

	return 0;
}
