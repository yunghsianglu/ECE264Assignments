/*
 * Please fill the functions in this file.
 */
#include "pa01.h"

/*
 * C does not initialize variables.
 *
 * int sum; 
 *
 * is different from
 *
 * int sum = 0;
 *
 * The value of sum is undefined (garbage) in the first case.
 *
 */

/* 
   array is an array of integers
   length is the length of the array (i.e. the number of elements)
  
   If an array has length elements.  The valid indexes are between 0
   and length - 1, not between 1 and length.  array[length] will
   access an invalid memory location and possibly terminate the
   program abnormally.

   This function returns the sum of the elements.
   For example, if
   array[0] is 3
   array[1] is 11
   array[2] is 9
   and length is 3
   This function should return 3 + 11 + 9 = 23.

   If the array has no element (length is 0), the function returns 0.

*/
int addElement(int * array, int length)
{
  return 0;
}
/*
 * =================================================================
 */
/* 
   array is an array of integers
   length is the length of the array (i.e. the number of elements)
  
   If an array has length elements.  The valid indexes are between 0
   and length - 1, not between 1 and length.  array[length] will
   access an invalid memory location and possibly terminate the
   program abnormally.

   This function returns the number of negative elements in the array
   For example, if
   array[0] is -3
   array[1] is 11
   array[2] is -9
   array[3] is 0
   and length is 4
   This function should return 2.
   0 is not considered as a negative number.

*/
int countNegative(int * array, int length)
{
  return 0;
}
/*
 * =================================================================
 */
/* 
   array is an array of integers
   length is the length of the array (i.e. the number of elements)
  
   If an array has length elements.  The valid indexes are between 0
   and length - 1, not between 1 and length.  array[length] will
   access an invalid memory location and possibly terminate the
   program abnormally.

   This function returns 1 if the elements are increasing
   (i.e. array[i] < array[j] for all 0 <= i < j < length).  If the
   elements are not increasing, this function returns 0.

   For example, if
   array[0] is 3
   array[1] is 9
   array[2] is 11
   and length is 3
   This function should return 1.
   
   If 
   array[0] is 3
   array[1] is 11
   array[2] is 9
   and length is 3
   This function should return 0.

   If 
   array[0] is 3
   array[1] is 3
   array[2] is 9
   and length is 3
   This function should return 0.

   If the array has only one element (i.e. length is 1), the function
   returns 1.  If the array has no element (length is 0), the function
   also returns 1.

*/
int isIncreasing(int * array, int length)
{
  return 0;
}
