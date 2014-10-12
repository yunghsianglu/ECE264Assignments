#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void print_maze(char** maze, int w, int h);
void read_and_alloc_maze(char* maze[MAX_H], FILE* input, int* p_w, int* p_h);
void free_maze(char** maze, int h);

int main(int argc, char *argv[]) {
	int w=0, h=0;
	FILE* input = (argc == 1 ? stdin : fopen(argv[1], "r"));
	char* maze[MAX_H] = {NULL};
	read_and_alloc_maze(maze, input, &w, &h);
	fclose(input);

	if(h >= 3 && w >= 3) {
		print_maze(maze, w, h);
		print_directions((char**)maze, w, h);
		printf("\n\n\n--------------------------------------\n\n\n");
		print_maze(maze, w, h);
	}

	free_maze(maze, h);
	return 0;
}

void print_maze(char** maze, int w, int h) {
	int y=0;
	for(y=0; y < h; y++) {
		printf("%s", maze[y]);
	}
}

void read_and_alloc_maze(char* maze[MAX_H], FILE* input, int* p_w, int* p_h) {
	int w = 0, h = 0;
	for(h = 0; h < MAX_H; h++) {
		maze[h] = malloc((MAX_W + 2) * 2 * sizeof(char));
		int success = fgets(maze[h], MAX_W, input) != NULL;
		if(!success || strlen(maze[h]) <= 2) {
			if(success) {
				free(maze[h]);
				maze[h] = NULL;
			}
			break;
		}
		w = strlen(maze[h]);
		while(maze[h][w-1] == '\n') {
			w--;
		}
	}
	*p_w = w;
	*p_h = h;
}

void free_maze(char** maze, int h) {
	while(h >= 1) {
		h--;
		free(maze[h]);
	}
}
