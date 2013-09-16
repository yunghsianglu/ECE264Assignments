
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS =
SOURCES = answer04.c pa04.c
TARGET = pa04
TESTN := $(shell seq 1 9)
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

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
	@echo "make             build $(TARGET)"
	@echo "make testall     run all testcases"
	@echo "make clean       start from scratch"
	@echo
	@echo "make test1	test on partition all"
	@echo "make test2	test on partition increasing"
	@echo "make test3	test on partition decreasing"
	@echo "make test4	test on partition with odd number only"
	@echo "make test5	test on partition with even number only"
	@echo "make test6	small test case on partition with alternate odd and even number"
	@echo "make test7	large test case on partition with alternate odd and even number"
	@echo "make test8	small test case on partition with prime number only"
	@echo "make test9	large test case on partition with prime number only"

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<

${TESTS}: test%: $(TARGET) | environment
	@echo '***************************************'
	@echo "test$*"
	@echo '***************************************'
	./$(TARGET) inputs/input0$* > outputs/output$*
	cat outputs/output$* | sort | diff expected/output-sorted$* -
	$(VALGRIND) --log-file=outputs/memoutput$* ./$(TARGET) inputs/input0$* > /dev/null
	@echo
	@bin/valgrind-checker.sh outputs/memoutput$*
	@echo 

testz01: $(TARGET) | environment
	./$(TARGET) inputs/input01 > outputs/output1
	diff expected/output1 outputs/output1
	$(VALGRIND) --log-file=outputs/memoutput1 ./$(TARGET) inputs/input01 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput1
