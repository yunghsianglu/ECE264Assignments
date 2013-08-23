
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS =
SOURCES = answer02.c pa02.c
TARGET = pa02
TESTT := my_strlen my_countchar my_strupper my_strlower my_strcpy my_strncpy my_strcat my_strncat my_strstr my_strinsert my_strdelete
TESTN := $(shell seq 0 $(shell expr 10 \* $(shell echo "$(TESTT)" | wc -w) - 1))

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
	rm -rf $(TARGET) $(OBJF) outputs

environment:
	@cd $(CURDIR)
	@mkdir -p outputs
	@mkdir -p $(OBJF)

help:
	@echo
	@echo "   You do NOT need to use make to run your program. (See below.)"
	@echo
	@echo "   make            Build $(TARGET)"
	@echo "   make testall    Run /all/ testcases"
	@echo "   make clean      Remove all temporary files"
	@echo "   make help       Print this message"
	@echo
	@echo "   After building $(TARGET), you can run it manually as follows:"
	@echo
	@echo "      aturing > ./$(TARGET) -h"
	@echo 
	@echo "   It is highly recommended that you do this as you debug and"
	@echo "   test your code."
	@echo 
	@echo "   There are 110 testcases. (i.e., 0 through 109.) You can run an "
	@echo "   individual testcase as follows:"
	@echo
	@echo "   make test0      Run the zeroeth testcase"
	@echo "   make test1      Run the first testcase"
	@echo "   ...             etc."
	@echo

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<

${TESTS}: test%: $(TARGET) | environment
	@./bin/test.sh "$(TARGET)" $(shell echo "$(TESTT)" | awk "{ print \$$$(shell expr 1 + $* / 10); }") inputs/input$(shell expr $* % 10) outputs/output$* expected/expected$(shell expr $* % 10)_$(shell echo "$(TESTT)" | awk "{ print \$$$(shell expr 1 + $* / 10); }") outputs/valgrind-log$*

