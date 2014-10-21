#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int gcd(a, b) {
	if(b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
int main(int argc, char *argv[]) {

	printf("gcd(27, 12) == %d\n", gcd(27, 12));

	return 0;
}
