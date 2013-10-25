GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer08.o pa08.o
HDRS = pa08.h
TARGET = pa08
TESTN := $(shell seq 1 10)
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

TESTS := $(addprefix test,${TESTN})

.PHONY : all test clean environment help testall $(TESTS)

pa08: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

help:
	@echo
	@echo "make             build $(TARGET)"
	@echo "make testall     run all testcases"
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

testall:  | $(TESTS)

${TESTS}: test%: $(TARGET) | environment
	@echo '***************************************'
	@echo "test$*"
	@echo '***************************************'
	./$(TARGET) inputs/input$* outputs/output$* > debug_files/debug$*
	diff expected/output$* outputs/output$*
	$(VALGRIND) --log-file=outputs/memoutput$* ./$(TARGET) inputs/input$* outputs/output$* > /dev/null
	@echo
	@bin/valgrind-checker.sh outputs/memoutput$*
	@echo 


environment:
	@mkdir -p outputs
	@mkdir -p debug_files

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(TARGET) $(OBJS) outputs/output* outputs/memoutput* debug_files/* 
