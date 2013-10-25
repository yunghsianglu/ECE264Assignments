Assignment PA08: Sparse Array

Consider a data structure called a sparse array: most elements of a
sparse array are 0. This means that most elements do not need to be
stored in the array. Only the elements whose values are non-zero are
stored. In a C program, a normal array of size N occupies a contiguous
piece of memory allocated for indexes from 0 to N − 1. It would be
inefficient to store a sparse array in a normal C array because most
space is wasted. Instead, you can use a data structure that stores
only non-zero elements.

In this question, you will implement a sparse array using a binary
search tree and add two sparse array. Each tree node has two integers
storing the index and the value. The binary search tree is built based
on the indexes:

-- If a node’s index is smaller than the parent’s index, this node is
   on the left side.

-- If a node’s index is larger than the parent’s index, this node is
   on the right side.

-- The indexes in the whole tree are distinct: no two nodes have the
   same index.  It is possible to have two nodes of the same value (but
   different indexes).

When merging two sparse array, array_1 and array_2:

 1. The contents in array_1 and array_2 should not be changed. You
    should create a new array (called new_array) that stores the
    result of merging.

 2. array_2 will be merged to new_array. This means you need to read
     nodes in array_2 and insert them into new_array.

 3. You need to use post-order to traverse the array_2 tree. 

 4. Values of two nodes need to be added only when the indices are the
    same.

 5. A node with value of 0 should be removed.

 6. if array_2 have nodes with index different than any nodes in
     new_array, you should insert those nodes into new_array.
  
Example:
Consider the following indices and corresponding values:

array_1:
int indices_1 [ NUM_VALUES_1 ] = {1 ,  2 ,  3 , 7 ,  8 , 9 };
int values_1  [ NUM_VALUES_1 ] = {3 ,  2 , -1 , -9 , -5 , 3 };

array_2:
int indices_2 [ NUM_VALUES_2 ] = {0 ,  1 ,  2 ,  3 , 4 , 7 , 9};
int values_2  [ NUM_VALUES_2 ] = {5 , -3 , -8 ,  1 , 7 , 9 , 1};

results:
int indices_3 [ NUM_VALUES_3 ] = { 0 ,  2 ,  4 , 8 , 9 };
int values_3  [ NUM_VALUES_3 ] = { 5 , -6 ,  7 ,-5 , 4 };
(elements whose values are zero are deleted)

Another hint: You may need to write your own functions.

About outputs: The output of pa08 only contains the final output,
which means make test only works when all the function has been done.
However, you can check your trees by "make testxx". (xx means some
number, such as 01, 02) Array1 and Array2 will be printed out in
"debug_files/", but this only works when you finished all functions
except SparseArray_merge and SparseArray_copy.