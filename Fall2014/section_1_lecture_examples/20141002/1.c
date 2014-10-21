#include <stdio.h>
// Credit:  Martin Dickey

int g(int a) {
	printf("g(%d)\n", a);
	if (a == 1 || a == 2)
		return a;
	else if (a > 0)
		return g(a - 2);
	else
		return g(a + 2);
}
int f(int val) {
	printf("f(%d)\n", val);
	if (val < 0)
		return g(val + 5);
	else
		return g(val - 5);
}
int main(void) {
	printf("f(-9) == %d\n", f(-9));
	return 0;
}
