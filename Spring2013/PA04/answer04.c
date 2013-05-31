#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "pa04.h"

#define NUM_CHAR 26 
/* 26 English letters */ 

#define LEN_LINE 80
/* length of a line. Each line has at most 80 characters, including \n
   and \0 */

/*
 * You are not allowed to use any numeric constant (for example, 65 or
 * 97) below.  Every constant must be defined as a symbol at the top
 * of this file (like NUM_CHAR and LEN_LINE).  You will lose 0.2 point
 * for each numeric constant below this point.
 */

/*
 * remember to call fclose if fopen is succeessful.
 */ 

/*
 * ============================================================
 */
int countLetter(char * file1, char * file2)
/*
 * The function counts the occurrences of the twenty sixe English
 * characters and write the results to another file.  
 *
 * file1: name of the input file
 * file2: name of the output file
 *
 * All upper-case letters are converted to lower-case letters. 'A' and
 * 'a' are both counted as 'a'.
 *
 * file1: name of the input file
 * file2: name of the output file
 *
 * This function returns EXIT_SUCCESS if it finishes without any
 * problem. The function returns EXIT_FAILURE if there is a problem in
 * opening the file, reading from the input file, or writing to the
 * output file.
 */
/*
 * You should NOT write anything like the following. You will lose
 * 20% points if you do so.
 *
 * if (c == 'a') ...
 * if (c == 'b') ...
 * if (c == 'c') ...
 * if (c == 'd') ...
 * 
 *
 * You should not write anything like the following, either.
 * switch (c)
 * {
 *  case 'a':
 *  ...
 *  case 'b':
 *  ...
 *  case 'c':
 *  ...
 *  }
 *
 * This is error-prone (what happens if you forget to change one
 * place?).  You should find a general method that is applicable to
 * all 26 characters.
 *
 * Whenever you copy-paste code, you have a higher chance of mistakes.
 *
 * Hint: create an array to store the counts.  Remember to initialize
 * the array's elements.
 *
 * Hint: C has several functions that can be useful.  Check isalpha,
 * isupper, islower.
 * 
 */
{
  return EXIT_SUCCESS;
}
/*
 * ============================================================
 */
int countString(char * file1, char * file2, char * str)
/*
 * The function counts the occurrences of a string in the input file.
 * The string is case-sensitive. "ECE" and "ece" are different.
 *
 * file1: name of the input file
 * file2: name of the output file
 * str: the string to search
 *
 * This function returns EXIT_SUCCESS if it finishes without
 * problem. The function returns EXIT_FAILURE if there is a problem
 * in opening the file, reading from the input file, or writing
 * to the output file.
 *
 * It is possible that the string may appear multiple times in the
 * same line. If this occurs, the function should count all all
 * occurrences.
 *
 * You need to count the string within each line. Do not count if the
 * string spans two or more lines.
 *
 * For simplicity, we assume that each line contains at most 80
 * characters.  Use LEN_LINE and do not use 80.  If LEN_LINE is
 * defined at the top of this file, you do not need to define anything
 * below.  You will lose 0.2 point if you use 80 or any number below.
 * If you need a number, define a symbol at the top of this file.
 *
 * Hint: fgets and strstr can be useful.
 * 
 */
{
  return EXIT_SUCCESS;
}
/*
 * ============================================================
 */

int read_front_letter(FILE *fptr, long *index);
int read_back_letter(FILE *fptr, long *index);

/*
 * ============================================================
 */
int isPalindrome(char * file1, char * file2)
/*
 * The function determine whether the input file is a palindrome.  All
 * upper-case letters are converted to lower-case letters.
 *
 * file1: name of the input file
 * file2: name of the output file
 *
 * This function returns EXIT_SUCCESS if it finishes without
 * problem. The function returns EXIT_FAILURE if there is a problem
 * in opening the file, reading from the input file, or writing
 * to the output file.
 *
 * Hint: fseek and ftell can be useful.
 *
 */
{

  /* use ftell to get the size of the file and initialize the
     indices */



  /* go to the beginning of the file */



  /* repeat until the two indices cross over 
   *    read the two alphabet letters from fptr 
   *    the 1st letter is at or after the position pointed at by front_ind 
   *    the 2nd letter is at or before the position pointed at by back_ind 
   *    if the two letters (upper or lower case) are the same, continue the 
   *       while iteration 
   *    else break from the loop 
   *    Note that 'A' and 'a' are treated to be the same letter 
   */
         
  return EXIT_SUCCESS;
}
int read_front_letter(FILE *fptr, long *ind)
/*
 * read an alphabet letter from fptr at the position *index or after
 * that you have to skip over non-alphabet letters
 * 
 * if the read is not successful (end of file is reached), the
 * function return -1 also, the letter read and returned by this
 * function and also the back_letter function should be of the same
 * case
 *
 * update *ind to point to a location right after the read letter
 */
   
{

  int c = 0;

  return c;
}

/*
 * ============================================================
 * Do not modify anything below
 * ============================================================
 */

/*
 * read an alphabet letter from fptr at the position *ind or before
 * that you have to skip over alphabet letters
 *
 * if the read is not successful (when *ind is < 0), should return -1
 * also, the letter read and returned by this function and also the
 * front_letter function should be of the same case
 *
 * update *ind to point to a location right before the read letter 
 *
 */

int read_back_letter(FILE *fptr, long *ind)
{
  while ((*ind) >= 0) 
    {
      fseek(fptr, *ind, SEEK_SET);
      int c = fgetc(fptr);
      (*ind) -= 1;
      if (isalpha(c)) 
	{
	  if (isupper(c)) 
	    {
	      c = c - 'A' + 'a';
	    }  
	  return c;
	}
    }
  return -1;
}
