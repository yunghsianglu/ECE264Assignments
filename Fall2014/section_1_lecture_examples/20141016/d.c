#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct {
	int x;
	int y;
	char* attraction;
} Point;
typedef struct {
	Point from;
	Point to;
} Route;

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

	Point p2 = copy_and_alloc(p);
	p2.x = 6;
	p2.y = 11;

	Route r;
	r.from = p;
	r.to = p2;

	printf("r: (%d,%d) to (%d,%d)", r.from.x, r.from.y, r.to.x, r.to.y);
	return 0;
}
