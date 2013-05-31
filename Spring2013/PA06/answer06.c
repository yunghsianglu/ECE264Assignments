#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa06.h"
#define MAXIMUM_LENGTH 80
int countStudent(char * filename, int * numberStudent)
/*
 * This function opens the file whose name is given as the first
 * argument. If the file cannot be opened, the function returns
 * EXIT_FAILURE.
 *
 * If the file is opened successfully, the function reads and counts
 * the number of students in the file. 
 *
 * Each student has an ID (integer) and a name (string).  For
 * simplicity, each student's name is only one string, not two for
 * first name and last name.
 *
 * Each student's record uses one line only. One student's record (ID
 * and name) will not span in two or more lines.  
 *
 * Two students' records use two differne lines.  The input file does
 * not contain any single line that has two (or more) students'
 * records.
 *
 * The number of students is stored in numberStudent (notice that this
 * is a pointer).
 *
 * Please be careful not to count empty lines or the end of the file
 * as another student.  Otherwise, your program will print empty lines
 * in the output and this is incorrect.
 *
 * An empty line may include space.  Thus, you cannot assume that an
 * empty line has only the newline character '\n'.
 *
 * The function closes the file and returns EXIT_SUCCESS.
 *
 * Hint: You can use the return value of fscanf to determine whether
 * a line contains an integer.  For example, 
 *
 * int val;
 * char str[MAXIMUM_LENGTH];
 *
 * fscanf(fptr, "%d", & val);
 *
 * return 1 if an integer is successfully read.
 * If a line has no integer, fscanf returns zero.
 *
 * fscanf(fptr, "%d %s", & val, str);
 *
 * return 2 if an integer and a string are successfully read.
 *
 */
{
  return EXIT_SUCCESS;
}
/*
 * ================================================
 */

Student * allocateStudent (int numberStudent)
/*
 * allocate enough memory space to store students' records for
 * numberStudent students.
 *
 * If memory allocation fails, return NULL.
 * If memory allocation succeeds, return the memory address;
 */
{
  return NULL;
}

/*
 * ================================================
 */

int readStudent(char * filename, Student * studentArray, 
		int numberStudent)
/*
 * This function opens the file whose name is given as the first
 * argument. If the file cannot be opened, the function returns
 * EXIT_FAILURE.
 *
 * If the file is opened successfully, the function reads the
 * students' records and stores the data in the second argument.
 *
 * Please be careful not to count empty lines or the end of the file
 * as another student.  Otherwise, your program will print empty lines
 * in the output and this is incorrect.
 *
 * The function closes the file and returns EXIT_SUCCESS.
 */
{
  return EXIT_SUCCESS;
}

/*
 * ================================================
 */

int writeStudent(char * filename, Student * studentArray, 
		 int numberStudent)
/*
 * This function opens the file whose name is given as the first
 * argument. If the file cannot be opened, the function returns
 * EXIT_FAILURE.
 *
 * If the file is opened successfully, the function writes the
 * students' records to the file, one student per line.  The line for
 * the last student should end with a newline character '\n'.
 *
 * This function should not write any empty line.  
 *
 * The function closes the file and returns EXIT_SUCCESS.
 */
{
  return EXIT_SUCCESS;
}


void swapStudent(Student * student1, Student * student2)
/*
 * swap the IDs and the names of the two students 
 *
 * Allocate only necessary memory. You cannot assume that every
 * student's name has MAXIMUM_LENGTH characters.
 *
 * Hint: Please be careful that the two students' names
 * may have different lengths.  
 */
{
  
}

/*
 * ================================================
 */

void freeStudent(Student * studentArray, int numberStudent)
/*
 * This function releases the memory allocated for the Student array.
 * Please remember that everything allocated using malloc must be
 * released.
 *
 * Hint: Each student's name requires malloc earlier so they
 * should be released now.
 *
 */
{
}

/*
 * ====== Do not modify anything below ===================
 */

void sortStudentbyID(Student * studentArray, int numberStudent)
/* This function sorts the students by their IDs. */
{
  /* use selection sort */
  int ind1, ind2;
  for (ind1 = 0; ind1 < numberStudent; ind1 ++)
    {
      int minInd = ind1;
      for (ind2 = ind1 + 1; ind2 < numberStudent; ind2 ++)
	{
	  if (studentArray[minInd].ID > studentArray[ind2].ID)
	    {
	      minInd = ind2;
	    }
	}
      if (minInd != ind1)
	{
	  swapStudent(& (studentArray[minInd]), & (studentArray[ind1]));
	}
    }
}

/*
 * ================================================
 */

void sortStudentbyName(Student * studentArray, int numberStudent)
/* This function sorts the students by their names. */
{
  int ind1, ind2;
  for (ind1 = 0; ind1 < numberStudent; ind1 ++)
    {
      int minInd = ind1;
      for (ind2 = ind1 + 1; ind2 < numberStudent; ind2 ++)
	{
	  if (strcmp(studentArray[minInd].name, 
		     studentArray[ind2].name) > 0)
	    {
	      minInd = ind2;
	    }
	}
      if (minInd != ind1)
	{
	  swapStudent(& (studentArray[minInd]), & (studentArray[ind1]));
	}
    }  
}

