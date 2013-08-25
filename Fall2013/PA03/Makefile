
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS =
SOURCES = answer03.c pa03.c
TARGET = pa03
TESTN := $(shell seq 0 12)

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
	@echo "   There are 13 testcases. (i.e., 0 through 109.) You can run an "
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
	@./bin/test.sh "$(TARGET)" inputs/input$* outputs/output$* expected/expected$* outputs/valgrind-log$*



