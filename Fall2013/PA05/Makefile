
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS =
SOURCES = answer05.c pa05.c
TARGET = pa05
TESTN := $(shell seq 1 17)

# -------------------------------------------------------------

TESTS := $(addprefix test,${TESTN})

.PHONY : all build clean environment help testall $(TESTS)
.DEFAULT_GOAL := build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))

-include $(SOURCES:%=$(OBJF)/%.P)

all: | build testall

testall: | $(TESTS)

build: $(TARGET)

clean:
	@cd $(CURDIR)
	rm -rf $(TARGET) $(OBJF) outputs *.o

environment:
	@cd $(CURDIR)
	@mkdir -p outputs
	@mkdir -p $(OBJF)

help:	
	@echo "                                                           "
	@echo "   make            Build $(TARGET)"
	@echo "   make clean      Remove all temporary files"
	@echo "   make help       Print this message"
	@echo "   make test1      Run the zeroeth testcase"
	@echo "   make test2      Run the first testcase"
	@echo "   ...             etc."
	@echo "   make test17     Run the 17th testcase"
	@echo "   make testall    Run all testcases"
	@echo
	@echo "   Testcases 1-13 test integer inputs."
	@echo "   Testcases 14-17 test string inputs."
	@echo
	@echo "   Please try and run your code yourself before testing with the makefile"
	@echo "   PA06 will have no makefile, so you will cross that bridge soon =0."
	@echo

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<

${TESTS}: test%: $(TARGET) | environment
	@./bin/test.sh "$(TARGET)" $*

