GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer01.o pa01.o
HDRS = pa01.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY: clean test0 test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 test14 test15 test16 test17 test18 test19 gen
pa01: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	perl grader.pl 2 2

test0:
	@$(VALGRIND) --log-file=memoutput0 ./pa01 input0 > output0
	@./pa01 input0 > output0
	@diff -w output0 expected0

test1:
	@$(VALGRIND) --log-file=memoutput1 ./pa01 input1 > output1
	@./pa01 input1 > output1
	@diff -w output1 expected1

test2:
	@$(VALGRIND) --log-file=memoutput2 ./pa01 input2 > output2
	@./pa01 input2 > output2
	@diff -w output2 expected2

test3:
	@$(VALGRIND) --log-file=memoutput3 ./pa01 input3 > output3
	@./pa01 input3 > output3
	@diff -w output3 expected3

test4:
	@$(VALGRIND) --log-file=memoutput4 ./pa01 input4 > output4
	@./pa01 input4 > output4
	@diff -w output4 expected4

test5:
	@$(VALGRIND) --log-file=memoutput5 ./pa01 input5 > output5
	@./pa01 input5 > output5
	@diff -w output5 expected5

test6:
	@$(VALGRIND) --log-file=memoutput6 ./pa01 input6 > output6
	@./pa01 input6 > output6
	@diff -w output6 expected6

test7:
	@$(VALGRIND) --log-file=memoutput7 ./pa01 input7 > output7
	@./pa01 input7 > output7
	@diff -w output7 expected7

test8:
	@$(VALGRIND) --log-file=memoutput8 ./pa01 input8 > output8
	@./pa01 input8 > output8
	@diff -w output8 expected8

test9:
	@$(VALGRIND) --log-file=memoutput9 ./pa01 input9 > output9
	@./pa01 input9 > output9
	@diff -w output9 expected9

test10:
	@$(VALGRIND) --log-file=memoutput10 ./pa01 input10 > output10
	@./pa01 input10 > output10
	@diff -w output10 expected10

test11:
	@$(VALGRIND) --log-file=memoutput11 ./pa01 input11 > output11
	@./pa01 input11 > output11
	@diff -w output11 expected11

test12:
	@$(VALGRIND) --log-file=memoutput12 ./pa01 input12 > output12
	@./pa01 input12 > output12
	@diff -w output12 expected12

test13:
	@$(VALGRIND) --log-file=memoutput13 ./pa01 input13 > output13
	@./pa01 input13 > output13
	@diff -w output13 expected13

test14:
	@$(VALGRIND) --log-file=memoutput14 ./pa01 input14 > output14
	@./pa01 input14 > output14
	@diff -w output14 expected14

test15:
	@$(VALGRIND) --log-file=memoutput15 ./pa01 input15 > output15
	@./pa01 input15 > output15
	@diff -w output15 expected15

test16:
	@$(VALGRIND) --log-file=memoutput16 ./pa01 input16 > output16
	@./pa01 input16 > output16
	@diff -w output16 expected16

test17:
	@$(VALGRIND) --log-file=memoutput17 ./pa01 input17 > output17
	@./pa01 input17 > output17
	@diff -w output17 expected17

test18:
	@$(VALGRIND) --log-file=memoutput18 ./pa01 input18 > output18
	@./pa01 input18 > output18
	@diff -w output18 expected18

test19:
	@$(VALGRIND) --log-file=memoutput19 ./pa01 input19 > output19
	@./pa01 input19 > output19
	@diff -w output19 expected19

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

gen: geninput.c
	$(GCC) $(CFLAGS) geninput.c -o geninput
	./geninput

clean:
	rm -f pa01 geninput $(OBJS) output*



