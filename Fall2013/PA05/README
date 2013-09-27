This assignment has the following purposes: 

1. Allocate memory when the program runs.  You do not know the amount
  of memory needed in advance.  Your program will allocate memory only
  after the program knows the file to read.  Your program will be
  checked to determine whether the program uses memory correctly.  You
  will receive zero if the program allocates memory whose size is
  independent of the input file.

2. Use the built-in quicksort function (qsort). This function is
   general and can take arrays of different types. To use this
   function, your program needs to provide "comparison" functions.

This assignment asks you to write a program that reads integers and
strings.  You are encouraged to use fscanf to read integer and fgets
to read strings.  Please read the Linux manual about these two
functions.

Your program needs to have the following functions:

* Read the integers (or strings) from a file and store the data in
  memory.  You do not know the length of the file and have to read the
  file once, counting the amount of data.  After knowing the amount of
  data, allocate enough memory to store the data, read the file again
  and store the data in memory.

* Sort the data. You MUST NOT write the sorting function yourself,
  instead, a sort function (qsort) has been provided for you in the C
  library.  It is very important for you to understand how qsort
  function works. The main task is to write appropriate comparison
  functions for integers and for strings.

* Write the sorted data into a file.

* Release the allocated memory.

* You can assume that MAXIMUM_LENGTH is the maximum length of each
  line of a file.  It is defined for you already.

*************
* IMPORTANT *
*************

  When your program allocates memory, you must allocate enough memory
  to store the data but not more.  You cannot assume an input file
  has, for example, 1000 lines.  If you do so, you will definitely
  receive zero in this assignment.

  #define LARGESIZE 10000
  Student stu[LARGESIZE]; 
  /* allocate a large array, regardless of the size of the input file */

  The teaching staff will inspect your program to ensure that you do
  not violate this rule.  You will receive zero even if your program
  passes the test-cases.

  You should never have any global variable or static variable.

  The input files are stored in the inputs directory.  The expected
  outputs are stored in the expected directory.  Your program's
  outputs are stored in the outputs directory.

  You should read the files stored in outputs/valgrind-log* and check
  whether your program has any invalid memory access or memory leak.

NOTE:
Type "make" to compile the source code.
Type "make clean" to remove generated files.

Now, it is time to take a look at Makefile. Please read this, it is very important for you to know
how Makefile works and soon be able to write your own Makefile.

It is impossible to write a C program using a single file.
When you include a header file, you are already using multiple files.
You do not implement printf, do you? Where does it come from? 
It comes from C libraries, such as libc.so in /usr/lib/. 
Why is C designed in this way?  What are the advantages of writing a program using multiple files?

   * Reduce redundant work.  Many frequently used functions are supported by libraries. 
You don't have to write your own printf, scanf, or fopen.
   *Improve portability. Some functions handle low-level activities related to hardware, 
such as reading files from a disk or sending packets through a network. 
It is better to isolate the hardware-specific in libraries so that your program can run on different computers, 
as long as your program uses the correct libraries (usually need to recompile the source code).
   * Enhance performance. Libraries are well optimized so your program can have better performance.
   * Partition work for collabortion. When you write a large program with other people, 
it is natural to break the work into smaller units. Each of you is responsibile for some units. 
Each unit is stored in a single file.
   * Save compilation time. Compiling a large program can take hours. 
If the whole program is in a single file and you change only one line, 
you have to wait for hours to check whether your change is correct. 
A better solution is to break the program into many files and compile 
only the files affected by your change. 
Then the object files are linked. This may take a few seconds, much better than a few hours. 

The last advantage is critical in developing large programs. 
This is an important reason to separate compilation from linking.

Here is a simple example:

ex1: main2.o f1.o f2.o
	gcc -Wall -Wshadow main2.o f1.o f2.o -o ex1

main2.o: main2.c f1.h f2.h
	gcc -Wall -Wshadow  -c main2.c

f1.o: f1.c f1.h
	gcc -Wall -Wshadow  -c f1.c

f2.o: f2.c f2.h
	gcc -Wall -Wshadow  -c f2.c

clean:
	rm *.o ex1

 You should always have

 -Wall -Wshadow 

after gcc. They will give you warning messages that likely come from errors.

