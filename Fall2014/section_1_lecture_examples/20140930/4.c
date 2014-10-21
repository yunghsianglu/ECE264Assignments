#include <stdio.h>

// What does this do?

int f(int n) {
	int i = 0;
	int this, prev, prev_prev;
	for(i=0; i <= n; i++) {
		if(i==0) {
			this = prev = prev_prev = i;
		}
		else if(i==1) {
			this = prev = i;
		}
		else {
			this = prev + prev_prev;
			prev_prev = prev;
			prev = this;
		}
	}
	return this;
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
