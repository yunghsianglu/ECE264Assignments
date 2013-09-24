GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer05.o pa05.o
HDRS = pa05.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose


pa05: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@


.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa05 $(OBJS) outputs/*

environment:
	@cd $(CURDIR)
	@mkdir -p outputs

help:	
	@echo "                                                           "
	@echo "   You do not actually need to do 'make' first to run the test,make test#" 
	@echo "   will do the job for you."
	@echo "                               "
	@echo "                               "                                      		
	@echo "   make            Build $(TARGET)"
	@echo "   make clean      Remove all temporary files"
	@echo "   make help       Print this message"
	@echo "   make test0      Run the zeroeth testcase"
	@echo "   make test1      Run the first testcase"
	@echo "   ...             etc."
	@echo "   You will compare your output file (if your program fails a test)" 
	@echo "   with the expected output file                                      "
	@echo "   Your program will stop  with ERORR message if the test fails    "
	@echo "   Also, you have to check the memoutput files to see if the valgrind complains"
	@echo "   Friendly note: there are 12 input files of integers while there are"
	@echo "   only 10 input files of strings"

test0:  pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput0 ./pa05 i inputs/intinput0 outputs/intoutput0
	@$(VALGRIND) --log-file=outputs/strmemoutput0 ./pa05 s inputs/strinput0 outputs/stroutput0
	@diff -w outputs/intoutput0 expected/intexpected0
	@diff -w outputs/stroutput0 expected/strexpected0

test1:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput1 ./pa05 i inputs/intinput1 outputs/intoutput1
	@$(VALGRIND) --log-file=outputs/strmemoutput1 ./pa05 s inputs/strinput1 outputs/stroutput1
	@diff -w outputs/intoutput1 expected/intexpected1
	@diff -w outputs/stroutput1 expected/strexpected1


test2:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput2 ./pa05 i inputs/intinput2 outputs/intoutput2
	@$(VALGRIND) --log-file=outputs/strmemoutput2 ./pa05 s inputs/strinput2 outputs/stroutput2
	@diff -w outputs/intoutput2 expected/intexpected2
	@diff -w outputs/stroutput2 expected/strexpected2

test3:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput3 ./pa05 i inputs/intinput3 outputs/intoutput3
	@$(VALGRIND) --log-file=outputs/strmemoutput3 ./pa05 s inputs/strinput3 outputs/stroutput3
	@diff -w outputs/intoutput3 expected/intexpected3
	@diff -w outputs/stroutput3 expected/strexpected3      


test4:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput4 ./pa05 i inputs/intinput4 outputs/intoutput4
	@$(VALGRIND) --log-file=outputs/strmemoutput4 ./pa05 s inputs/strinput4 outputs/stroutput4
	@diff -w outputs/intoutput4 expected/intexpected4
	@diff -w outputs/stroutput4 expected/strexpected4

test5:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput5 ./pa05 i inputs/intinput5 outputs/intoutput5
	@$(VALGRIND) --log-file=outputs/strmemoutput5 ./pa05 s inputs/strinput5 outputs/stroutput5
	@diff -w outputs/intoutput5 expected/intexpected5
	@diff -w outputs/stroutput5 expected/strexpected5

test6:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput6 ./pa05 i inputs/intinput6 outputs/intoutput6
	@$(VALGRIND) --log-file=outputs/strmemoutput6 ./pa05 s inputs/strinput6 outputs/stroutput6
	@diff -w outputs/intoutput6 expected/intexpected6
	@diff -w outputs/stroutput6 expected/strexpected6

test7:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput7 ./pa05 i inputs/intinput7 outputs/intoutput7
	@$(VALGRIND) --log-file=outputs/strmemoutput7 ./pa05 s inputs/strinput7 outputs/stroutput7
	@diff -w outputs/intoutput7 expected/intexpected7
	@diff -w outputs/stroutput7 expected/strexpected7

test8:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput8 ./pa05 i inputs/intinput8 outputs/intoutput8
	@$(VALGRIND) --log-file=outputs/strmemoutput8 ./pa05 s inputs/strinput8 outputs/stroutput8
	@diff -w outputs/intoutput8 expected/intexpected8
	@diff -w outputs/stroutput8 expected/strexpected8

test9:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput9 ./pa05 i inputs/intinput9 outputs/intoutput9
	@$(VALGRIND) --log-file=outputs/strmemoutput9 ./pa05 s inputs/strinput9 outputs/stroutput9
	@diff -w outputs/intoutput9 expected/intexpected9
	@diff -w outputs/stroutput9 expected/strexpected9

test10:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput10 ./pa05 i inputs/intinput10 outputs/intoutput10
	@diff -w outputs/intoutput10 expected/intexpected10


test11:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput11 ./pa05 i inputs/intinput11 outputs/intoutput11
	@diff -w outputs/intoutput11 expected/intexpected11


test12:	 pa05 | environment
	@$(VALGRIND) --log-file=outputs/intmemoutput12 ./pa05 i inputs/intinput12 outputs/intoutput12
	@diff -w outputs/intoutput12 expected/intexpected12



