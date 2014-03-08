
/**
 * DO NOT MODIFY THIS FILE
 * 
 * You are welcome to browse through it. In particular, you may be interested
 * in the code for Huffman_applyTree(...)
 */

#include <stdlib.h>
#include <string.h>

#include "treefun.h"

// PrettyPrint code adapted from: 
// http://leetcode.com/2010/09/how-to-pretty-print-binary-tree.html
// code in public domain

#define FATAL(msg) {							\
	fprintf(stderr, "FATAL %s:%d %s\n", __FILE__, (int) __LINE__, msg); \
	exit(1);							\
    }

// ----------------------------------------------------------------------- Queue

/**
 * To draw binary trees "prettily", we need a Queue: a data structure where 
 * you add to the end and pull from the front.
 */
typedef struct Queue_st
{
    StackNode * head; 
    StackNode * tail; 
} Queue;

static Queue * Queue_create()
{
    return calloc(1, sizeof(Queue));
}

static void Queue_destroy(Queue * queue)
{
    if(queue == NULL) 
	return;
    StackNode * itr = queue->head;
    while(itr != NULL) {
	StackNode * next = itr->next;
	free(itr);
	itr = next;
    }
    free(queue);
}

static void Queue_pushBack(Queue * queue, HuffNode * tree)
{
    StackNode * node = malloc(sizeof(StackNode));
    node->tree = tree;
    node->next = NULL;
    if(queue->head == NULL) {
	queue->head = node;
	queue->tail = node;
    } else {
	queue->tail->next = node;
	queue->tail = node;
    }
}

static HuffNode * Queue_popFront(Queue * queue)
{
    if(queue->head == NULL)
	FATAL("Queue empty");
    StackNode * node = queue->head;
    queue->head = node->next;
    if(queue->head == NULL)
	queue->tail = NULL;
    HuffNode * tree = node->tree;
    free(node);
    return tree;
}

// --------------------------------------------- Convert 'node->value' to string

static void snprintNode(char * buffer, int len, HuffNode * node)
{
    // Put the node's value into buffer
    int value = node->value;
    if(node->left != NULL || node->left != NULL)
	snprintf(buffer, len, "o");
    else if(value == '\n') 
	snprintf(buffer, len, "\\n");
    else if(value == '\r') 
	snprintf(buffer, len, "\\r");
    else if(value == '\t') 
	snprintf(buffer, len, "\\t");
    else if(value == '\f') 
	snprintf(buffer, len, "\\f");
    else if(value == '\v') 
	snprintf(buffer, len, "\\v");
    else if(value == '\a') 
	snprintf(buffer, len, "\\a");
    else if(value == '\0') 
	snprintf(buffer, len, "\\0");
    else if(value == ' ') 
	snprintf(buffer, len, "' '");
    else if(value >= ' ' && value <= '~') 
	snprintf(buffer, len, "%c", value);
    else
	snprintf(buffer, len, "0x%02x", value);
}

// ----------------------------------------------------------------- Plain Print

static void HuffNode_print_Worker(HuffNode * node, FILE * fp, int level)
{
    // -- (1) -- Base case: empty subtree
    if (node == NULL)
	return;

    // -- (2) -- Recursive case: pre-order traversal
    // Print some spaces
    int i;
    for(i = 0; i < level; ++i)
	fprintf(fp, "     ");
    // Now the node->value
#define BUFLEN 8
    char buffer[BUFLEN];
    if(node->left != NULL || node->left != NULL)
	snprintf(buffer, BUFLEN, "%d", node->value);
    else
	snprintNode(buffer, BUFLEN, node);
#undef BUFLEN
    fprintf(fp, "%s\n", buffer);

    // left sub-tree
    HuffNode_print_Worker(node->left, fp, level + 1);

    // right sub-tree
    HuffNode_print_Worker(node->right, fp, level + 1);
}

void HuffNode_printPlain(FILE * fp, HuffNode * tree)
{
    HuffNode_print_Worker(tree, fp, 0);
}

// ---------------------------------------------------------------- Pretty Print

