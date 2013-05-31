/*
 * Do not modify this file.
 * If you modify this file, your program will fail in grading.
 */
#include <stdio.h>
#include <stdlib.h>
#include "pa06.h"
int main(int argc, char ** argv)
{
  if (argc < 4)
    {
      printf("need four file names: input, output1, and output2");
      return EXIT_FAILURE;
    }
  int numberStudent; /* not initialized */
  if (countStudent(argv[1], & numberStudent) == EXIT_FAILURE)
    {
      printf("countStudent fail\n");
      return EXIT_FAILURE;
    }
  Student * studentArray; /* not initialized */
  studentArray = allocateStudent(numberStudent);
  if (studentArray == NULL)
    {
      printf("allocateStudent fail\n");
      return EXIT_FAILURE;
    }
  if (readStudent(argv[1], studentArray, numberStudent) == EXIT_FAILURE)
    {
      printf("readStudent fail\n");
      return EXIT_FAILURE;
    }
  sortStudentbyID(studentArray, numberStudent);
  if (writeStudent(argv[2], studentArray, numberStudent) == EXIT_FAILURE)
    {
      printf("writeStudent fail\n");
      return EXIT_FAILURE;
    }
  sortStudentbyName(studentArray, numberStudent);
  if (writeStudent(argv[3], studentArray, numberStudent) == EXIT_FAILURE)
    {
      printf("writeStudent fail\n");
      return EXIT_FAILURE;
    }
  freeStudent(studentArray, numberStudent);
  return EXIT_SUCCESS;
}