The first line means the program ex1 depends on three files: 
main2.o, f1.o, and f2.o. A .o file is called an object file. 
If these three files are available, the second line uses gcc to link 
the three object files and create the executable called ex1.  
Please notice that the command gcc is after a TAB, not space. 
How are the three object files are created? 
They are created by the following three rules. 
The file main2.o requires three files: main2.c, f1.h, and f2.h. 
The following line uses gcc to compile (with the -c flag) main2.c and create the object file main2.o.  
The same situation applies to f1.o and f2.o.  How do you use Makefile? Simply type

          make

and you will see the following messages

gcc -Wall -Wshadow -c main2.c
gcc -Wall -Wshadow -c f1.c
gcc -Wall -Wshadow -c f2.c
gcc -Wall -Wshadow main2.o f1.o f2.o -o ex1

 What is so important about Makefile? It is the dependence rules.

ex1: main2.o f1.o f2.o

says that the executable main depends on main.o, f1.o, and f2.o. 
If any of the three object files has been changed, execute the following command

	gcc -Wall -Wshadow main.o f1.o f2.o -o main

How does make know whether f1.o has changed? It checks the following rule

f1.o: f1.h f1.c

If f1.h or f1.c is changed, execute the following command

	gcc -Wall -Wshadow -c f1.c

If neither f1.h nor f1.c has changed, then f1.c will not be compiled. 
How does the computer know whether a file has been changed? 
It compares the time of the files. If f1.c's time is later than f1.o's time, 
make thinks f1.c has been changed and generates a new f1.o.  If you the following command

            touch f1.c

the time of f1.c is set to the current time and it is later than f1.o's time. Now, type

            make

again and you will see the following message

gcc -c f1.c
gcc -Wall -Wshadow main.o f1.o f2.o -o ex1

The message means that f1.c is compiled again and a newer version of main is created. 
Notice that f2.c is not recompiled. This saves time.  
If a file has not changed, it is unnecessary to compile it again.  The last rule says, if you type

                     make clean

the object files and main are deleted.

In Makefile, anything after # is treated as a comment.



 We can define symbols in Makefile. For example

GCC = gcc
CFLAGS = -Wall -Wshadow

ex1: main2.o f1.o f2.o
	$(GCC) $(CFLAGS) main2.o f1.o f2.o -o ex1

main2.o: main2.c f1.h f2.h
	$(GCC) $(CFLAGS) -c main2.c

f1.o: f1.h f1.c
	$(GCC) $(CFLAGS) -c f1.c

f2.o: f2.h f2.c
	$(GCC) $(CFLAGS) -c f2.c

clean:
	rm *.o ex1

If we decide to use another compiler, we can change this line

GCC = gcc

without changing any other lines because GCC is substituted in the following lines. 
We can also change the flags by adding -g for debugging or -O for optimization.

We can also create a symbol OBJS that represents all object files:

GCC = gcc
CFLAGS = -Wall -WShadow
OBJS = main2.o f1.o f2.o 
ex1: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o ex1

main2.o: main2.c f1.h f2.h
	$(GCC) $(CFLAGS) -c main2.c

f1.o: f1.h f1.c
	$(GCC) $(CFLAGS) -c f1.c

f2.o: f2.h f2.c
	$(GCC) $(CFLAGS) -c f2.c

clean:
	rm *.o ex1


Now let's try to understand the following lines in the Makefile of this programming assignment.

test0:  pa05
	@$(VALGRIND) --log-file=outputs/intmemoutput0 ./pa05 i inputs/intinput0 outputs/intoutput0
	@$(VALGRIND) --log-file=outputs/strmemoutput0 ./pa05 s inputs/strinput0 outputs/stroutput0
	@diff -w outputs/intoutput0 expected/intexpected0
	@diff -w outputs/stroutput0 expected/strexpected0

pa05 will compile your program since we earlier have defined 
pa05: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

$(VALGRIND) --log-file=outputs/intmemoutput0 
tells valgrind to put memory log-file in outputs directory 
(This is where you will go to check what happens if you have 
any memory leakage or other errors) with name intmemoutput0.

./pa05 i inputs/input0 outputs/intoutput0 will execute your object file with three arguments
 i, inputs/input0 and outputs/intoutput0

Prof. Lu will cover more of this in the future lecture but I highly encourage you 
to take a peek of pa05.c to see what these three arguments are and how they are used in 
the main program and later passed to your functions. Your input takes from inputs/input0
and the output of the program  will be stored in outputs/intoutput0.

Last but not the least,

@diff -w outputs/intoutput0 expected/intexpected0 will test your output with the expected
output, [ERROR] will be displayed if these two files are different.

That's all, folks. And please use gdb when there is something wrong with your program.


 

