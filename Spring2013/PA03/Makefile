GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer03.o pa03.o
HDRS = pa03.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY : clean test0 test1 test2 test3 test4 test5
pa03: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	perl grader.pl 5 2

test0:
	@$(VALGRIND) --log-file=memoutput0 ./pa03 p 3 > outputpartition03
	@sort outputpartition03 > outputpartition03sorted
	@sort expectedpartition03 > expectedpartition03sorted
	@diff -w expectedpartition03sorted outputpartition03sorted
	@rm *sorted

test1:
	@$(VALGRIND) --log-file=memoutput1 ./pa03 p 4 > outputpartition04
	@sort outputpartition04 > outputpartition04sorted
	@sort expectedpartition04 > expectedpartition04sorted
	@diff -w expectedpartition04sorted outputpartition04sorted
	@rm *sorted

test2:
	@$(VALGRIND) --log-file=memoutput2 ./pa03 p 5 > outputpartition05
	@sort outputpartition05 > outputpartition05sorted
	@sort expectedpartition05 > expectedpartition05sorted
	@diff -w expectedpartition05sorted outputpartition05sorted
	@rm *sorted
	
test3:
	@$(VALGRIND) --log-file=memoutput3 ./pa03 p 6 > outputpartition06
	@sort outputpartition06 > outputpartition06sorted
	@sort expectedpartition06 > expectedpartition06sorted
	@diff -w expectedpartition06sorted outputpartition06sorted
	@rm *sorted
	
test4:
	@$(VALGRIND) --log-file=memoutput4 ./pa03 p 7 > outputpartition07
	@sort outputpartition07 > outputpartition07sorted
	@sort expectedpartition07 > expectedpartition07sorted
	@diff -w expectedpartition07sorted outputpartition07sorted
	@rm *sorted
	
test5:
	@$(VALGRIND) --log-file=memoutput5 ./pa03 p 8 > outputpartition08
	@sort outputpartition08 > outputpartition08sorted
	@sort expectedpartition08 > expectedpartition08sorted
	@diff -w expectedpartition08sorted outputpartition08sorted
	@rm *sorted

test6:
	@$(VALGRIND) --log-file=memoutput6 ./pa03 s 3 > outputsubset03
	@sort outputsubset03 > outputsubset03sorted
	@sort expectedsubset03 > expectedsubset03sorted
	@diff -w expectedsubset03sorted outputsubset03sorted
	@rm *sorted

test7:
	@$(VALGRIND) --log-file=memoutput7 ./pa03 s 4 > outputsubset04
	@sort outputsubset04 > outputsubset04sorted
	@sort expectedsubset04 > expectedsubset04sorted
	@diff -w expectedsubset04sorted outputsubset04sorted
	@rm *sorted

test8:
	@$(VALGRIND) --log-file=memoutput8 ./pa03 s 5 > outputsubset05
	@sort outputsubset05 > outputsubset05sorted
	@sort expectedsubset05 > expectedsubset05sorted
	@diff -w expectedsubset05sorted outputsubset05sorted
	@rm *sorted
	
test9:
	@$(VALGRIND) --log-file=memoutput9 ./pa03 s 6 > outputsubset06
	@sort outputsubset06 > outputsubset06sorted
	@sort expectedsubset06 > expectedsubset06sorted
	@diff -w expectedsubset06sorted outputsubset06sorted
	@rm *sorted
	
test10:
	@$(VALGRIND) --log-file=memoutput10 ./pa03 s 7 > outputsubset07
	@sort outputsubset07 > outputsubset07sorted
	@sort expectedsubset07 > expectedsubset07sorted
	@diff -w expectedsubset07sorted outputsubset07sorted
	@rm *sorted
	
test11:
	@$(VALGRIND) --log-file=memoutput11 ./pa03 s 8 > outputsubset08
	@sort outputsubset08 > outputsubset08sorted
	@sort expectedsubset08 > expectedsubset08sorted
	@diff -w expectedsubset08sorted outputsubset08sorted
	@rm *sorted

test12:
	@$(VALGRIND) --log-file=memoutput12 ./pa03 u 3 > outputpermute03
	@sort outputpermute03 > outputpermute03sorted
	@sort expectedpermute03 > expectedpermute03sorted
	@diff -w expectedpermute03sorted outputpermute03sorted
	@rm *sorted

test13:
	@$(VALGRIND) --log-file=memoutput13 ./pa03 u 4 > outputpermute04
	@sort outputpermute04 > outputpermute04sorted
	@sort expectedpermute04 > expectedpermute04sorted
	@diff -w expectedpermute04sorted outputpermute04sorted
	@rm *sorted

test14:
	@$(VALGRIND) --log-file=memoutput14 ./pa03 u 5 > outputpermute05
	@sort outputpermute05 > outputpermute05sorted
	@sort expectedpermute05 > expectedpermute05sorted
	@diff -w expectedpermute05sorted outputpermute05sorted
	@rm *sorted
	
test15:
	@$(VALGRIND) --log-file=memoutput15 ./pa03 u 6 > outputpermute06
	@sort outputpermute06 > outputpermute06sorted
	@sort expectedpermute06 > expectedpermute06sorted
	@diff -w expectedpermute06sorted outputpermute06sorted
	@rm *sorted
	
test16:
	@$(VALGRIND) --log-file=memoutput16 ./pa03 u 7 > outputpermute07
	@sort outputpermute07 > outputpermute07sorted
	@sort expectedpermute07 > expectedpermute07sorted
	@diff -w expectedpermute07sorted outputpermute07sorted
	@rm *sorted
	
test17:
	@$(VALGRIND) --log-file=memoutput17 ./pa03 u 8 > outputpermute08
	@sort outputpermute08 > outputpermute08sorted
	@sort expectedpermute08 > expectedpermute08sorted
	@diff -w expectedpermute08sorted outputpermute08sorted
	@rm *sorted


.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa03 $(OBJS) output* memoutput* *sorted






