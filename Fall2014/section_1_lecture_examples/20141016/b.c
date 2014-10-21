#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct {
	int x;
	int y;
} Point;

int main(int argc, char *argv[]) {
	Point p;
	p.x = 5;
	p.y = 10;
	Point p2 = p;
	p2.x = 6;
	printf("p  == (%d,%d)\n",
		p.x, p.y);
	printf("p2 == (%d,%d)\n",
		p2.x, p2.y);
	
	char s1[] = "abc";
	char* s2 = s1;
	s2[0] = "b";

	return 0;
}
