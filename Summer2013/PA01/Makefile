
GCC = gcc
CFLAGS = -g -Wall -Wshadow
SOURCES = answer01.c pa01.c
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose
TARGET = pa01

# -------------------------------------------------------------

.PHONY : test memcheck build clean environment help
.DEFAULT_GOAL:= build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))
DEPF = $(SOURCES:%=$(OBJF)/%.P)

-include $(SOURCES:%=$(OBJF)/%.P)

test: $(TARGET)
	cat outputs/output | sort | diff -w -q - expected/expected 

memcheck: $(TARGET) 
	$(VALGRIND) --log-file=outputs/memoutput ./$< > outputs/output

build: $(TARGET)

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/$(shell dirname "$<")\/\1,g' | sed '$$ s,$$, \\,' | sed 's,$(OBJF)/./,$(OBJF)/,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS) $(DEPF) output/output output/memoutput 

environment:
	@mkdir -p outputs	
	@mkdir -p $(OBJF)

help:
	@echo
	@echo "   make             build target /with/ help message"
	@echo "   make test        run tests"
	@echo "   make memcheck    run valgrind to check memory"
	@echo "   make clean       start from scratch"
	@echo
	@echo "   Temporary files written to ./$(OBJF) "
	@echo "   Outputs: output/output and output/memoutput "
	@echo "   Example output: expected/example-output "




