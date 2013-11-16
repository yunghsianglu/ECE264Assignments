GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = utility.o pa09.o
HDRS = pa09.h
TARGET = pa09
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY: test clean environment test_ch01 test_ch02 test_ch03 test_ch04 test_ch05 test_ch06 test_bit01 test_bit02 test_bit03 test_bit04 test_bit05 test_bit06

pa09: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

test: | test_ch01 test_ch02 test_ch03 test_ch04 test_ch05 test_ch06 test_bit01 test_bit02 test_bit03 test_bit04 test_bit05 test_bit06

test_ch01: $(TARGET) | environment
	./$(TARGET) inputs/ch_header_inputs/testcase1_ch outputs/output_ch01
	diff expected/ch_expected/solution1 outputs/output_ch01
	$(VALGRIND) --log-file=outputs/memoutput_ch01 ./pa09 inputs/ch_header_inputs/testcase1_ch outputs/output_ch01 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput_ch01 

test_ch02: $(TARGET) | environment
	./$(TARGET) inputs/ch_header_inputs/testcase2_ch outputs/output_ch02
	diff expected/ch_expected/solution2 outputs/output_ch02
	$(VALGRIND) --log-file=outputs/memoutput_ch02 ./pa09 inputs/ch_header_inputs/testcase2_ch outputs/output_ch02 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput_ch02

test_ch03: $(TARGET) | environment
	./$(TARGET) inputs/ch_header_inputs/testcase3_ch outputs/output_ch03
	diff expected/ch_expected/solution3 outputs/output_ch03
	$(VALGRIND) --log-file=outputs/memoutput_ch03 ./pa09 inputs/ch_header_inputs/testcase3_ch outputs/output_ch03 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput_ch03

test_ch04: $(TARGET) | environment
	./$(TARGET) inputs/ch_header_inputs/testcase4_ch outputs/output_ch04
	diff expected/ch_expected/solution4 outputs/output_ch04
	$(VALGRIND) --log-file=outputs/memoutput_ch04 ./pa09 inputs/ch_header_inputs/testcase4_ch outputs/output_ch04 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput_ch04

test_ch05: $(TARGET) | environment
	./$(TARGET) inputs/ch_header_inputs/testcase5_ch outputs/output_ch05
	diff expected/ch_expected/solution5 outputs/output_ch05
	$(VALGRIND) --log-file=outputs/memoutput_ch05 ./pa09 inputs/ch_header_inputs/testcase5_ch outputs/output_ch05 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput_ch05

test_ch06: $(TARGET) | environment
	./$(TARGET) inputs/ch_header_inputs/testcase6_ch outputs/output_ch06
	diff expected/ch_expected/solution6 outputs/output_ch06
	$(VALGRIND) --log-file=outputs/memoutput_ch06 ./pa09 inputs/ch_header_inputs/testcase6_ch outputs/output_ch06 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput_ch06

test_bit01: $(TARGET) | environment
	./$(TARGET) inputs/bit_header_inputs/description_bit outputs/output_bit01
	diff expected/bit_expected/description_sol outputs/output_bit01
	$(VALGRIND) --log-file=outputs/memoutput_bit01 ./pa09 inputs/bit_header_inputs/description_bit outputs/output_bit01
	@bin/valgrind-checker.sh outputs/memoutput_bit01

test_bit02: $(TARGET) | environment
	./$(TARGET) inputs/bit_header_inputs/gophers_bit outputs/output_bit02
	diff expected/bit_expected/gophers_sol outputs/output_bit02
	$(VALGRIND) --log-file=outputs/memoutput_bit02 ./pa09 inputs/bit_header_inputs/gophers_bit outputs/output_bit02
	@bin/valgrind-checker.sh outputs/memoutput_bit02

test_bit03: $(TARGET) | environment
	./$(TARGET) inputs/bit_header_inputs/poetry1_bit outputs/output_bit03
	diff expected/bit_expected/poetry1_sol outputs/output_bit03
	$(VALGRIND) --log-file=outputs/memoutput_bit03 ./pa09 inputs/bit_header_inputs/poetry1_bit outputs/output_bit03
	@bin/valgrind-checker.sh outputs/memoutput_bit03

test_bit04: $(TARGET) | environment
	./$(TARGET) inputs/bit_header_inputs/poetry2_bit outputs/output_bit04
	diff expected/bit_expected/poetry2_sol outputs/output_bit04
	$(VALGRIND) --log-file=outputs/memoutput_bit04 ./pa09 inputs/bit_header_inputs/poetry2_bit outputs/output_bit04
	@bin/valgrind-checker.sh outputs/memoutput_bit04

test_bit05: $(TARGET) | environment
	./$(TARGET) inputs/bit_header_inputs/prefixcodes_bit outputs/output_bit05
	diff expected/bit_expected/prefixcodes_sol outputs/output_bit05
	$(VALGRIND) --log-file=outputs/memoutput_bit05 ./pa09 inputs/bit_header_inputs/prefixcodes_bit outputs/output_bit05
	@bin/valgrind-checker.sh outputs/memoutput_bit05

test_bit06: $(TARGET) | environment
	./$(TARGET) inputs/bit_header_inputs/stone_bit outputs/output_bit06
	diff expected/bit_expected/stone_sol outputs/output_bit06
	$(VALGRIND) --log-file=outputs/memoutput_bit06 ./pa09 inputs/bit_header_inputs/stone_bit outputs/output_bit06
	@bin/valgrind-checker.sh outputs/memoutput_bit06

test_bit07: $(TARGET) | environment
	./$(TARGET) inputs/bit_header_inputs/woods_bit outputs/output_bit07
	diff expected/bit_expected/woods_sol outputs/output_bit07
	$(VALGRIND) --log-file=outputs/memoutput_bit07 ./pa09 inputs/bit_header_inputs/woods_bit outputs/output_bit07
	@bin/valgrind-checker.sh outputs/memoutput_bit07

environment:
	@mkdir -p outputs

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -r $(TARGET) $(OBJS) outputs/*output* outputs/memoutput*
