/* 
 * Do not modify this file 
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
int main(int argc, char ** argv)
{
  if (argc < 4)
    {
      printf("need four file names: input, output1, and output2");
      return EXIT_FAILURE;
    }
  Student * stu = readStudent(argv[1]);
  if (stu == NULL)
    {
      printf("readStudent fail\n");
      return EXIT_FAILURE;
    }
  stu = sortStudentbyID(stu);
  if (writeStudent(argv[2], stu) == EXIT_FAILURE)
    {
      printf("writeStudent fail\n");
      return EXIT_FAILURE;
    }
  stu = sortStudentbyName(stu);
  if (writeStudent(argv[3], stu) == EXIT_FAILURE)
    {
      printf("writeStudent fail\n");
      return EXIT_FAILURE;
    }
  freeStudent(stu);
  return EXIT_SUCCESS;
}
