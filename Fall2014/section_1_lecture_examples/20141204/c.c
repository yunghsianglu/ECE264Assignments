#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int array[] = {3,2,1,9,2,1,4,5,7,6,2,8,5};
	int n = 7;
	int i,c,d,swap;
	int inner = 0, outer = 0;

	// Print array
	for(i=0; i<n; i++) { printf("%d ", array[i]); }
	printf("\n");

	for (c = 0 ; c < ( n - 1 ); c++) { // outer loop
		outer++;

		// For n == 1, this is touched 0 times.
		// "   n == 2, "    "  "       1 time.
		// "   n == 3, "    "  "       2 time.
		// "   n == 4, "    "  "       3 time.
		// "   n == n, "    "  "       (n - 1) times.

		for (d = 0 ; d < n - c - 1; d++) { // inner loop

			// This is touched (n - c - 1) times per outer loop.
			inner++;

			if (array[d] > array[d+1]) {
				swap       = array[d];
				array[d]   = array[d+1];
				array[d+1] = swap;
			}
		}
	}

	// Print array
	//for(i=0; i<n; i++) { printf("%d ", array[i]); }
	printf("n==%d   outer==%d   inner==%d\n", n, outer, inner);

	return 0;
}

