------------------------------------------------------------------
ECE 264 - FALL 2013 - PROGRAMMING ASSIGNMENT 09
------------------------------------------------------------------
(Derived from an assignment by Professor Vijay Raghunathan)

INTRODUCTION
============
You will base your utilities on the widely used algorithmic technique
of Huffman coding, which is used in JPEG compression as well as in MP3
audio compression. For more information, please see the attached PDF file from last semester.

ASSIGNMENT
==========
Write a program that takes a compressed file, reads the Huffman tree
specified by the header, modify the provided postOrderPrint function and print the traverse of the Huffman Tree to a output file. Hint: the header can be either character-based representation or bit-based representation. See the input files to understand what that means.

SPECIFICATIONS
============== 
There will not be a skeleton provided for this assignment.  It will be
up to you to define all functions.  In the directory PA09, there will be different files for you to start. pa09.c is for you to write your main function. utility.c is for you to write your utility functions(all the functions except main funtion). pa09.h is for you to declare all the functions and structures. A Makefile will be provided later on for your testing convenience. Even without the Makefile, you should be able to write a simple Makefile for testing purpose.

*The program takes two input arguments:
 1. the input filename of the compressed file; and
 2. the output filename for the uncompressed file.

  - A suite of inputs and their expected outputs.

Here are some details for this program:
  In pa09.c you will need to do:
    1. Check argc, print error message if the number of arguments are not correct
    2. Open the input file, check if the file has been opened correctly, if not, print error message;
    3. Call a function to create Huffman Tree, return the head of the tree;
    4. Open an output file, use your own modified function postOrderPrint to print the traverse of the tree 
  
  In utility.c you will need to do:
    1. Write a function that can create Huffman Tree based on input(You will need to check if the input is char-based or bit-based, they are 
       different, so your create Huffman Tree should be able to handle both cases);
    2. Write functions to perform push and pop to maintain the Stack;
    3. Write any other functions you think are useful;

  In pa09.h you will need to do:
    1. Create two structures, one is for Huffman Tree, one is for Stack(This has been created for you, so don't worry);
    2. Declare all the functions and constants you use in your code(Do not use mysterious constants! That's very bad coding style);

*Reminder:
1. Be aware of memory leaks!
2. You must use stack to do this assignment and you need to use linked list to implement the stack.
3. All you need to do is to read the header and generate the Huffman Tree. The char-based header looks like:
   1g1o01s1 01e1h01p1r0000013\n
   The '\n' is the new line. Every '1' indicates the next character you read is the data of a leaf node, every '0' indicates the next character you read is data for non-leaf node.
4. Bit-representation is a little bit tricky, so start with char-representation.
5. Start early. You won't be able to finish the code in one day.

 
 
SAMPLE OUTPUT
=============

The output is just the printed traverse of nodes you have visited.

Consider the compressed file for string "streets are stone stars are
not", the output file of the program should read as follows:

Left
Left
Left
Back
Right
Back
Leaf: t
Back
Right
Left
Left
Back
Right
Back
Leaf: a
Back
Right
Left
Back
Right
Back
Leaf: r
Back
Back
Back
Right
Left
Left
Left
Left
Back
Right
Back
Leaf: n
Back
Right
Left
Back
Right
Back
Leaf: o
Back
Back
Right
Left
Back
Right
Back
Leaf:  
Back
Back
Right
Left
Left
Back
Right
Back
Leaf: e
Back
Right
Left
Back
Right
Back
Leaf: s
Back
Back
Back
Back
 
Consider the compressed file for string "go go gophers", the output
file of the program should read as follows:

Left
Left
Left
Back
Right
Back
Leaf: g
Back
Right
Left
Back
Right
Back
Leaf: o
Back
Back
Right
Left
Left
Left
Back
Right
Back
Leaf: s
Back
Right
Left
Back
Right
Back
Leaf:  
Back
Back
Right
Left
Left
Left
Back
Right
Back
Leaf: e
Back
Right
Left
Back
Right
Back
Leaf: h
Back
Back
Right
Left
Left
Back
Right
Back
Leaf: p
Back
Right
Left
Back
Right
Back
Leaf: r
Back
Back
Back
Back
Back


HINTS
=====

* You need to use structures for this assignment.  See tree.h for the
  Huffman node structure.

* A stack is a last-in first-out (LIFO) data structure that is very
  similar to a linked list, but it has three special operations:
  
  - push: place a new item (a Huffman subtree?) on the top of the
    stack, making this the new top.

  - peek: access the item (the Huffman subtree?) at the top of the
    stack, but does not change the stack.

  - pop: removes (and deallocates) the topmost element of the stack,
    making the next element the new top.

  It is also highly likely that you need a function to check the
  number of elements currently on the stack.

* We will check whether your program initializes all pointers to NULL.
  This can be accomplished in the following ways.

  - int * ptr = NULL; /* initialized to NULL, required */
  - int * ptr; 
  - ptr = NULL; /* immediately after declaring ptr */
  - int * ptr = malloc(numberElement * sizeof(int));

  If you write the following code without initialization, you will
  lose points.

  - int * ptr; /* uninitialized pointer. NOT ALLOWED */

  Why do we check this? Uninitializing pointers make a program's
  behavior unpredictable.

  (You are also allowed to declare and allocate memory for a pointer
  immediately using malloc() or calloc().)


WHAT TO SUBMIT?
===============

Submit a .zip file containing the following files: 

1. pa09.c pa09.h utility.c.

3. A README file that describes the algorithm used in your assignment.
   The README should say how the functions accomplish their goals, not
   just the goals themselves.
 

HOW TO SUBMIT?
==============
 
Your submission should be submitted through Blackboard.  You can
submit as many times on Blackboard as you need before the deadline. We
will grade the final submission, so please make sure that it is your
FINAL version with everything included.


HOW WILL WE GRADE YOUR SUBMISSION?
==================================
 
We will grade your assignments on algorithm correctness through DDD,
memory allocation and deletions through valgrind, proper coding
standards, content of README, a proper Makefile, and commenting.
 
ADDTIONAL FAQ
=============

1. What should I write in pa09.c?
You should write your main function in pa09.c. This main function should call the utility functions you write in utility.c to open the input, read the header, generate the Huffman Tree, and use post order print to an output file(See Makefile).

2. What are the tree.c and tree.h?
The tree.h is the header file for tree.c. The tree.c contains a function void Huff_postOrderPrint(HuffNode *tree), You should refer to this and write your own post order print function since you are writing your output to a file. In short, you should open an output file and use fprintf to do that. You should not submit tree.c and tree.h.

3. What is a bit-representation header?
The header information can be made more economical if we use bits 0 and 1 to distinguish between non-leaf and leaf nodes, and also to indicate the end of a topology. In these two examples, there will be a total of 10 bytes (8 bytes for the leaf nodes and 2 bytes for all the 0's and 1's). The challenge here is that both the compression and decompression programs would have to handle bits instead of characters. For example, in the bit-based approach, the first 16 bits (or the first 2 bytes) of the header information for encoding the string "streets are stone stars are not" are 10111010 01011000 (note that the space in the bit stream is introduced for better clarity). The ASCII coding for 't' straddles the two bytes, 7 bits in the first byte and 1 bit in the second byte. The second most significant bit in the second byte is a 1, indicating that the next 8 bits is an ASCII character, of which the the most significant 6 bits of the character 'a' is contained in the least significant 6 bits of the second byte.
 
In the bit-based representation of the Huffman coding tree, the last byte may not contain 8 bits. In this case, we again pad it with 0 bits. Consider the case where the input file uses nine distinct ASCII characters. The number of bits required to represent the Huffman coding tree is 9×8 + 9×2 = 90 bits, which can represented by 12 bytes. In other words, the last byte should contain only two useful bits. The 12 bytes are followed by "31\n", the number of characters in the string and the newline character.