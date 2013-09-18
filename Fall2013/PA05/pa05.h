/* 
 * Do not modify this file
 * 
 * If you modify this file. Your program will fail in grading.
 *
 */
#ifndef _PA05_H_
#define _PA05_H_
#define MAXIMUM_LENGTH 80
int * readInteger(char * filename, int * numInteger);
void sortInteger(int * arrInteger, int numInteger);
void printInteger(int * arrInteger, int numInteger);
int saveInteger(char * filename, int * arrInteger, int numInteger);
void freeInteger(int * arrInteger, int numInteger);

char * * readString(char * filename, int * numString);
void sortString(char * * arrString, int numString);
void printString(char * * arrString, int numString);
int saveString(char * filename, char * * arrString, int numString);
void freeString(char * * arrString, int numString);
#endif
