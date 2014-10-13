/*
 * Usage:  ./pa06 [maze_file]
 *
 * If maze_file is not specified, it must be passed into stdin.
 *
 * The maze must be the output from the amaze program with walls denoted by 'X'
 * and spaces denoted by ' ' (space).
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer06.h"

void print_maze(char** maze, int w, int h);
void read_and_alloc_maze(char* maze[MAX_H], FILE* input, int* p_w, int* p_h);
void free_maze(char** maze, int h);

int main(int argc, char *argv[]) {
	// Open the maze file given on the command line or else use stdin.
	FILE* input = (argc == 1 ? stdin : fopen(argv[1], "r"));

	// Read the maze either from stdin or from a file given on the command line.
	char* maze[MAX_H] = {NULL};
	int w=0, h=0;
	read_and_alloc_maze(maze, input, &w, &h);
	fclose(input);

	// This won't work with a very small maze.
	if(h < 3 || w < 3) {
		fprintf(stderr, "Maze is too small.  Minimum is 3x3 characters.\n");
		free_maze(maze, h);
		return EXIT_FAILURE;
	}

	// Print the directions to traverse the entire maze.
	print_directions(maze, w, h);

	// Uncomment these lines to print the entire maze when it finishes.
	//printf("\n--------------------------------------\n");
	//print_maze(maze, w, h);

	// Free the memory on the heap for the maze.
	free_maze(maze, h);

	return EXIT_SUCCESS;
}

void print_maze(char** maze, int w, int h) {
	// Print the maze to stdout.
	int y=0;
	for(y=0; y < h; y++) {
		printf("%s\n", maze[y]);
	}
}

void read_and_alloc_maze(char* maze[MAX_H], FILE* input, int* p_w, int* p_h) {
	int w = 0, h = 0;
	for(h = 0; h < MAX_H; h++) {
		// Each line of the maze is allocated from the heap.
		maze[h] = malloc((MAX_W + 2) * sizeof(char));

		// Read a line of the maze.
		int success = fgets(maze[h], MAX_W + 1, input) != NULL;

		// If we are at EOF or if the line was less than 3 characters then stop.
		if(!success || strlen(maze[h]) < 3) {
			free(maze[h]);
			maze[h] = NULL;
			break;
		}

		// The maze width is the length of any given line, minus newline if any.
		w = strlen(maze[h]);
		while(maze[h][w-1] == '\n') {
			maze[h][w-1] = '\0';
			w--;
		}
	}
	*p_w = w;
	*p_h = h;
}

void free_maze(char** maze, int h) {
	// Free the memory on the heap for lines of the maze.
	while(h >= 1) {
		h--;
		free(maze[h]);
	}
}
