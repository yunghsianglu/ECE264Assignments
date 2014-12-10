#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int array[] = {3,2,1,9,2,1,4,5,7,6,2,8,5};
	int n = 6;
	int i,c,d,swap;
	int num_inner_loop = 0;

	// Print array
	printf("n == %d\n", n);
	//for(i=0; i<n; i++) { printf("%d ", array[i]); }
	printf("\n");

	for (c = 0 ; c < ( n - 1 ); c++) {
		for (d = 0 ; d < n - c - 1; d++) {
			num_inner_loop++;
			if (array[d] > array[d+1]) {
				swap       = array[d];
				array[d]   = array[d+1];
				array[d+1] = swap;
			}
		}
	}

	// Print array
	//for(i=0; i<n; i++) { printf("%d ", array[i]); }
	printf("num_inner_loop == %d\n", num_inner_loop);

	return 0;
}

