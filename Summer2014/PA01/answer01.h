#ifndef PA01_H
#define PA01_H 

#include <stdlib.h>

//----------------------------------------------ARRAY FUNCTIONS

/** Return the sum of the array elements. */
int arraySum(int * array, int len);

//-------------------------------------------------------------

/**
 * How many elements are less than zero. 
 * 
 * Examples:
 * int array[] = { 1, 4, -5, 4 };
 * int len = 4;
 * int count = arrayCountNegative(array,len); // count == 1
 */
int arrayCountNegative(int * array, int len);

//-------------------------------------------------------------

/** 
 * Are the array elements increasing.
 * Return 1 (i.e., TRUE) if every element of the array is 
 * greater than or equal to preceding elements. Also return 1 
 * if the array is empty.
 * Return 0 if there is one or more elements that are smaller
 * than some preceding element.
 * 
 * Examples:
 * int array1[] = { 1, 1, 2, 3, 3 };
 * int len1 = 5;
 * int array2[] = { 1, 2, 0, 4 };
 * int len2 = 4;
 * int isInc1 = arrayIsIncreasing(array1, len1); // isInc1 == 1
 * int isInc2 = arrayIsIncreasing(array2, len2); // isInc2 == 0
 * int isInc3 = arrayIsIncreasing(NULL, 0);      // isInc3 == 1
 */
int arrayIsIncreasing(int * array, int len);

//------------------------------------------------------------- Searching Arrays

/** 
 * Find a needle (some integer) in a haystack (an array)
 * If the array "haystack" contains the integer "needle", then
 * return the _index_ of needle. If "haystack" contains "needle"
 * multiple times, then return the right-most (greatest) index.
 * If "needle" is not in "haystack", then return -1.
 *
 * Examples:
 * int haystack[] = { 1, 4, -5, 4 };
 * int len = 4;
 * int x1 = arrayIndexRFind(1, haystack, len); // x1 == 0
 * int x2 = arrayIndexRFind(4, haystack, len); // x2 == 3
 * int x3 = arrayIndexRFind(6, haystack, len); // x3 == -1
 */
int arrayIndexRFind(int needle, const int * haystack, int len);

//-------------------------------------------------------------

/** 
 * Return the _index_ of the smallest element in the array.
 * If the array is empty (has zero length), then return 0.
 * 
 * Examples:
 * int array[] = { 3, 4, -5 };
 * int len = 3;
 * int ind1 = arrayFindSmallest(array, len); // ind1 == -5
 */
int arrayFindSmallest(int * array, int len);

//------------------------------------------------------------- String Functions

/** 
 * Length of C string 'str', excluding the terminating null byte ('\0')
 * 
 * Examples:
 * my_strlen("abc"); // 3
 * my_strlen("");   // 0
 * my_strlen(NULL); // error -- undefined behavior. You do not need to 
 *                  // consider this case. See the README -- FAQ for more info.
 */
size_t my_strlen(const char * str);

//-------------------------------------------------------------

/**
 * Return a pointer to the first occurance of character 'ch' in C string 'str'
 * Return NULL if 'ch' is not found.
 *
 * Note that the terminating '\0' character is considered to be part of the 
 * string. Thus, if 'ch' is specified as '\0', then return a pointer to the
 * null terminator of the string.
 *
 * Examples:
 * const char * str = "Hello World!";
 * printf("'%s'\n", my_strchr(str, 'o')); // prints "'o World!'\n"
 * printf("'%s'\n", my_strchr(str, 'z')); // prints "'(null)'\n"
 *                                        // i.e., my_strchr(str, 'z') == NULL
 * printf("'%s'\n", my_strchr(str, '\0')); // prints "''\n"
 *
 * Please read the README FAQ before attempting this function.
 */
char * my_strchr(const char * str, int ch);

//-------------------------------------------------------------

/** 
 * Finds the first occurance of C-string 'needle' in C-string 'haystack'
 * Return 'haystack' when 'needle' is the empty string (ie, "").
 * The terminating null bytes are not compared.
 *
 * Examples:
 * const char * str = "Hello World!";
 * printf("'%s'\n", my_strstr(str, "World")); // prints "'World!'\n"
 * printf("'%s'\n", my_strstr(str, ""));      // prints "'Hello World!'\n"
 * printf("'%s'\n", my_strstr(str, "hello")); // prints "'(null)'\n"
 *                                      // i.e., my_strstr(str, "hello") == NULL
 */
char * my_strstr(const char * haystack, const char * needle);

//-------------------------------------------------------------

/**
 * Copys C-string 'src' (including the null-byte terminator) into the memory 
 * pointed to by 'dest'. The strings must not overlap, and 'dest' must be large
 * enough to contain 'src', *including* the terminating null-byte.
 *
 * Returns 'dest'
 *
 * Examples:
 * const char * str = "Hello World!"; // strlen(str) == 12, but 13 bytes with \0
 * char buffer[50];
 * printf("%s\n", my_strcpy(buffer, str)); // prints "Hello World!\n"
 */
char * my_strcpy(char * dest, const char * src);

//-------------------------------------------------------------

/**
 * Append C-string 'src' to C-string 'dest'. A precondition is 'Dest' must be 
 * large enough to contain both 'dest' and 'src', *including* the terminating
 * null-byte.
 *
 * Returns 'dest'
 *
 * Examples:
 * char buffer[50];
 * my_strcpy(buffer, "Hello ");
 * printf("%s\n", my_strcat(buffer, "Zippy!")); // prints "Hello Zippy!"
 */
char * my_strcat(char * dest, const char * src);

//-------------------------------------------------------------

/**
 * Returns 1 when 'ch' is a whitespace character, and 0 otherwise.
 *
 * By default, white-space characters are: space ' ', form-feed '\f', 
 * newline '\n', carriage return '\r', horizontal tab '\t' and vertical tab '\v'
 *
 * See the README FAQ for more information.
 *
 * Examples:
 * my_isspace(' '); // 1
 * my_isspace('\f'); // 1
 * my_isspace('\n'); // 1
 * my_isspace('\r'); // 1
 * my_isspace('\t'); // 1
 * my_isspace('\v'); // 1
 * char ch;
 * for(ch = 'A'; ch <= 'Z'; ++ch)
 *    my_isspace(ch); // always 0
 */
int my_isspace(int ch);

//-------------------------------------------------------------

/**
 * Convert the initial portion of 'str' to an integer.
 *
 * Implement my_atoi(str) as follows:
 * (1) Increment str to skip all white-space characters as defined by 
 * my_isspace(...)
 * (2) If there is a '-' sign, note that 'str' is a negative number, and 
 * increment str past the minus sign.
 * (3) Initialize a return value "ret" to 0. (int ret = 0)
 * (4) While '0' <= *str <= '9':
 *     (4.a) Multiply ret by 10
 *     (4.b) Add (*str - '0') to ret
 *     (4.c) Increment str
 * (5) If there was a minus sign, return -ret. Otherwise return ret.
 *
 * Examples:
 * my_atoi("0"); // 0
 * my_atoi("-12"); // -12
 * my_atoi("15th of March would be the ides."); // 15
 * my_atoi("4 months to Summer."); // 4
 * my_atoi("\n\f\t\v\r 6 white space characters handled correctly."); // 6
 * my_atoi("garbage should yield 0"); // 0
 */
int my_atoi(const char * str);

#endif
