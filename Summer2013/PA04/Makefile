GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer04.o pa04.o
HDRS = pa04.h
TARGET = pa04
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY : all test clean environment help test01 test02 test03 test04 test05 test06 test07 test08 test09 test10

pa04: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

help:
	@echo
	@echo "make             build $(TARGET)"
	@echo "make test        run all testcases"
	@echo "make clean       start from scratch"
	@echo
	@echo "make test01	normal case with fewer inputs"
	@echo "make test02	two empty array"
	@echo "make test03	arrays with value of 0"
	@echo "make test04	arrays with redundant index"
	@echo "make test05	identical arrays with inverse sign values"
	@echo "make test06	normal cases"
	@echo "make test07	normal cases"
	@echo "make test08	normal cases"
	@echo "make test09	normal cases"
	@echo "make test10	normal cases"

test: | test01 test02 test03 test04 test05 test06 test07 test08 test09 test10

test01: $(TARGET) | environment
	./$(TARGET) inputs/input1 outputs/output1 >debug_files/debug01
	diff expected/output1 outputs/output1
	$(VALGRIND) --log-file=outputs/memoutput1 ./pa04 inputs/input1 outputs/output1 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput1

test02: $(TARGET) | environment
	./$(TARGET) inputs/input2 outputs/output2 >debug_files/debug02
	diff expected/output2 outputs/output2
	$(VALGRIND) --log-file=outputs/memoutput2 ./pa04 inputs/input2 outputs/output2 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput2

test03: $(TARGET) | environment
	./$(TARGET) inputs/input3 outputs/output3 >debug_files/debug03
	diff expected/output3 outputs/output3
	$(VALGRIND) --log-file=outputs/memoutput3 ./pa04 inputs/input3 outputs/output3 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput3

test04: $(TARGET) | environment
	./$(TARGET) inputs/input4 outputs/output4 >debug_files/debug04
	diff expected/output4 outputs/output4
	$(VALGRIND) --log-file=outputs/memoutput4 ./pa04 inputs/input4 outputs/output4 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput4

test05: $(TARGET) | environment
	./$(TARGET) inputs/input5 outputs/output5 >debug_files/debug05
	diff expected/output5 outputs/output5
	$(VALGRIND) --log-file=outputs/memoutput5 ./pa04 inputs/input5 outputs/output5 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput5

test06: $(TARGET) | environment
	./$(TARGET) inputs/input6 outputs/output6 >debug_files/debug06
	diff expected/output6 outputs/output6
	$(VALGRIND) --log-file=outputs/memoutput6 ./pa04 inputs/input6 outputs/output6 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput6

test07: $(TARGET) | environment
	./$(TARGET) inputs/input7 outputs/output7 >debug_files/debug07
	diff expected/output7 outputs/output7
	$(VALGRIND) --log-file=outputs/memoutput7 ./pa04 inputs/input7 outputs/output7 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput7

test08: $(TARGET) | environment
	./$(TARGET) inputs/input8 outputs/output8 >debug_files/debug08
	diff expected/output8 outputs/output8
	$(VALGRIND) --log-file=outputs/memoutput8 ./pa04 inputs/input8 outputs/output8 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput8

test09: $(TARGET) | environment
	./$(TARGET) inputs/input9 outputs/output9 >debug_files/debug09
	diff expected/output9 outputs/output9
	$(VALGRIND) --log-file=outputs/memoutput9 ./pa04 inputs/input9 outputs/output9 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput9

test10: $(TARGET) | environment
	./$(TARGET) inputs/input10 outputs/output10 >debug_files/debug10
	diff expected/output10 outputs/output10
	$(VALGRIND) --log-file=outputs/memoutput10 ./pa04 inputs/input10 outputs/output10 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput10

environment:
	@mkdir -p outputs
	@mkdir -p debug_files

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(TARGET) $(OBJS) outputs/output* outputs/memoutput* debug_files/* 
