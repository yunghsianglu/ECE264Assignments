/**
 * Do not modify this file
 */
#ifndef PA07_H
#define PA07_H

/**
 * A ListNode structure for a linked list of strings.
 */
typedef struct ListNode_st
{
    char * str;
    struct ListNode_st * next;
} List;

/**
 * Create a new list-node with the passed string. 
 * str should be copied (with strdup).
 */
List * List_createNode(const char * str);

/**
 * Free all memory associated with the linked list, including memory for
 * contained strings. Must safely handle NULL lists.
 */
void List_destroy(List * list);

/**
 * Length of a linked list. 
 * The length of "NULL" is 0.
 */
int List_length(List * list);

/**
 * Merge two sorted lists to produce a final sorted list.
 * 
 * 'lhs' and 'rhs' are two sorted linked-list. Read 'left-hand-side' and 'right-
 * hand-side'. Note that either (or both) could be NULL, signifying the empty
 * list.
 * 'compar' is a function that is used to compare two nodes. This parameter is
 * similar to the parameter in qsort(...), except that it only compares two
 * strings. You can pass 'strcmp' to this function if you want to sort lists in
 * ascending order.
 *
 * When implementing this function, do not call List_createNode(...) or
 * malloc(...) Instead, think about how to build a new list by:
 * (1) Create a new (empty -- i.e., NULL) list where we build the result. You 
 *     will need to track the first and last node of this list.
 * (2) In a while-loop:
 * (2.a) Use compar to identify whether the front node of lhs or rhs is smaller.
 *       Remember that lhs or rhs could be NULL. 
 * (2.b) Move the front node of 'lhs/rhs' to the end of the result list. 
 *
 * You will need to consider what happens when 'lhs' or 'rhs' becomes NULL.
 *
 * Well-written code should be 20-30 lines long, including comments and spacing.
 * If your code is longer than this, then you may save time by rethinking your
 * approach.
 */
List * List_merge(List * lhs, 
		  List * rhs, 
		  int (*compar)(const char *, const char*));

/** 
 * Sorts the list's elements using the merge-sort algorithm.
 * Merge-sort is a recursive algorithm. See the README for hints.
 * 
 * The brief instructions are as follows:
 *
 * (1) Base case: 
 * Lists of length 0 or 1 are already (defacto) sorted. In this case, return
 * 'list'.
 *
 * (2) Recursive case: 
 * (2.a) Split the linked-list into two approx. equal sized lists.
 * (2.b) Call List_sort(...) on each of these smaller lists.
 * (2.c) Call List_merge(...) to merge the now sorted smaller lists into a 
 *       single larger sorted list, which you return.
 *
 * Well-written code should be 20-30 lines long, including comments and spacing.
 * If your code is longer than this, then you may save time by rethinking your
 * approach.
 */
List * List_sort(List * list, int (*compar)(const char *, const char*));

#endif

