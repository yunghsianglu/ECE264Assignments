GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer04.o pa04.o
HDRS = pa04.h

pa04: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	perl grader.pl 4 2 4 10 8

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

test0: pa04
	./pa04 c inputs/input_article0 outputs/output_c0
	diff -w outputs/output_c0 expected/expected_c0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput0 ./pa04 c inputs/input_article0 outputs/output_c0
	
test1: pa04
	./pa04 c inputs/input_article1 outputs/output_c1
	diff -w outputs/output_c1 expected/expected_c1
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput1 ./pa04 c inputs/input_article1 outputs/output_c1
	
test2: pa04
	./pa04 c inputs/input_article2 outputs/output_c2
	diff -w outputs/output_c2 expected/expected_c2
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput2 ./pa04 c inputs/input_article2 outputs/output_c2
	
test3: pa04
	./pa04 c inputs/input_article3 outputs/output_c3
	diff -w outputs/output_c3 expected/expected_c3
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput3 ./pa04 c inputs/input_article3 outputs/output_c3

test4: pa04
	./pa04 s inputs/input_article0 outputs/output_str00 Aa
	diff -w  outputs/output_str00 expected/expected_str00
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput4 ./pa04 s inputs/input_article0 outputs/output_str00 Aa

test5: pa04
	./pa04 s inputs/input_article0 outputs/output_str01 bB
	diff -w  outputs/output_str01 expected/expected_str01
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput5 ./pa04 s inputs/input_article0 outputs/output_str01 bB
	
test6: pa04
	./pa04 s inputs/input_article1 outputs/output_str10 Elec
	diff -w  outputs/output_str10 expected/expected_str10
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput6 ./pa04 s inputs/input_article1 outputs/output_str10 Elec

test7: pa04
	./pa04 s inputs/input_article1 outputs/output_str11 eng
	diff -w  outputs/output_str11 expected/expected_str11
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput7 ./pa04 s inputs/input_article1 outputs/output_str11 eng

test8: pa04
	./pa04 s inputs/input_article1 outputs/output_str12 ing
	diff -w  outputs/output_str12 expected/expected_str12
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput8 ./pa04 s inputs/input_article1 outputs/output_str12 ing

test9: pa04
	./pa04 s inputs/input_article1 outputs/output_str13 USA
	diff -w  outputs/output_str13 expected/expected_str13
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput9 ./pa04 s inputs/input_article1 outputs/output_str13 USA

test10: pa04
	./pa04 s inputs/input_article2 outputs/output_str20 ing
	diff -w  outputs/output_str20 expected/expected_str20
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput10 ./pa04 s inputs/input_article2 outputs/output_str20 ing

test11: pa04
	./pa04 s inputs/input_article2 outputs/output_str21 circuit
	diff -w  outputs/output_str21 expected/expected_str21
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput11 ./pa04 s inputs/input_article2 outputs/output_str21 circuit

test12: pa04
	./pa04 s inputs/input_article3 outputs/output_str30 computer
	diff -w  outputs/output_str30 expected/expected_str30
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput12 ./pa04 s inputs/input_article3 outputs/output_str30 copmuter

test13: pa04
	./pa04 s inputs/input_article3 outputs/output_str31 int
	diff -w  outputs/output_str31 expected/expected_str31
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput13 ./pa04 s inputs/input_article3 outputs/output_str31 int

test14: pa04
	./pa04 p inputs/input_pal0 outputs/output_pal0
	diff -w  outputs/output_pal0 expected/expected_pal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput14 ./pa04 p inputs/input_pal0 outputs/output_pal0

test15: pa04
	./pa04 p inputs/input_pal1 outputs/output_pal1
	diff -w  outputs/output_pal1 expected/expected_pal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput15 ./pa04 p inputs/input_pal1 outputs/output_pal1

test16: pa04
	./pa04 p inputs/input_pal2 outputs/output_pal2
	diff -w  outputs/output_pal2 expected/expected_pal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput16 ./pa04 p inputs/input_pal2 outputs/output_pal2

test17: pa04
	./pa04 p inputs/input_pal3 outputs/output_pal3
	diff -w  outputs/output_pal3 expected/expected_pal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput17 ./pa04 p inputs/input_pal2 outputs/output_pal3

test18: pa04
	./pa04 p inputs/input_nonpal0 outputs/output_nonpal0
	diff -w  outputs/output_nonpal0 expected/expected_nonpal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput18 ./pa04 p inputs/input_nonpal0 outputs/output_nonpal0

test19: pa04
	./pa04 p inputs/input_nonpal1 outputs/output_nonpal1
	diff -w  outputs/output_nonpal1 expected/expected_nonpal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput19 ./pa04 p inputs/input_nonpal1 outputs/output_nonpal1

test20: pa04
	./pa04 p inputs/input_nonpal2 outputs/output_nonpal2
	diff -w  outputs/output_nonpal2 expected/expected_nonpal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput20 ./pa04 p inputs/input_nonpal2 outputs/output_nonpal2
	
test21: pa04
	./pa04 p inputs/input_nonpal3 outputs/output_nonpal3
	diff -w  outputs/output_nonpal3 expected/expected_nonpal0
	valgrind --leak-check=full --verbose --log-file=outputs/memoutput21 ./pa04 p inputs/input_nonpal3 outputs/output_nonpal3

clean:
	rm -f pa04 $(OBJS) outputs/*





