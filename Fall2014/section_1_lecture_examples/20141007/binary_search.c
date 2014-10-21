#include <stdio.h>

int binary_search(int needle, const int haystack[],
									int min_idx, int max_idx) {
									
	int mid_idx = (max_idx + min_idx) / 2;

	if(min_idx == max_idx) // BASE CASE
		return haystack[min_idx] == needle ? min_idx : -1;

	else if(needle <= haystack[mid_idx])
		return binary_search(needle, haystack, min_idx, mid_idx);

	else
		return binary_search(needle, haystack, mid_idx + 1, max_idx);
}

int main() {
	int needle = 2;
	int haystack[] = { 1, 2, 3, 4, 10, 11 };
	int i;
	for(i=0; i<6; i++) {
		int result = binary_search(haystack[i], haystack, 0, 5);
		printf("%d is at %d\n", haystack[i], result);
	}
	return 0;
}
