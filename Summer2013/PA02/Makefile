GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer02.o pa02.o
HDRS = pa02.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY : clean test0 test1 test2 test3 test4 test5
pa02: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	rm -f outputs/*output*
	./pa02 inputs/filelist 
	diff -q -w outputs/intoutput01 expected/intexpected01
	diff -q -w outputs/intoutput02 expected/intexpected02
	diff -q -w outputs/intoutput03 expected/intexpected03
	diff -q -w outputs/intoutput04 expected/intexpected04
	diff -q -w outputs/intoutput05 expected/intexpected05
	diff -q -w outputs/intoutput06 expected/intexpected06
	diff -q -w outputs/stroutput01 expected/strexpected01
	diff -q -w outputs/stroutput02 expected/strexpected02
	diff -q -w outputs/stroutput03 expected/strexpected03
	diff -q -w outputs/stroutput04 expected/strexpected04
	diff -q -w outputs/stroutput05 expected/strexpected05
	diff -q -w outputs/stroutput06 expected/strexpected06
	$(VALGRIND) --log-file=outputs/memoutput ./pa02 inputs/filelist 

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa02 $(OBJS) outputs/*output* 






