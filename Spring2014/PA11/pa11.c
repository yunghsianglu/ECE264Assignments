
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#include "answer11.h"

int main(int argc, char * * argv)
{
    // Parse arguments
    if (argc < 3) {
	fprintf(stderr, "Invalid arguments, please refer to "
		"the README file, or read the source for "
		"pa11.c\n");
	return EXIT_FAILURE;
    }

    const char * processing_stage = argv[1];
    char * state = argv[2];

    if(!isValidState(state)) {
	fprintf(stderr, "Invalid state: %s\n", state);
	return EXIT_FAILURE;
    }

    // -- processMoveList
    if(strcmp(processing_stage, "1") == 0) {
	if (argc != 4) {
	    fprintf(stderr, "Invalid arguments for cmd=1\n");
	    return EXIT_FAILURE;
	}
	const char * movelist = argv[3];
	if(!isValidMoveList(movelist)) {
	    fprintf(stderr, "Invalid movelist: %s\n", movelist);
	    return EXIT_FAILURE;
	}
	processMoveList(state, movelist);
    }

    // -- generate move tree
    if (strcmp(processing_stage, "2") == 0) {
	if (argc != 4) {		    
	    fprintf(stderr, "Invalid arguments for cmd=2\n");
	    return EXIT_FAILURE;
	}
	int nummove = (int) strtol(argv[3], NULL, 10);
	if ((nummove < 0) || (nummove > 9)) {
	    fprintf(stderr, "Expected n=[0..9], but got %d\n", nummove);
	    return EXIT_FAILURE;
	}
	MoveTree * tree = generateAll(state, nummove);
	MoveTree_print(tree);
	MoveTree_destroy(tree);
    }

    // -- solve puzzle
    if (strcmp(processing_stage, "3") == 0) {
	char * movelist = solve(state);
	if(movelist == NULL) {
	    printf("No solution within %d steps\n", MAX_SEARCH_DEPTH);
	} else {
	    printf("%s\n", movelist);
	}
	free(movelist);
    }

    // If we got here, then success
    return EXIT_SUCCESS;
}

