#ifndef pa08_h
#define pa08_h

typedef struct snode {
  int index ;
  int value ;
  struct snode * left ;
  struct snode * right ;
} SparseNode ;

SparseNode * SparseNode_create(int index, int value);
SparseNode * SparseArray_build(int * indicies, int * values, int length);
void SparseArray_destroy ( SparseNode * array );
int SparseArray_getMin ( SparseNode * array );
int SparseArray_getMax ( SparseNode * array );
SparseNode * SparseArray_getNode ( SparseNode * array , int index );
SparseNode * SparseArray_remove ( SparseNode * array , int index );
SparseNode * SparseArray_insert ( SparseNode * array, int index, int value );
SparseNode * SparseArray_copy(SparseNode * array);
SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2);

#endif
