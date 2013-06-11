
GCC = gcc
CFLAGS = -g -Wall -Wshadow
SOURCES = answer01.c pa01.c
TARGET = pa01
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

# -------------------------------------------------------------

.PHONY : all test memcheck build clean environment help
.DEFAULT_GOAL:= build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))

-include $(SOURCES:%=$(OBJF)/%.P)

all: | build test memcheck

test: $(TARGET) | environment
	./$(TARGET) > outputs/output
	cat outputs/output | sort | diff -w -q - expected/expected_sorted 

memcheck: $(TARGET) | environment
	$(VALGRIND) --log-file=outputs/memoutput ./$< > outputs/output
	@echo && ./expected/valgrind-checker.sh outputs/memoutput

build: $(TARGET)

clean:
	@cd $(CURDIR)
	rm -rf $(TARGET) $(OBJF) output/output output/memoutput 

environment:
	@mkdir -p outputs	
	@mkdir -p $(OBJF)

help:
	@echo
	@echo "   make             build $(TARGET)"
	@echo "   make all         build, test and memcheck"
	@echo "   make test        run tests"
	@echo "   make memcheck    run valgrind to check memory"
	@echo "   make clean       start from scratch"
	@echo
	@echo "   Temporary files written to ./$(OBJF) "
	@echo "   Outputs: output/output and output/memoutput "
	@echo "   Example output: expected/example-output "

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<


