#include <stdio.h>

int f(int n) {
	if(n==0) {
		return 0;  // BASE CASE
		// Fib(0) is 0
	}
	if(n==1) {
		return 1;  // BASE CASE
		// Fib(1) is 1
	}
	else {
		return f(n-2) + f(n-1); // RECURSIVE CALLS
		// Fib(n) is Fib(n-2) + Fib(n-1)
	}
}
int main(int argc, char *argv[]) {
	printf("f(0) == %d\n", f(0));
	printf("f(1) == %d\n", f(1));
	printf("f(2) == %d\n", f(2));
	printf("f(3) == %d\n", f(3));
	printf("f(4) == %d\n", f(4));
	printf("f(5) == %d\n", f(5));
	printf("f(6) == %d\n", f(6));
	printf("f(7) == %d\n", f(7));
	printf("f(8) == %d\n", f(8));
	return 0;
}
