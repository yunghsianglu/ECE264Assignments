#ifndef PA02_H
#define PA02_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int my_strlen(const char *s);
int my_countchar(const char *s, char c);

void my_strcat(char *s1, const char *s2);
void my_strncat(char *s1, const char *s2, int num);
void my_strcpy(char *s1, const char *s2);
void my_strncpy(char *s1, const char *s2, int num);

const char *my_strstr(const char *s1, const char *s2);

void my_strupper(char *s);
void my_strlower(char *s);

void my_strinsert(char *s1, const char *s2, int pos);
void my_strdelete(char *s, int pos, int length);

#endif /* pa02.h */
