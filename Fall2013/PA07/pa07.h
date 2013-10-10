/* 
 * Do not modify this file.
 */


#ifndef PA07_H
#define PA07_H

#include <stdio.h>

typedef struct linked {
  int value;
  int index;
  struct linked * next;
} Node;

Node * List_create(int value, int index);
Node * List_build(int * value, int * index, int length);
Node * List_insert_ascend(Node * head, int value, int index);
Node * List_delete(Node * head, int index);
void List_destroy(Node * head);
void List_print(FILE * out, Node * head);
Node * List_copy(Node * head);
Node * List_reverse(Node * head);
Node * List_merge(Node * head1, Node * head2);
Node * List_getNode(Node * head, int index);

#endif

