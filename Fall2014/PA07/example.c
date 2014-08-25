
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

/**
 * Merge-sorting arrays is conceptually more complex than merge-sorting
 * linked-lists. The reason is that you cannot merge-sort an array "in-place", 
 * which means that you have to make copies of sub-arrays as you go. This makes
 * the code more complex than working with linked-lists, which require no
 * copying at all.
 */
void merge_sort(char * * strArr, int len, 
		int (*compar)(const char *, const char *))
{
    // Base case: very short arrays are already sorted.
    if(len <= 1)
	return;

    // Recursive case: split, sort and merge.
    // Split
    int leftLen = len / 2;
    int rightLen = len - leftLen;
    char * * strArrLeft = malloc(leftLen * sizeof(const char *));
    char * * strArrRight = malloc(rightLen * sizeof(const char *));
    memcpy(strArrLeft, &strArr[0], leftLen * sizeof(const char *));
    memcpy(strArrRight, &strArr[leftLen], rightLen * sizeof(const char *));

    // Sort
    merge_sort(strArrLeft, leftLen, compar);
    merge_sort(strArrRight, rightLen, compar);

    // Merge
    int writeInd = 0; // write index into strArr
    int leftInd = 0; // read index from strArrLeft
    int rightInd = 0; // read index from strArrRight
    while(leftInd < leftLen && rightInd < rightLen) {
	int cmp = compar(strArrLeft[leftInd], strArrRight[rightInd]);
	if(cmp <= 0) {
	    strArr[writeInd++] = strArrLeft[leftInd++];
	} else {
	    strArr[writeInd++] = strArrRight[rightInd++];
	}
    }
    if(leftInd < leftLen) { // copy remaining elements
	memcpy(&strArr[writeInd], &strArrLeft[leftInd], 
	       (leftLen - leftInd) * sizeof(const char *));
    } else if(rightInd < rightLen) {
	memcpy(&strArr[writeInd], &strArrRight[rightInd], 
	       (rightLen - rightInd) * sizeof(const char *));
    }

    // Cleanup
    free(strArrLeft);
    free(strArrRight);
}


void print_usage(char * argv0)
{
    printf("\n"
	   "   Usage: %s <filename>\n"
	   "\n"
	   "      Reads from file <filename>, or stdin if none given.\n"
	   "      The file is read line-by-line, sorted line-by-line, and\n"
	   "      then printed to stdout.\n"
	   "\n",
	   basename(argv0));
}

/**
 * Example code for:
 * (1) reading a file of strings into an array
 * (2) using merge-sort to sort them
 * (3) printing the sorted lines
 */
int main(int argc, char * * argv)
{
    // The file we read from.
    FILE * fp = NULL;

    // Will read the file line-by-line into this buffer
    size_t buffer_len = 1024;
    char * buffer = malloc(buffer_len * sizeof(char));

    // Parse input arguments
    if(argc != 2) {
	print_usage(argv[0]);
	return EXIT_FAILURE;
    }
    
    if(strcmp(argv[1], "--help") == 0) {
	print_usage(argv[0]);
	return EXIT_SUCCESS;
    } else {
	const char * filename = argv[1];
	fp = fopen(filename, "r");
	if(fp == NULL) {
	    fprintf(stderr, "Failed to open file '%s', aborting\n", filename);
	    return EXIT_FAILURE;
	}
    }

    // How many lines of input are there?
    int n_lines = 0;

    // Read the file line-by-line. Lookup the man-page of getline for details.
    while(getline(&buffer, &buffer_len, fp) != -1)
	n_lines++;

    // Create an array of strings
    char * * strArr = malloc(n_lines * sizeof(char *));

    // Initialize the contents of strArr by re-reading the entire file.
    fseek(fp, 0, SEEK_SET);
    int ind = 0;
    while(getline(&buffer, &buffer_len, fp) != -1)
	strArr[ind++] = strdup(buffer);

    // Sort strArr
    merge_sort(strArr, n_lines, strcmp);

    // Print the result
    for(ind = 0; ind < n_lines; ++ind) {
	const char * s = strArr[ind];
	printf("%s", s);
	int len = strlen(s);
	if(len > 0 && s[len-1] != '\n')
	    printf("\n"); // make sure there's always a new-line character
    }

    // Cleanup resources
    fclose(fp);
    free(buffer);
    for(ind = 0; ind < n_lines; ++ind)
	free(strArr[ind]);
    free(strArr);

    return EXIT_SUCCESS;
}

