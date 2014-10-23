#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void insert(int n, int pos, int** p_a, int* p_len) {
	int* new_a = malloc((*(p_len)+1) * sizeof(int));
	int i;
	for(i=0; i<*p_len; i++) {
		if(i < pos)
			new_a[i] = (*p_a)[i];
		else
			new_a[i+1] = (*p_a)[i];
	}
	new_a[pos] = n;
	*p_len = *p_len + 1;
	*p_a = new_a;
}

int main(int argc, char *argv[]) {
	int len = 3;
	int* a = malloc(len * sizeof(int));
	int i;
	for(i=0; i<len; i++)
		a[i] = 11 * i;

	insert(5000, 0, &a, &len);
	return 0;
}
