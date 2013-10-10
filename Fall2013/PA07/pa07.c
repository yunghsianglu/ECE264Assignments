/* 
 * Do not modify this file.
 */

#include "pa07.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int readSparseArrayFile(const char* filename, Node * * sparse_array)
{
    // initialize input file
    *sparse_array = NULL;
    FILE * fptr = NULL;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
	{
	    fprintf(stderr, "Error opening file: '%s', aborting.\n", filename);
	    return FALSE;
	}

    // initializing array
    int hasError = FALSE;
    int sparse_array_size = 0;
    int i;
    int lineno = 0;
    fscanf(fptr, "%d", &sparse_array_size);
    lineno++;

    int * array_index = malloc(sizeof(int) * sparse_array_size);
    int * array_value = malloc(sizeof(int) * sparse_array_size);
    if (sparse_array_size > 0 && (!array_index || !array_value))
	{
	    fprintf(stderr, "Failed to allocate memory (!), aborting.\n");
	    hasError = TRUE;
	}

    for(i = 0; i < sparse_array_size && !hasError; i++)
	{
	    if(fscanf(fptr, "%d", &array_index[i]) != 1)
		{
		    fprintf(stderr, "Input file error at line #%d\n", lineno);
		    hasError = TRUE;
		}
	    lineno++;
	}

    for(i = 0; i < sparse_array_size &&  !hasError; i++)
	{

	    if(fscanf(fptr, "%d", &array_value[i]) != 1)
		{
		    fprintf(stderr, "Input file error at line #%d\n", lineno);
		    hasError = TRUE;
		}
	    lineno++;
	}
    printf("\n");

    if(!hasError) 
	{
	    *sparse_array = List_build(array_value, array_index, sparse_array_size);
	}

    fclose(fptr);
    free(array_index);
    free(array_value);

    if(hasError)
	{
	    fprintf(stderr, "Aborting due to previous errors, goodbye.\n");
	    return FALSE;
	}
    
    return TRUE;
}

int main(int argc, char ** argv)
{
    if (argc != 3) 
	{
	    printf("Usage: ./pa05 <input file 1> <input file 2>\n");
	    return EXIT_FAILURE;
	}

    // Input file processed, ready to build the sparse-array
    Node * array1 = NULL, * array2 = NULL;
    int okay = TRUE;
    okay = okay && readSparseArrayFile(argv[1], &array1);
    okay = okay && readSparseArrayFile(argv[2], &array2);

    if(okay)
	{
	    FILE * out = stdout; // This is where we output results
    
	    printf("*******************************\n");
	    printf("Array 1:\n");
	    printf("*******************************\n");

	    List_print(out, array1);  

	    printf("\n*******************************\n");
	    printf("Array 2:\n");
	    printf("*******************************\n");

	    List_print(out, array2); 

	    printf("\n*******************************\n");
	    printf("Copy of Array 1:\n");
	    printf("*******************************\n");

	    Node * clone_array = List_copy(array1);
	    List_print(out, clone_array);

	    printf("\n*******************************\n");
	    printf("Merged array:\n");
	    printf("*******************************\n");

	    Node * array_new = List_merge(array1, array2);
	    List_print(out, array_new);

	    List_destroy(array_new);
	    List_destroy(clone_array);
	}

    List_destroy(array1);
    List_destroy(array2);

    return EXIT_SUCCESS;
}




