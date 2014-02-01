
#include "answer02.h"

size_t my_strlen(const char * str)
{
    size_t len = 0;
    while(*str++) len++;
    return len;
}

int my_countchar(const char * str, char c)
{
    int count = 0;
    while(*str) {
	if(*str == c) count++;
	str++;
    }
    return count;
}

char * my_strchr(const char * str, int ch)
{
    const char * end = str + my_strlen(str);
    while(str <= end && *str != ch)
	str++;
    return (str <= end && *str == ch) ? (char *) str : NULL;
}

char * my_strrchr(const char * str, int ch)
{
    const char * end = str + my_strlen(str);
    while(end >= str && *end != ch)
	end--;
    return (end >= str && *end == ch) ? (char*) end : NULL;
}

char * my_strstr(const char * haystack, const char * needle)
{
    if(*needle == '\0') return (char *) haystack;
    
    while(*haystack != '\0') {
	const char * p1 = haystack;
	const char * p2 = needle;
	while(*p1 == *p2 && *p1 && *p2) {
	    p1++;
	    p2++;
	}
	if(*p2 == '\0') return (char *) haystack;
	haystack++;
    }

    return NULL;
}

char * my_strcpy(char * dest, const char * src)
{
    char * ret = dest;
    while(*src) *dest++ = *src++;
    *dest = '\0';
    return ret;
}

char * my_strcat(char * dest, const char * src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}

int my_isspace(int ch)
{
    return ch == ' ' || ch == '\n' || ch == '\v' || ch == '\f' 
	|| ch == '\r' || ch == '\t';
}

int my_atoi(const char * str)
{
    int is_negative = 0;
    
    while(*str && my_isspace(*str)) ++str; // skip whitespace

    if(*str == '-') {
	is_negative = 1;
	str++;
    }

    int ret = 0;
    while(*str >= '0' && *str <= '9')
	ret = ret * 10 + (*str++ - '0');

    return is_negative ? -ret : ret;
}