/** Find the maximum height of the binary tree */
static int HuffNode_height(HuffNode *p) {
    if(p == NULL) return 0;
    int hleft = HuffNode_height(p->left);
    int hright = HuffNode_height(p->right);
    return 1 + (hleft > hright ? hleft : hright);
}

/** Print the arm branches (eg, /    \ ) on a line */
static void print_branches(FILE * fp, Queue * Q, 
			   int branch_sz, int node_spacing_sz, int start_sz, 
			   int nodesThisLevel)
{
    int i, w, width;
    StackNode * itr = Q->head;
    for(i = 0; i < nodesThisLevel / 2; i++) {  
	width = (i == 0 ? (start_sz-1) : (node_spacing_sz-2));
	for(w = 0; w < width; ++w)
	    fprintf(fp, " ");
	fprintf(fp, "%s", (itr->tree ? "/" : " "));
	itr = itr->next;
	width = 2 * branch_sz + 2;
	for(w = 0; w < width; ++w)
	    fprintf(fp, " ");
	fprintf(fp, "%s", (itr->tree ? "\\" : " "));
	itr = itr->next;
    }
    fprintf(fp, "\n");
}

/** Print the branches and node (eg, ___o___ ) */
static void print_nodes(FILE * fp, Queue * Q, 
			int branch_sz, int node_spacing_sz, int start_sz, 
			int nodesThisLevel)
{
    int nodeOccupies = 2 * branch_sz + 2;
#define PATLEN 50
    char vstring[PATLEN];
    int i, w, width, fill, overflow;
    StackNode * itr = Q->head;
    for (i = 0; i < nodesThisLevel; i++, itr = itr->next) {
	if(itr->tree != NULL)
	    snprintNode(vstring, PATLEN, itr->tree);
	else
	    strcpy(vstring, "");

	int labelLen = strlen(vstring);
	int lhs_sp = (nodeOccupies - labelLen) / 2;
	int rhs_sp = nodeOccupies - labelLen - lhs_sp;
	overflow = (lhs_sp < 0 ? -lhs_sp : 0) + (rhs_sp < 0 ? -rhs_sp : 0);

	// Space before node
	width = (i == 0 ? start_sz : node_spacing_sz) - overflow;
	for(w = 0; w < width; ++w)
	    fprintf(fp, " ");

	// Node starts here
	fill = (itr->tree && itr->tree->left) ? '_' : ' ';
	for(w = 0; w < lhs_sp; ++w)
	    fprintf(fp, "%c", fill);
	fprintf(fp, "%s", vstring);
	fill = (itr->tree && itr->tree->right) ? '_' : ' ';
	for(w = 0; w < rhs_sp; ++w)
	    fprintf(fp, "%c", fill);
    }
    fprintf(fp, "\n");
#undef PATLEN
}

/** Print the leaves only (just for the bottom row) */
static void print_leaves(FILE * fp, Queue * Q, 
			 int indent, int level, int curr_tree_width)
{
#define PATLEN 50
    char pattern[PATLEN];
    char vstring[PATLEN];
    int i, width;
    StackNode * itr = Q->head;    
    for (i = 0; i < curr_tree_width && itr != NULL; i++) {
	width = (i == 0 ? (indent+2) : (2*level+2));
	snprintf(pattern, PATLEN, "%% %ds", width);
	if(itr->tree)
	    snprintNode(vstring, PATLEN, itr->tree);
	else
	    strcpy(vstring, "");
	fprintf(fp, pattern, vstring);
	fflush(fp);
	itr = itr->next;
    }
    fprintf(fp, "\n");
#undef PATLEN
}

/**
 * Pretty formatting of a binary tree to the output stream
 *
 * Parameters:
 * fp           FILE * to print to. Just use 'stdout' if you are unsure.
 * root         Root of Huffman Coding Tree that we're printing
 * level        Control how wide you want the tree to sparse (eg, level 1 has
 *              the minimum space between nodes, while level 2 has a larger
 *              space between nodes)
 * indent       Change this to add some indent space to the left (eg,
 *              indent of 0 means the lowest level of the left node will
 *              stick to the left margin)
 */
