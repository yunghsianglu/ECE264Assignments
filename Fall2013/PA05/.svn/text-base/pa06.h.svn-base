/* 
 * Do not modify this file
 * 
 * If you modify this file. Your program will fail in grading.
 *
 */
#ifndef _PA06_H_
#define _PA06_H_
typedef struct
{
  int ID;
  char * name; 
  /* If you change this to 
     
     char name[80];

     you will receive zero */
} Student;

int countStudent(char * filename, int * numstu);
Student * allocateStudent (int numberStudent);
int readStudent(char * filename, Student * studentArray, 
		int numberStudent);
int writeStudent(char * filename, Student * studentArray, 
		 int numberStudent);
void sortStudentbyID(Student * studentArray, int numberStudent);
void sortStudentbyName(Student * studentArray, int numberStudent);
void swapStudent(Student * student1, Student * student2);
void freeStudent(Student * studentArray, int numberStudent);
#endif
