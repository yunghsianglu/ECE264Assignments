GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer01.o pa01.o
HDRS = pa01.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY : clean test0 test1 test2 test3 test4 test5
pa01: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	rm -f output/output
	./pa01 | sort > outputs/output
	diff -q -w outputs/output expected/expected
	$(VALGRIND) --log-file=outputs/memoutput ./pa01 > outputs/output

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa01 $(OBJS) outputs/output outputs/memoutput 






