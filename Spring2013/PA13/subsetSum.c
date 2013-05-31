#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "pa13.h"

#define SUCCESS 0
#define FAILURE -1

/*
* Write a parallel C program that returns the answer for the following problem:
* Given a nonempty set S, with elements {a1, a2, a3, ...}, and a integer N, 
* find the number of nonempty subsets of S, such that the sum of all elements 
* in this subset equals to N.
*
* Arguments:
*	intset - pointer to an array of a integer set
*	length - size (length) of the integer set
*	N - target sum value
*	numThread - number of threads 
* Return value:
*	numOfSolutions - Number of nonempty subsets in which the subsetSum value 
*	matches with N. This variable should be protected as the critical 
*	sections by using mutex objects.
*
* Hint: The total number of possible subsets is (2^(length)-1). You may use
* 	math library function 'pow()' to assign the index for each thread.
* 	pthread.h and math.h are already included in this file.
*/
int subsetSum(int * intset, int length, int N, int numThread)
{ 
  
}
