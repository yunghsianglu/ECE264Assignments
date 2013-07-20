
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS = -lm -lpthread
SOURCES = pa06.c parallel-primes.c
TARGET = pa06
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

# -------------------------------------------------------------

.PHONY : all build clean environment help
.DEFAULT_GOAL:= build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))

-include $(SOURCES:%=$(OBJF)/%.P)

all: | build test

build: $(TARGET)

clean:
	@cd $(CURDIR)
	rm -rf $(TARGET) $(TARGET_O3) $(OBJF) output/typing.ppm output/memoutput 

environment:
	@mkdir -p outputs	
	@mkdir -p $(OBJF)

help:
	@echo
	@echo "   make             builds $(TARGET)"
	@echo

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<


