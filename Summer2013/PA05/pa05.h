#ifndef PA05_H
#define PA05_H

typedef struct _huffnode {
  int value;
  struct _huffnode *left;
  struct _huffnode *right;
} HuffNode;

typedef struct _stack {
  struct _stack * next;
  HuffNode * node;
} Stack;

#endif
