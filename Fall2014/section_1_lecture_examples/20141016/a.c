#define SPACE ' '
#define WALL  'X'
#define TRACK '.'
#define MAX_W 100
#define MAX_H 100

void print_directions(char** maze, int w, int h) {
	Maze m;
	m.walls = maze;
	m.w = w;
	m.h = h;
	print_directions_nicely(m);
}
typedef struct {
	char** walls,
	int w,
	int h
} Maze;

void print_directions_nicely(Maze m) {
	printf("Width is %d\n", m.w);
	printf("Height is %d\n", m.h);
	printf("First row is %s\n", m.maze[0]);

	Maze* p_m = &m;

	printf("Width is %d\n",     p_m->w);
	printf("Height is %d\n",    p_m->h);
	printf("First row is %s\n", p_m->maze[0]);

	printf("Width is %d\n",     (*p_m).w);

}
