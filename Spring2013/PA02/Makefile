GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer02.o pa02.o
HDRS = pa02.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY: clean test0 test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 test14 test15 test16 test17 test18 test19 gen
pa02: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	perl grader.pl 3 2

test0:
	@$(VALGRIND) --log-file=memoutput0 ./pa02 input0 > output0
	@./pa02 input0 > output0
	@diff -w output0 expected0

test1:
	@$(VALGRIND) --log-file=memoutput1 ./pa02 input1 > output1
	@./pa02 input1 > output1
	@diff -w output1 expected1

test2:
	@$(VALGRIND) --log-file=memoutput2 ./pa02 input2 > output2
	@./pa02 input2 > output2
	@diff -w output2 expected2

test3:
	@$(VALGRIND) --log-file=memoutput3 ./pa02 input3 > output3
	@./pa02 input3 > output3
	@diff -w output3 expected3

test4:
	@$(VALGRIND) --log-file=memoutput4 ./pa02 input4 > output4
	@./pa02 input4 > output4
	@diff -w output4 expected4

test5:
	@$(VALGRIND) --log-file=memoutput5 ./pa02 input5 > output5
	@./pa02 input5 > output5
	@diff -w output5 expected5

test6:
	@$(VALGRIND) --log-file=memoutput6 ./pa02 input6 > output6
	@./pa02 input6 > output6
	@diff -w output6 expected6

test7:
	@$(VALGRIND) --log-file=memoutput7 ./pa02 input7 > output7
	@./pa02 input7 > output7
	@diff -w output7 expected7

test8:
	@$(VALGRIND) --log-file=memoutput8 ./pa02 input8 > output8
	@./pa02 input8 > output8
	@diff -w output8 expected8

test9:
	@$(VALGRIND) --log-file=memoutput9 ./pa02 input9 > output9
	@./pa02 input9 > output9
	@diff -w output9 expected9

test10:
	@$(VALGRIND) --log-file=memoutput10 ./pa02 input10 > output10
	@./pa02 input10 > output10
	@diff -w output10 expected10

test11:
	@$(VALGRIND) --log-file=memoutput11 ./pa02 input11 > output11
	@./pa02 input11 > output11
	@diff -w output11 expected11

test12:
	@$(VALGRIND) --log-file=memoutput12 ./pa02 input12 > output12
	@./pa02 input12 > output12
	@diff -w output12 expected12

test13:
	@$(VALGRIND) --log-file=memoutput13 ./pa02 input13 > output13
	@./pa02 input13 > output13
	@diff -w output13 expected13

test14:
	@$(VALGRIND) --log-file=memoutput14 ./pa02 input14 > output14
	@./pa02 input14 > output14
	@diff -w output14 expected14

test15:
	@$(VALGRIND) --log-file=memoutput15 ./pa02 input15 > output15
	@./pa02 input15 > output15
	@diff -w output15 expected15

test16:
	@$(VALGRIND) --log-file=memoutput16 ./pa02 input16 > output16
	@./pa02 input16 > output16
	@diff -w output16 expected16

test17:
	@$(VALGRIND) --log-file=memoutput17 ./pa02 input17 > output17
	@./pa02 input17 > output17
	@diff -w output17 expected17

test18:
	@$(VALGRIND) --log-file=memoutput18 ./pa02 input18 > output18
	@./pa02 input18 > output18
	@diff -w output18 expected18

test19:
	@$(VALGRIND) --log-file=memoutput19 ./pa02 input19 > output19
	@./pa02 input19 > output19
	@diff -w output19 expected19

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

gen: geninput.c
	$(GCC) $(CFLAGS) geninput.c -o geninput
	./geninput

clean:
	rm -f pa02 geninput $(OBJS) output* memoutput*



