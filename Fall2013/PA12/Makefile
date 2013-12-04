GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = pa12.o subsetSum.o
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes

pa12: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@ -lpthread -lm
	mkdir -p outputs

testall: pa12
	perl grader.pl 4 2 27

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o pa12 outputs/*

test0: pa12
	perl grader.pl 4 1 0
test1: pa12
	perl grader.pl 4 1 1
test2: pa12
	perl grader.pl 4 1 2
test3: pa12
	perl grader.pl 4 1 3
test4: pa12
	perl grader.pl 4 1 4
test5: pa12
	perl grader.pl 4 1 5
test6: pa12
	perl grader.pl 4 1 6
test7: pa12
	perl grader.pl 4 1 7
test8: pa12
	perl grader.pl 4 1 8
test9: pa12
	perl grader.pl 4 1 9
test10: pa12
	perl grader.pl 4 1 10
test11: pa12
	perl grader.pl 4 1 11
test12: pa12
	perl grader.pl 4 1 12
test13: pa12
	perl grader.pl 4 1 13
test14: pa12
	perl grader.pl 4 1 14
test15: pa12
	perl grader.pl 4 1 15
test16: pa12
	perl grader.pl 4 1 16
test17: pa12
	perl grader.pl 4 1 17
test18: pa12
	perl grader.pl 4 1 18
test19: pa12
	perl grader.pl 4 1 19
test20: pa12
	perl grader.pl 4 1 20
test21: pa12
	perl grader.pl 4 1 21
test22: pa12
	perl grader.pl 4 1 22
test23: pa12
	perl grader.pl 4 1 23
test24: pa12
	perl grader.pl 4 1 24
test25: pa12
	perl grader.pl 4 1 25
test26: pa12
	perl grader.pl 4 1 26

corrtest0: pa12
	$(VALGRIND) --log-file=outputs/memoutput0 ./pa12 inputs/input1_set inputs/input1_num outputs/output1 3 > /dev/null
	diff expected/expected1 outputs/output1

perftest0: pa12
	./pa12 inputs/input1_set inputs/input1_num /dev/null 3 > outputs/timeinfo0

corrtest1: pa12
	$(VALGRIND) --log-file=outputs/memoutput1 ./pa12 inputs/input2_set inputs/input2_num outputs/output2 3 > /dev/null
	diff expected/expected2 outputs/output2

perftest1: pa12
	./pa12 inputs/input2_set inputs/input2_num /dev/null 3 > outputs/timeinfo1

corrtest2: pa12
	$(VALGRIND) --log-file=outputs/memoutput2 ./pa12 inputs/input3_set inputs/input3_num outputs/output3 3 > /dev/null
	diff expected/expected3 outputs/output3

perftest2: pa12
	./pa12 inputs/input3_set inputs/input3_num /dev/null 3 > outputs/timeinfo2

corrtest3: pa12
	$(VALGRIND) --log-file=outputs/memoutput3 ./pa12 inputs/input4_set inputs/input4_num outputs/output4 4 > /dev/null
	diff expected/expected4 outputs/output4

perftest3: pa12
	./pa12 inputs/input4_set inputs/input4_num /dev/null 4 > outputs/timeinfo3

corrtest4: pa12
	$(VALGRIND) --log-file=outputs/memoutput4 ./pa12 inputs/input5_set inputs/input5_num outputs/output5 5 > /dev/null
	diff expected/expected5 outputs/output5

perftest4: pa12
	./pa12 inputs/input5_set inputs/input5_num /dev/null 5 > outputs/timeinfo4

corrtest5: pa12
	$(VALGRIND) --log-file=outputs/memoutput5 ./pa12 inputs/input6_set inputs/input6_num outputs/output6 6 > /dev/null
	diff expected/expected6 outputs/output6

perftest5: pa12
	./pa12 inputs/input6_set inputs/input6_num /dev/null 6 > outputs/timeinfo5

corrtest6: pa12
	$(VALGRIND) --log-file=outputs/memoutput6 ./pa12 inputs/input7_set inputs/input7_num outputs/output7 7 > /dev/null
	diff expected/expected7 outputs/output7

perftest6: pa12
	./pa12 inputs/input7_set inputs/input7_num /dev/null 7 > outputs/timeinfo6

corrtest7: pa12
	$(VALGRIND) --log-file=outputs/memoutput7 ./pa12 inputs/input8_set inputs/input8_num outputs/output8 8 > /dev/null
	diff expected/expected8 outputs/output8

perftest7: pa12
	./pa12 inputs/input8_set inputs/input8_num /dev/null 8 > outputs/timeinfo7

corrtest8: pa12
	$(VALGRIND) --log-file=outputs/memoutput8 ./pa12 inputs/input9_set inputs/input9_num outputs/output9 9 > /dev/null
	diff expected/expected9 outputs/output9

perftest8: pa12
	./pa12 inputs/input9_set inputs/input9_num /dev/null 9 > outputs/timeinfo8

corrtest9: pa12
	$(VALGRIND) --log-file=outputs/memoutput9 ./pa12 inputs/input10_set inputs/input10_num outputs/output10 4 > /dev/null
	diff expected/expected10 outputs/output10

perftest9: pa12
	./pa12 inputs/input10_set inputs/input10_num /dev/null 4 > outputs/timeinfo9

corrtest10: pa12
	$(VALGRIND) --log-file=outputs/memoutput10 ./pa12 inputs/input11_set inputs/input11_num outputs/output11 1 > /dev/null
	diff expected/expected11 outputs/output11

perftest10: pa12
	./pa12 inputs/input11_set inputs/input11_num /dev/null 1 > outputs/timeinfo10

corrtest11: pa12
	$(VALGRIND) --log-file=outputs/memoutput11 ./pa12 inputs/input12_set inputs/input12_num outputs/output12 2 > /dev/null
	diff expected/expected12 outputs/output12

perftest11: pa12
	./pa12 inputs/input12_set inputs/input12_num /dev/null 2 > outputs/timeinfo11

corrtest12: pa12
	$(VALGRIND) --log-file=outputs/memoutput12 ./pa12 inputs/input13_set inputs/input13_num outputs/output13 3 > /dev/null
	diff expected/expected13 outputs/output13

perftest12: pa12
	./pa12 inputs/input13_set inputs/input13_num /dev/null 3 > outputs/timeinfo12

corrtest13: pa12
	$(VALGRIND) --log-file=outputs/memoutput13 ./pa12 inputs/input14_set inputs/input14_num outputs/output14 4 > /dev/null
	diff expected/expected14 outputs/output14

perftest13: pa12
	./pa12 inputs/input14_set inputs/input14_num /dev/null 4 > outputs/timeinfo13

corrtest14: pa12
	$(VALGRIND) --log-file=outputs/memoutput14 ./pa12 inputs/input15_set inputs/input15_num outputs/output15 5 > /dev/null
	diff expected/expected15 outputs/output15

perftest14: pa12
	./pa12 inputs/input15_set inputs/input15_num /dev/null 5 > outputs/timeinfo14

corrtest15: pa12
	$(VALGRIND) --log-file=outputs/memoutput15 ./pa12 inputs/input16_set inputs/input16_num outputs/output16 6 > /dev/null
	diff expected/expected16 outputs/output16

perftest15: pa12
	./pa12 inputs/input16_set inputs/input16_num /dev/null 6 > outputs/timeinfo15

corrtest16: pa12
	$(VALGRIND) --log-file=outputs/memoutput16 ./pa12 inputs/input17_set inputs/input17_num outputs/output17 7 > /dev/null
	diff expected/expected17 outputs/output17

perftest16: pa12
	./pa12 inputs/input17_set inputs/input17_num /dev/null 7 > outputs/timeinfo16

corrtest17: pa12
	$(VALGRIND) --log-file=outputs/memoutput17 ./pa12 inputs/input18_set inputs/input18_num outputs/output18 8 > /dev/null
	diff expected/expected18 outputs/output18

perftest17: pa12
	./pa12 inputs/input18_set inputs/input18_num /dev/null 8 > outputs/timeinfo17

corrtest18: pa12
	$(VALGRIND) --log-file=outputs/memoutput18 ./pa12 inputs/input19_set inputs/input19_num outputs/output19 9 > /dev/null
	diff expected/expected19 outputs/output19

perftest18: pa12
	./pa12 inputs/input19_set inputs/input19_num /dev/null 9 > outputs/timeinfo18

corrtest19: pa12
	$(VALGRIND) --log-file=outputs/memoutput19 ./pa12 inputs/input20_set inputs/input20_num outputs/output20 10 > /dev/null
	diff expected/expected20 outputs/output20

perftest19: pa12
	./pa12 inputs/input20_set inputs/input20_num /dev/null 10 > outputs/timeinfo19

corrtest20: pa12
	$(VALGRIND) --log-file=outputs/memoutput20 ./pa12 inputs/input21_set inputs/input21_num outputs/output21 4 > /dev/null
	diff expected/expected21 outputs/output21

perftest20: pa12
	./pa12 inputs/input21_set inputs/input21_num /dev/null 4 > outputs/timeinfo20

corrtest21: pa12
	$(VALGRIND) --log-file=outputs/memoutput21 ./pa12 inputs/input22_set inputs/input22_num outputs/output22 4 > /dev/null
	diff expected/expected22 outputs/output22

perftest21: pa12
	./pa12 inputs/input22_set inputs/input22_num /dev/null 4 > outputs/timeinfo21

corrtest22: pa12
	$(VALGRIND) --log-file=outputs/memoutput22 ./pa12 inputs/input23_set inputs/input23_num outputs/output23 4 > /dev/null
	diff expected/expected23 outputs/output23

perftest22: pa12
	./pa12 inputs/input23_set inputs/input23_num /dev/null 4 > outputs/timeinfo22

corrtest23: pa12
	$(VALGRIND) --log-file=outputs/memoutput23 ./pa12 inputs/input24_set inputs/input24_num outputs/output24 4 > /dev/null
	diff expected/expected24 outputs/output24

perftest23: pa12
	./pa12 inputs/input24_set inputs/input24_num /dev/null 4 > outputs/timeinfo23

corrtest24: pa12
	$(VALGRIND) --log-file=outputs/memoutput24 ./pa12 inputs/input25_set inputs/input25_num outputs/output25 5 > /dev/null
	diff expected/expected25 outputs/output25

perftest24: pa12
	./pa12 inputs/input25_set inputs/input25_num /dev/null 5 > outputs/timeinfo24

corrtest25: pa12
	$(VALGRIND) --log-file=outputs/memoutput25 ./pa12 inputs/input26_set inputs/input26_num outputs/output26 6 > /dev/null
	diff expected/expected26 outputs/output26

perftest25: pa12
	./pa12 inputs/input26_set inputs/input26_num /dev/null 6 > outputs/timeinfo25

corrtest26: pa12
	$(VALGRIND) --log-file=outputs/memoutput26 ./pa12 inputs/input27_set inputs/input27_num outputs/output27 7 > /dev/null
	diff expected/expected27 outputs/output27

perftest26: pa12
	./pa12 inputs/input27_set inputs/input27_num /dev/null 7 > outputs/timeinfo26
