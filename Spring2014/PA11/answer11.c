
#include "answer11.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// ---------------------------------------------------------------- isValidState

int charcmp(const void * a, const void * b)
{
    return *((char*)a) - *((char*)b);
}

int isValidState(const char * state)
{
    int len = strlen(state);
    if(len != 16) return FALSE;
    char buffer[17];
    strcpy(buffer, state);
    qsort(buffer, len, sizeof(char), charcmp);
    const char * valid = "-123456789ABCDEF";
    if(strcmp(valid, buffer) == 0)
	return TRUE;
    return FALSE;
}

// ------------------------------------------------------------- isValidMoveList

int isValidMoveList(const char * moves)
{
    int len = strlen(moves);
    int i;
    for(i = 0; i <  len; ++i)
	if(moves[i] != 'R' && moves[i] != 'L' && 
	   moves[i] != 'U' && moves[i] != 'D')
	    return FALSE;
    return TRUE;
}

// ----------------------------------------------------------------- printPuzzle

void printPuzzle(const char * state)
{
    int row, col;
    for(row = 0; row < SIDELENGTH; ++row) {
	for(col = 0; col < SIDELENGTH; ++col) {
	    printf(" %c", state[row*SIDELENGTH + col]);
	}
	printf("\n");
    }
}

// ------------------------------------------------------------------------ Move

int move(char * state, char m)
{
    int dx = 0;
    int dy = 0;
    switch(m) {
    case 'U': dy = -1; break;
    case 'D': dy = 1; break;
    case 'L': dx = -1; break;
    case 'R': dx = 1; break;
    default:
	fprintf(stderr, "Invalid move '%c'!\n", m);
	return FALSE;
    }
    char * strpos = strstr(state, "-");
    if(strpos == NULL) {
	fprintf(stderr, "Invalid state '%s'!\n", state);
	return FALSE;
    }
    int pos = strpos - state;
    int row = pos / SIDELENGTH;
    int col = pos % SIDELENGTH;
    if(row + dy < 0 || row + dy >= SIDELENGTH)
	return FALSE;
    if(col + dx < 0 || col + dx >= SIDELENGTH)
	return FALSE;

    // Now we know we have a valid move...
    int target_pos = (row+dy)*SIDELENGTH + (col+dx);

    // So swap 'pos' with 'target_pos'
    state[pos] = state[target_pos];
    state[target_pos] = '-';

    return TRUE;
}

// ------------------------------------------------------------- processMoveList

void processMoveList(char * state, const char * movelist)
{
#ifdef MYDEBUG
    printf("\nApply sequence '%s' to initial state:\n", movelist);
    printPuzzle(state);
#endif

    int valid = TRUE;
    int ind = 0;
    int movelist_len = strlen(movelist);
    for(ind = 0; ind < movelist_len && valid; ++ind) {
	if(!move(state, movelist[ind])) {
	    valid = FALSE;
	} else {
#ifdef MYDEBUG
	    printf("\nApply move '%c':\n", movelist[ind]);
	    printPuzzle(state);
#endif
	}
    }
	    
    if(!valid) {
	printf("I\n");
    } else {
#ifdef MYDEBUG
	printf("\nFinal state: \n");
	printPuzzle(state);
#else
	printf("%s\n", state);
#endif
    }
}

// -------------------------------------------------------------------- MoveTree
MoveTree * MoveTree_create(const char * state, const char * moves)
{
    MoveTree * node = malloc(sizeof(MoveTree));
    node -> state = strdup(state);
    node -> moves = strdup(moves);
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void MoveTree_destroy(MoveTree * node)
{
    if(node == NULL)
	return;
    MoveTree_destroy(node -> left);
    MoveTree_destroy(node -> right);
    free(node -> state);
    free(node -> moves);
    free(node);
}

MoveTree * MoveTree_insert(MoveTree * node, const char * state,
			   const char * moves)
{
    if(node == NULL) {
#ifdef MYTEST
	if(strcmp(state, FINAL_STATE) == 0) {
	    printf("FINAL FOUND\n");
	}
#endif
	return MoveTree_create(state, moves);
    }
	
    int cmp = strcmp(state, node -> state);
    
    if(cmp < 0) 
	node -> left = MoveTree_insert(node -> left, state, moves);
    else if(cmp > 0)
	node -> right = MoveTree_insert(node -> right, state, moves);
    else if(strlen(moves) < strlen(node -> moves)) 
	strcpy(node -> moves, moves); // overwrite with shorter seq
	
    return node;
}

MoveTree * MoveTree_find(MoveTree * node, const char * state)
{
    if(node == NULL)
	return NULL;
    int cmp = strcmp(node -> state, state);
    if(cmp < 0)
	return MoveTree_find(node -> right, state);
    else if(cmp > 0)
	return MoveTree_find(node -> left, state);
    
    return node; // We found it!
}

void MoveTree_print(MoveTree * node)
{
    if(node == NULL)
	return;
    printf("%s\n", node -> state);
    MoveTree_print(node -> left);
    MoveTree_print(node -> right);
}

// ----------------------------------------------------------------- generateAll

void generateAllHelper(MoveTree * root, int n_moves, 
		       const char * state, 
		       char * movelist, int ind)
{    
    const char possibleMoves[] = { 'U', 'D', 'L', 'R' };
    int numPossibleMoves = sizeof(possibleMoves) / sizeof(char);
    if(ind == n_moves) {
	// Base case
	return; // nothing to do
    } 

    // Recursive case
    int i;
    for(i = 0; i < numPossibleMoves; ++i) {
	char m = possibleMoves[i];
	char * dup_state = strdup(state);
	if(move(dup_state, m)) {
	    movelist[ind] = m;
	    movelist[ind+1] = '\0'; // Terminates the movelist
	    MoveTree_insert(root, dup_state, movelist);
	    generateAllHelper(root, n_moves, dup_state, movelist, 
			      ind + 1);
	} else {
	    // Move unimportant
	}
	free(dup_state);
    }
}

MoveTree * generateAll(char * state, int n_moves)
{ 
    MoveTree * tree = MoveTree_create(state, "");
    char * movelist = malloc((n_moves+1) * sizeof(char));
    movelist[n_moves] = '\0';
    generateAllHelper(tree, n_moves, state, movelist, 0);
    free(movelist);
    return tree;
}

// ----------------------------------------------------------------------- Solve

char * solve(char * state)
{
    MoveTree * tree = generateAll(state, MAX_SEARCH_DEPTH);
    MoveTree * answer = MoveTree_find(tree, FINAL_STATE);
    char * movelist = NULL;
    if(answer != NULL)
	movelist = strdup(answer -> moves);
    MoveTree_destroy(tree);
    return movelist;
}

