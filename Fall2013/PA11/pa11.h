#ifndef PA11_H
#define PA11_H

#define TRUE 1
#define FALSE 0

// 4x4 puzzle
#define SIDELENGTH 4
#define FINAL_STATE "123456789ABCDEF-"

#define MAX_SEARCH_DEPTH 9

// To help debug
void printPuzzle(const char * state);

// --------------------------------------------------- Stage 0
// To check the validity of main's arguments
int isValidState(const char * state);
int isValidMoveList(const char * movelist);

// --------------------------------------------------- Stage 1
// Mutating the state of the puzzle
int move(char * state, char m);
void processMoveList(char * state, const char * movelist);

// --------------------------------------------------- Stage 2
// Generating all possible states in up to the given number of moves

// No two nodes in a MoveTree have the same 'state'
typedef struct move_tree_st {
    char * state;
    char * moves;
    struct move_tree_st * left;
    struct move_tree_st * right;
} MoveTree;

// Manipulating MoveTree
MoveTree * MoveTree_create(const char * state, const char * moves);
void MoveTree_destroy(MoveTree * node);
MoveTree * MoveTree_insert(MoveTree * node, const char * state, 
			   const char * moves);
MoveTree * MoveTree_find(MoveTree * node, const char * state);
void MoveTree_print(MoveTree * node);

// Generating all moves
MoveTree * generateAll(char * state, int n_moves);

// --------------------------------------------------- Stage 3
// Solving the puzzle
char * solve(char * state);

#endif

