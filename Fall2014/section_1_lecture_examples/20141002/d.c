#include <stdio.h>

int f(int n, int* pnum_calls) {
	(*pnum_calls)++;
	if(n==0) // (bad style to omit braces)
		return 0;  // BASE CASE
	if(n==1) 
		return 1;  // BASE CASE
	else 
		return f(n-2, pnum_calls) + f(n-1, pnum_calls);
}
int main(int argc, char *argv[]) {
	int i;
	for(i=0; i<=8; i++) {
		int num_calls = 0;
		int result = f(i, &num_calls);
		printf("f(%d) == %d : called f %d times\n",
			i, result, num_calls);
	}
	return 0;
}
