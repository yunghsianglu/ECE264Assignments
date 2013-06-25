/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * For this assignment, you must use qsort and give appropriate
 * comparison functions.
 *
 * You can assume that the input files have no empty lines and the
 * last line ends with '\n'.  You can count the number of lines by
 * counting the occurrences of '\n'.
 *
 * Hint: 
 * You can write additonal functions.
 *
 */

#include "pa02.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define INT     0
#define STRING  1
#define FAILURE 0
#define SUCCESS 1

struct Buffer
{
    char* data;
    int len;
};

struct StringArray
{
    char** strs;
    int len;
};

struct Buffer readFile(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    struct Buffer buffer;
    buffer.data = (char*) malloc(size + 1);
    buffer.len = size + 1;
    buffer.data[size] = '\0'; // so we always have null terminated string

    size_t n_read = fread(buffer.data, 1, size, fp);
    assert(n_read == size);
    
    fclose(fp);

    return buffer;
}

struct StringArray bufferToStringList(struct Buffer buffer)
{
    int i;
    int n_lines = 1; // we always have at least one string
    for(i = 0; i < buffer.len; ++i) {
	if(buffer.data[i] == '\n') {
	    buffer.data[i] = '\0'; // now we have strings =0
	    n_lines++;
	}
    }

    // Create the output array
    struct StringArray strarr;
    
    strarr.strs = (char**) malloc(n_lines * sizeof(char*));
    strarr.len = n_lines;

    // And populate it... skipping empty lines
    int insert_idx = 0;
    strarr.strs[insert_idx++] = &buffer.data[0];
    for(i = 0; i < buffer.len - 1; ++i) 
	if(buffer.data[i] == '\0' && strlen(&buffer.data[i+1]) != 0)
	    strarr.strs[insert_idx++] = &buffer.data[i+1];
    
    assert(insert_idx <= strarr.len);
    strarr.len = insert_idx;

    return strarr;
}


/*
 * =================================================================
 * read the integers from the file whose name is inName
 * sort the integers
 * stored the sorted integers in the file whose name is outName
 */

int compar_int(const void* a, const void* b)
{
    return *((int*) a) < *((int*) b) ? -1 : 1;
}

void sortInt(char * inName, char * outName)
{
    struct Buffer buffer = readFile(inName);
    struct StringArray strarr = bufferToStringList(buffer);
    
    // Okay, let's convert the strings to an array of integers
    int* ints = (int*) malloc(strarr.len * sizeof(int));
    int i;
    int n_ints = 0;
    for(i = 0; i < strarr.len; ++i) 
	ints[n_ints++] = atol(strarr.strs[i]);

    // Lets sort by integer
    qsort(ints, n_ints, sizeof(int), compar_int);
    
    // Output the results to outName
    FILE* fp = fopen(outName, "w");
    assert(fp != NULL);
    for(i = 0; i < n_ints; ++i)
	fprintf(fp, "%d\n", ints[i]);

    free(ints);
    free(buffer.data);
}

/*
 * =================================================================
 * read the strings from the file whose name is inName
 * sort the strings
 * stored the sorted strings in the file whose name is outName
 *
 * The strings are sorted by ASCII order (using strcmp). Thus, 'B' will
 * appear before 'a'.
 */

int compar_str(const void* a, const void* b)
{
    return strcmp(*((char**) a), *((char**) b));
}

void sortString(char * inName, char * outName)
{
    struct Buffer buffer = readFile(inName);
    struct StringArray strarr = bufferToStringList(buffer);

    int i;

    // Lets sort by integer
    qsort(strarr.strs, strarr.len, sizeof(char*), compar_str);
    
    // Output the results to outName
    FILE* fp = fopen(outName, "w");
    assert(fp != NULL);
    for(i = 0; i < strarr.len; ++i)
	fprintf(fp, "%s\n", strarr.strs[i]);
    fclose(fp);

    free(buffer.data);
}
