#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct {
	int x;
	int y;
	char* attraction;
} Point;

Point copy_and_alloc(Point src) {
	Point dst;
	dst.x = src.x;
	dst.y = src.y;

	// dst.attraction = src.attraction;
	dst.attraction = malloc(
						(strlen(src.attraction) + 1) * sizeof(char));
	strcpy(dst.attraction, src.attraction);
	return dst;
}

int main(int argc, char *argv[]) {
	char s1[] = "zoo";
	Point p;
	p.x = 5;
	p.y = 10;
	p.attraction = s1;

	//Point p2 = p;
	Point p2 = copy_and_alloc(p);

	p2.x = 6;
	printf("Before changing attraction\n");
	printf("p  == (%d,%d,%s)\n", p.x, p.y, p.attraction);
	printf("p2 == (%d,%d,%s)\n", p2.x, p2.y, p2.attraction);
	p2.attraction[0] = 'f';

	printf("Subsequent to changing attraction\n");
	printf("p  == (%d,%d,%s)\n", p.x, p.y, p.attraction);
	printf("p2 == (%d,%d,%s)\n", p2.x, p2.y, p2.attraction);

	free(p2.attraction);
	return 0;
}
