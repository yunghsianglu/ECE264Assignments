/* 
 * Do not modify this file.
 */
#ifndef _STUDENT_H_
#define _STUDENT_H_
typedef struct listnode
{
  int ID;
  char * name;   
  struct listnode * next;
} Student;

Student * readStudent(char * infile);
int writeStudent(char * outfile, Student * stu);
Student * sortStudentbyID(Student * stu);
Student * sortStudentbyName(Student * stu);
void freeStudent(Student * stu);
#endif
