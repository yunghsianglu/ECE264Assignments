#include "pa05.h"
/*
 *
 * You will receive no point if you use the built-in string functions,
 * including but not limited to strlen, strcpy, strcat, strncat,
 * strstr.
 *
 */ 
/**
 * Count the number of characters in a NULL-terminated string s (not
 * counting the NULL character).
 *
 * Example: my_strlen("foo") should return 3.
 */
int my_strlen(const char *s)
{
    return 0;
}

/**
 * Count the number of occurrences of a particular character c in a
 * NULL-terminated string s.
 *
 * Example: my_countchar("foo", 'o') should return 2.
 */
int my_countchar(const char *s, char c)
{
    return 0;
}

/**
 * Convert an entire NULL-terminated string s to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that returns
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "ece264";
 * my_strupper(foobar) changes foobar to "ECE264".
 */
void my_strupper(char *s)
{
}

/**
 * Convert an entire NULL-terminated string s to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that return
 * the lowercase version of a character c.
 *
 * Example: char foobar[10] = "ECE264";
 * my_strupper(foobar) changes foobar to "ece264".
 */
void my_strlower(char *s)
{
}

/** 
 * Copy the contents of a NULL-terminated string s2 into the memory
 * pointed to by s1.  Any existing data in s1 will be overwritten by
 * the contents of s2.  Note: you can assume that there is sufficient
 * memory available in s1.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "bar2") changes foo to "bar2".
 */
void my_strcpy(char *s1, const char *s2)
{
}

/**
 * Copy the first n characters of a NULL-terminated string s2 into the
 * memory pointed to by s1. Any existing data in s1 will be
 * overwritten by the contents of s2.  Note: you can assume that there
 * is sufficient memory available in s1.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "bar", 1) changes foo to "b".
 */
void my_strncpy(char *s1, const char *s2, int num)
{
}

/** 
 * Concatenate (append) the contents of a NULL-terminated string s2
 * onto the end of the NULL-terminated string s1.  Note: you can
 * assume that there is sufficient memory available in s1.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "ece";
 * my_strcat(foo, "bar") changes foo to "ecebar".
 */
void my_strcat(char *s1, const char *s2) 
{
}

/** 
 * Concatenate (append) the first n characters of a NULL-terminated
 * string s2 onto the end of the NULL-terminated string s1.  Note: you
 * can assume that there is sufficient memory available in s1.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "ece";
 * my_strcat(foo, "bar", 1) changes foo to "eceb".
 */
void my_strncat(char *s1, const char *s2, int num)
{
}

/**
 * Return a pointer to the first occurrence of a NULL-terminated
 * substring s2 in a NULL-terminated string s1.  If s2 does not appear
 * in s1, the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will return NULL.
 * Example(2): my_strstr("foobar", "bar") will return a pointer to the
 * "bar" portion of the "foobar" argument.
 */
const char *my_strstr(const char *s1, const char *s2)
{
    return NULL;
}


/**
 * Insert a NULL-terminated string s2 in the NULL-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "ece";
 * my_strinsert(foo, "bar", 0) changes foo to "barece".
 * 
 * Example(2): char foo[10] = "ece";
 * my_strinsert(foo, "bar", 100) changes foo to "ecebar".
 */
void my_strinsert(char *s1, const char *s2, int pos)
{
}

/**
 * Delete a portion of the NULL-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "ecebar";
 * my_strdelete(foo, 3, 3) changes foo to "ece".
 *
 * Example(2): char foo[10] = "ecebar";
 * my_strdelete(foo, 0, 3) changes foo to "bar".
 * 
 * Example(3): char foo[10] = "ecebar";
 * my_strdelete(foo, 0, 34) changes foo to "".
 */
void my_strdelete(char *s, int pos, int length)
{
}