static void HuffNode_printPretty_Worker(FILE * fp, HuffNode * root, int level, 
					int indent) 
{
    int r, i; // for-loop indices
    int h = HuffNode_height(root);

    // eq of the length of branch for each node of each level
    int branch_sz = 2*((1 << h) - 1) - (3-level)*(1 << (h-1));

    // distance between left neighbor node's right arm and right neighbor 
    // node's left arm
    int node_spacing_sz = 2 + (level+1)*(1 << h);

    // starting space to the first node to print of each level 
    // (for the left most node of each level only)
    int start_sz = branch_sz + (3-level) + indent;  
    
    Queue * Q = Queue_create();
    Queue_pushBack(Q, root);
    int curr_tree_width = 1;
    for (r = 1; r < h; r++) {
	print_branches(fp, Q, branch_sz, node_spacing_sz, 
		       start_sz, curr_tree_width);
	branch_sz = branch_sz / 2 - 1;
	node_spacing_sz = node_spacing_sz / 2 + 1;
	start_sz = branch_sz + (3-level) + indent;
	print_nodes(fp, Q, branch_sz, node_spacing_sz, 
		    start_sz, curr_tree_width);
	for (i = 0; i < curr_tree_width; i++) {
	    HuffNode * currNode = Queue_popFront(Q);
	    if(currNode) {
		Queue_pushBack(Q, currNode->left);
		Queue_pushBack(Q, currNode->right);
	    } else {
		Queue_pushBack(Q, NULL);
		Queue_pushBack(Q, NULL);
	    }
	}
	curr_tree_width *= 2;
    }
    print_branches(fp, Q, branch_sz, node_spacing_sz, 
		   start_sz, curr_tree_width);
    print_leaves(fp, Q, indent, level, curr_tree_width);
    Queue_destroy(Q);
}

void HuffNode_printPretty(FILE * fp, HuffNode * tree)
{
    HuffNode_printPretty_Worker(fp, tree, 1, 0);
}

// ------------------------------------------------------------------ Tree Print

void HuffNode_print(FILE * fp, HuffNode * tree)
{
    int h = HuffNode_height(tree);
    if(h > 6)
	HuffNode_printPlain(fp, tree);
    else
	HuffNode_printPretty(fp, tree);
}

// ----------------------------------------------------------------- Stack Print

void Stack_print(FILE * fp, Stack * stack)
{
    int counter = 0;
    fprintf(fp, "-- BEGIN Stack --\n");
    StackNode * itr = stack->head;
    while(itr != NULL) {
	fprintf(fp, "\nNode #%d\n", counter++);
	HuffNode_print(fp, itr->tree);
	fprintf(fp, "\n");
	itr = itr->next;
    }
    fprintf(fp, "-- END Stack   --\n");
}

// ---------------------------------------------------------- Huffman Apply Tree

unsigned char * Huffman_applyTree(FILE * fp, HuffNode * tree, size_t * len_ptr)
{    
    // The length of the file is stored next:
    size_t len = 0;
    int val = fgetc(fp);
    while(!feof(fp) && val >= '0' && val <= '9') {
	len = (len * 10) + (val - '0');
	val = fgetc(fp);
    }
    if(val != '\n' || feof(fp))
	FATAL("Corrupt input file: new line not in expected place");

    // Allocate result buffer
    unsigned char * buffer = malloc(len * (sizeof(unsigned char) + 1));
    if(buffer == NULL)
	FATAL("Could not allocate buffer for decoding tree");
    buffer[len] = '\0'; // So buffer can be treated as a string

    // Now read the rest of the file into 'encoded'
    size_t write_pos = 0;
    int bit_offset = -1;
    unsigned char byte = 0;
    HuffNode * itr = tree;
    while(write_pos < len) {
	if(bit_offset < 0) {
	    byte = fgetc(fp);
	    if(feof(fp)) 
		FATAL("Unexpected end of file");
	    bit_offset = 7;
	}
	int bit = (byte >> bit_offset) & 0x01;
	bit_offset -= 1;
	if(bit == 1)
	    itr = itr->right;
	else 
	    itr = itr->left;
	if(itr->left == NULL && itr->right == NULL) {
	    buffer[write_pos++] = itr->value;
	    itr = tree;
	}
    }

    *len_ptr = len;
    return buffer;
}

