/*
 * Do not modify this file
 */

#include <stdio.h>
#include <stdlib.h>
#include "pa08.h"

int main ( int argc , char ** argv )
{
  int i; //index

  //check arguments
  if (argc != 3)
    {
      printf("usage: ./pa04 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  //initializing input file
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("File error!\n");
      return EXIT_FAILURE;
    }
  /**********************************
   //initialize array 1
   **********************************/
  int number_of_value_1 = 0;
  fscanf(fptr, "%d", &number_of_value_1);
  printf("\nlength: %d\n", number_of_value_1);

  int* indices_1 = malloc(sizeof(int)* number_of_value_1);
  if (indices_1 == NULL)
    {
      printf("Array_1 indices malloc error!\n");
      return EXIT_FAILURE;
    }

  int* values_1 = malloc(sizeof(int)* number_of_value_1);
  if (values_1 == NULL)
    {
      printf("Array_1 values malloc error!\n");
      return EXIT_FAILURE;
    }

  printf("indices: ");

  for (i = 0; i < number_of_value_1; i++)
    {
      fscanf(fptr, "%d", &indices_1[i]);
      printf("%d ", indices_1[i]);
    }

  printf("\nvalues: ");
  for (i = 0; i < number_of_value_1; i++)
    {
      fscanf(fptr, "%d", &values_1[i]);
      printf("%d ", values_1[i]);
    }
  printf("\n");
  
  SparseNode * array_1 = NULL ;
  array_1 = SparseArray_build(indices_1, values_1, number_of_value_1);


  /************************************
   //initialize array 2
   ************************************/
  int number_of_value_2 = 0;
  fscanf(fptr, "%d", &number_of_value_2);
  printf("\nlength: %d\n", number_of_value_2);

  int* indices_2 = malloc(sizeof(int)* number_of_value_2);
  if (indices_2 == NULL)
    {
      printf("Array_2 indices malloc error!\n");
      return EXIT_FAILURE;
    }

  int* values_2 = malloc(sizeof(int)* number_of_value_2);
  if (values_2 == NULL)
    {
      printf("Array_2 values malloc error!\n");
      return EXIT_FAILURE;
    }

  printf("indices: ");
  for (i = 0; i < number_of_value_2; i++)
    {
      fscanf(fptr, "%d", &indices_2[i]);
      printf("%d ", indices_2[i]);
    }

  printf("\nvalues: ");
  for (i = 0; i < number_of_value_2; i++)
    {
      fscanf(fptr, "%d", &values_2[i]);
      printf("%d ", values_2[i]);
    }
   printf("\n");

  SparseNode * array_2 = NULL ;
  array_2 = SparseArray_build(indices_2, values_2, number_of_value_2);
  
  //finilizing the initialization step
  fclose(fptr);
  free(indices_1);
  free(values_1);
  free(indices_2);
  free(values_2);

  /***********************************
   ***********************************
   * Printing results
   ***********************************
   **********************************/
  SparseNode * onenode = NULL;
  
  fptr = fopen(argv[2], "w");
  if (fptr == NULL){
    printf("output file error\n");
    return EXIT_FAILURE;
  }

  /********************************************************
   * array 1 and array 2
   ********************************************************/

  printf("*******************************\n");
  printf("Array 1\n");
  printf("*******************************\n");
  if (array_1 != NULL)
    {
      for (i = SparseArray_getMin(array_1); 
	   i <= SparseArray_getMax(array_1); i++) 
	{
	  onenode = SparseArray_getNode(array_1,i);
	  if (onenode != NULL)
	    {
	      printf("%5d: %6d\n" , i , onenode->value);
	    }
	}
    }

  printf("\n*******************************\n");
  printf("Array 2\n");
  printf("*******************************\n");
  if (array_2 != NULL){
    for (i = SparseArray_getMin(array_2); 
	 i <= SparseArray_getMax(array_2); i++) 
      {
	onenode = SparseArray_getNode(array_2,i);
	if (onenode != NULL)
	  {
	    printf("%5d: %6d\n" , i , onenode->value);
	  }
      }
  }
  printf("\n*******************************\n");

  
  /********************************************************
   * copy array
   ********************************************************/
  
  SparseNode * copy = SparseArray_copy(array_1);

  printf("Array copy\n");
  printf("*******************************\n");
  if (copy != NULL){
    for (i = SparseArray_getMin(copy);
	 i <= SparseArray_getMax(copy); i++) 
      {
	onenode = SparseArray_getNode(copy,i);
	if (onenode != NULL)
	  {
	    printf("%5d: %6d\n" , i , onenode->value);
	  }
      }
  }
  printf("\n*******************************\n");
  
  /********************************************************
   * doing addition
   ********************************************************/

  SparseNode * array_new = NULL;
  array_new = SparseArray_merge(array_1, array_2);
  printf("Array result\n");
  printf("*******************************\n");
  if (array_new != NULL){
    for (i = SparseArray_getMin(array_new); 
	 i <= SparseArray_getMax(array_new); i++) {
      onenode = SparseArray_getNode(array_new,i);
      if (onenode != NULL)
	{
	  printf("%5d: %6d\n" , i , onenode->value);
	  fprintf(fptr, "%5d: %6d\n" , i , onenode->value);
	}
    }
  }
  printf("\n*******************************\n");

  

  SparseArray_destroy ( array_1 );
  SparseArray_destroy ( array_2 );
  SparseArray_destroy ( array_new );
  SparseArray_destroy ( copy );
  fclose(fptr);
  return EXIT_SUCCESS ;
}
