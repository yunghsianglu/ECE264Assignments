GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = tree.o pa10.o
HDRS = tree.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa10: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

gentree: tree.o pa10.o tree.h
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: $(HDRS)
	$(GCC) $(CFLAGS) -c $*.c
	
grade:
	perl grader.pl 4 2 12

test0: pa10
	@$(VALGRIND) --log-file=outputs/memoutput0 ./pa10 inputs/input0 > outputs/output0
	diff -w outputs/output0 expected/expected0

test1: pa10
	@$(VALGRIND) --log-file=outputs/memoutput1 ./pa10 inputs/input1 > outputs/output1
	diff -w outputs/output1 expected/expected1

test2: pa10
	@$(VALGRIND) --log-file=outputs/memoutput2 ./pa10 inputs/input2 > outputs/output2
	diff -w outputs/output2 expected/expected2

test3: pa10
	@$(VALGRIND) --log-file=outputs/memoutput3 ./pa10 inputs/input3 > outputs/output3
	diff -w outputs/output3 expected/expected3

test4: pa10
	@$(VALGRIND) --log-file=outputs/memoutput4 ./pa10 inputs/input4 > outputs/output4
	diff -w outputs/output4 expected/expected4

test5: pa10
	@$(VALGRIND) --log-file=outputs/memoutput5 ./pa10 inputs/input5 > outputs/output5
	diff -w outputs/output5 expected/expected5

test6: pa10
	@$(VALGRIND) --log-file=outputs/memoutput6 ./pa10 inputs/input6 > outputs/output6
	diff -w outputs/output6 expected/expected6

test7: pa10
	@$(VALGRIND) --log-file=outputs/memoutput7 ./pa10 inputs/input7 > outputs/output7
	diff -w outputs/output7 expected/expected7

test8: pa10
	@$(VALGRIND) --log-file=outputs/memoutput8 ./pa10 inputs/input8 > outputs/output8
	diff -w outputs/output8 expected/expected8

test9: pa10
	@$(VALGRIND) --log-file=outputs/memoutput9 ./pa10 inputs/input9 > outputs/output9
	diff -w outputs/output9 expected/expected9

test10: pa10
	@$(VALGRIND) --log-file=outputs/memoutput10 ./pa10 inputs/input10 > outputs/output10
	diff -w outputs/output10 expected/expected10

test11: pa10
	@$(VALGRIND) --log-file=outputs/memoutput11 ./pa10 inputs/input11 > outputs/output11
	diff -w outputs/output11 expected/expected11

extra: pa10
	@$(VALGRIND) --log-file=outputs/memoutput12 ./pa10 inputs/extra12 > outputs/output12
	diff -w outputs/output12 expected/expected12
	@$(VALGRIND) --log-file=outputs/memoutput13 ./pa10 inputs/extra13 > outputs/output13
	diff -w outputs/output13 expected/expected13
	@$(VALGRIND) --log-file=outputs/memoutput14 ./pa10 inputs/extra14 > outputs/output14
	diff -w outputs/output14 expected/expected14
	@$(VALGRIND) --log-file=outputs/memoutput15 ./pa10 inputs/extra15 > outputs/output15
	diff -w outputs/output15 expected/expected15
	@$(VALGRIND) --log-file=outputs/memoutput16 ./pa10 inputs/extra16 > outputs/output16
	diff -w outputs/output16 expected/expected16
	@$(VALGRIND) --log-file=outputs/memoutput17 ./pa10 inputs/extra17 > outputs/output17
	diff -w outputs/output17 expected/expected17
	@$(VALGRIND) --log-file=outputs/memoutput18 ./pa10 inputs/extra18 > outputs/output18
	diff -w outputs/output18 expected/expected18
	@$(VALGRIND) --log-file=outputs/memoutput19 ./pa10 inputs/extra19 > outputs/output19
	diff -w outputs/output19 expected/expected19
	@$(VALGRIND) --log-file=outputs/memoutput20 ./pa10 inputs/extra20 > outputs/output20
	diff -w outputs/output20 expected/expected20
	@$(VALGRIND) --log-file=outputs/memoutput21 ./pa10 inputs/extra21 > outputs/output21
	diff -w outputs/output21 expected/expected21
	@$(VALGRIND) --log-file=outputs/memoutput22 ./pa10 inputs/extra22 > outputs/output22
	diff -w outputs/output22 expected/expected22
	@$(VALGRIND) --log-file=outputs/memoutput23 ./pa10 inputs/extra23 > outputs/output23
	diff -w outputs/output23 expected/expected23
	@$(VALGRIND) --log-file=outputs/memoutput24 ./pa10 inputs/extra24 > outputs/output24
	diff -w outputs/output24 expected/expected24
	@$(VALGRIND) --log-file=outputs/memoutput25 ./pa10 inputs/extra25 > outputs/output25
	diff -w outputs/output25 expected/expected25
	@$(VALGRIND) --log-file=outputs/memoutput26 ./pa10 inputs/extra26 > outputs/output26
	diff -w outputs/output26 expected/expected26
	@$(VALGRIND) --log-file=outputs/memoutput27 ./pa10 inputs/extra27 > outputs/output27
	diff -w outputs/output27 expected/expected27
	@$(VALGRIND) --log-file=outputs/memoutput28 ./pa10 inputs/extra28 > outputs/output28
	diff -w outputs/output28 expected/expected28
	@$(VALGRIND) --log-file=outputs/memoutput29 ./pa10 inputs/extra29 > outputs/output29
	diff -w outputs/output29 expected/expected29
	@$(VALGRIND) --log-file=outputs/memoutput30 ./pa10 inputs/extra30 > outputs/output30
	diff -w outputs/output30 expected/expected30
	@$(VALGRIND) --log-file=outputs/memoutput31 ./pa10 inputs/extra31 > outputs/output31
	diff -w outputs/output31 expected/expected31
	
clean:
	rm -f pa10 $(OBJS) outputs/*
