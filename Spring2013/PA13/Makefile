GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = pa13.o subsetSum.o
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes

pa13: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@ -lpthread -lm

grade: pa13
	perl grader.pl 4 2 27

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o pa13 outputs/*

generate: pa13
	./pa13 inputs/input1_set inputs/input1_num expected/expected1 3 > expected/exptime0
	./pa13 inputs/input2_set inputs/input2_num expected/expected2 3 > expected/exptime1
	./pa13 inputs/input3_set inputs/input3_num expected/expected3 3 > expected/exptime2
	./pa13 inputs/input4_set inputs/input4_num expected/expected4 4 > expected/exptime3
	./pa13 inputs/input5_set inputs/input5_num expected/expected5 5 > expected/exptime4
	./pa13 inputs/input6_set inputs/input6_num expected/expected6 6 > expected/exptime5
	./pa13 inputs/input7_set inputs/input7_num expected/expected7 7 > expected/exptime6
	./pa13 inputs/input8_set inputs/input8_num expected/expected8 8 > expected/exptime7
	./pa13 inputs/input9_set inputs/input9_num expected/expected9 9 > expected/exptime8
	./pa13 inputs/input10_set inputs/input10_num expected/expected10 4 > expected/exptime9
	./pa13 inputs/input11_set inputs/input11_num expected/expected11 1 > expected/exptime10
	./pa13 inputs/input12_set inputs/input12_num expected/expected12 2 > expected/exptime11
	./pa13 inputs/input13_set inputs/input13_num expected/expected13 3 > expected/exptime12
	./pa13 inputs/input14_set inputs/input14_num expected/expected14 4 > expected/exptime13
	./pa13 inputs/input15_set inputs/input15_num expected/expected15 5 > expected/exptime14
	./pa13 inputs/input16_set inputs/input16_num expected/expected16 6 > expected/exptime15
	./pa13 inputs/input17_set inputs/input17_num expected/expected17 7 > expected/exptime16
	./pa13 inputs/input18_set inputs/input18_num expected/expected18 8 > expected/exptime17
	./pa13 inputs/input19_set inputs/input19_num expected/expected19 9 > expected/exptime18
	./pa13 inputs/input20_set inputs/input20_num expected/expected20 10 > expected/exptime19
	./pa13 inputs/input21_set inputs/input21_num expected/expected21 4 > expected/exptime20
	./pa13 inputs/input22_set inputs/input22_num expected/expected22 4 > expected/exptime21
	./pa13 inputs/input23_set inputs/input23_num expected/expected23 4 > expected/exptime22
	./pa13 inputs/input24_set inputs/input24_num expected/expected24 4 > expected/exptime23
	./pa13 inputs/input25_set inputs/input25_num expected/expected25 5 > expected/exptime24
	./pa13 inputs/input26_set inputs/input26_num expected/expected26 6 > expected/exptime25
	./pa13 inputs/input27_set inputs/input27_num expected/expected27 7 > expected/exptime26

corrtest0: pa13
	$(VALGRIND) --log-file=outputs/memoutput0 ./pa13 inputs/input1_set inputs/input1_num outputs/output1 3 > /dev/null
	diff expected/expected1 outputs/output1

perftest0: pa13
	./pa13 inputs/input1_set inputs/input1_num /dev/null 3 > outputs/timeinfo0

corrtest1: pa13
	$(VALGRIND) --log-file=outputs/memoutput1 ./pa13 inputs/input2_set inputs/input2_num outputs/output2 3 > /dev/null
	diff expected/expected2 outputs/output2

perftest1: pa13
	./pa13 inputs/input2_set inputs/input2_num /dev/null 3 > outputs/timeinfo1

corrtest2: pa13
	$(VALGRIND) --log-file=outputs/memoutput2 ./pa13 inputs/input3_set inputs/input3_num outputs/output3 3 > /dev/null
	diff expected/expected3 outputs/output3

perftest2: pa13
	./pa13 inputs/input3_set inputs/input3_num /dev/null 3 > outputs/timeinfo2

corrtest3: pa13
	$(VALGRIND) --log-file=outputs/memoutput3 ./pa13 inputs/input4_set inputs/input4_num outputs/output4 4 > /dev/null
	diff expected/expected4 outputs/output4

perftest3: pa13
	./pa13 inputs/input4_set inputs/input4_num /dev/null 4 > outputs/timeinfo3

corrtest4: pa13
	$(VALGRIND) --log-file=outputs/memoutput4 ./pa13 inputs/input5_set inputs/input5_num outputs/output5 5 > /dev/null
	diff expected/expected5 outputs/output5

perftest4: pa13
	./pa13 inputs/input5_set inputs/input5_num /dev/null 5 > outputs/timeinfo4

corrtest5: pa13
	$(VALGRIND) --log-file=outputs/memoutput5 ./pa13 inputs/input6_set inputs/input6_num outputs/output6 6 > /dev/null
	diff expected/expected6 outputs/output6

perftest5: pa13
	./pa13 inputs/input6_set inputs/input6_num /dev/null 6 > outputs/timeinfo5

corrtest6: pa13
	$(VALGRIND) --log-file=outputs/memoutput6 ./pa13 inputs/input7_set inputs/input7_num outputs/output7 7 > /dev/null
	diff expected/expected7 outputs/output7

perftest6: pa13
	./pa13 inputs/input7_set inputs/input7_num /dev/null 7 > outputs/timeinfo6

corrtest7: pa13
	$(VALGRIND) --log-file=outputs/memoutput7 ./pa13 inputs/input8_set inputs/input8_num outputs/output8 8 > /dev/null
	diff expected/expected8 outputs/output8

perftest7: pa13
	./pa13 inputs/input8_set inputs/input8_num /dev/null 8 > outputs/timeinfo7

corrtest8: pa13
	$(VALGRIND) --log-file=outputs/memoutput8 ./pa13 inputs/input9_set inputs/input9_num outputs/output9 9 > /dev/null
	diff expected/expected9 outputs/output9

perftest8: pa13
	./pa13 inputs/input9_set inputs/input9_num /dev/null 9 > outputs/timeinfo8

corrtest9: pa13
	$(VALGRIND) --log-file=outputs/memoutput9 ./pa13 inputs/input10_set inputs/input10_num outputs/output10 4 > /dev/null
	diff expected/expected10 outputs/output10

perftest9: pa13
	./pa13 inputs/input10_set inputs/input10_num /dev/null 4 > outputs/timeinfo9

corrtest10: pa13
	$(VALGRIND) --log-file=outputs/memoutput10 ./pa13 inputs/input11_set inputs/input11_num outputs/output11 1 > /dev/null
	diff expected/expected11 outputs/output11

perftest10: pa13
	./pa13 inputs/input11_set inputs/input11_num /dev/null 1 > outputs/timeinfo10

corrtest11: pa13
	$(VALGRIND) --log-file=outputs/memoutput11 ./pa13 inputs/input12_set inputs/input12_num outputs/output12 2 > /dev/null
	diff expected/expected12 outputs/output12

perftest11: pa13
	./pa13 inputs/input12_set inputs/input12_num /dev/null 2 > outputs/timeinfo11

corrtest12: pa13
	$(VALGRIND) --log-file=outputs/memoutput12 ./pa13 inputs/input13_set inputs/input13_num outputs/output13 3 > /dev/null
	diff expected/expected13 outputs/output13

perftest12: pa13
	./pa13 inputs/input13_set inputs/input13_num /dev/null 3 > outputs/timeinfo12

corrtest13: pa13
	$(VALGRIND) --log-file=outputs/memoutput13 ./pa13 inputs/input14_set inputs/input14_num outputs/output14 4 > /dev/null
	diff expected/expected14 outputs/output14

perftest13: pa13
	./pa13 inputs/input14_set inputs/input14_num /dev/null 4 > outputs/timeinfo13

corrtest14: pa13
	$(VALGRIND) --log-file=outputs/memoutput14 ./pa13 inputs/input15_set inputs/input15_num outputs/output15 5 > /dev/null
	diff expected/expected15 outputs/output15

perftest14: pa13
	./pa13 inputs/input15_set inputs/input15_num /dev/null 5 > outputs/timeinfo14

corrtest15: pa13
	$(VALGRIND) --log-file=outputs/memoutput15 ./pa13 inputs/input16_set inputs/input16_num outputs/output16 6 > /dev/null
	diff expected/expected16 outputs/output16

perftest15: pa13
	./pa13 inputs/input16_set inputs/input16_num /dev/null 6 > outputs/timeinfo15

corrtest16: pa13
	$(VALGRIND) --log-file=outputs/memoutput16 ./pa13 inputs/input17_set inputs/input17_num outputs/output17 7 > /dev/null
	diff expected/expected17 outputs/output17

perftest16: pa13
	./pa13 inputs/input17_set inputs/input17_num /dev/null 7 > outputs/timeinfo16

corrtest17: pa13
	$(VALGRIND) --log-file=outputs/memoutput17 ./pa13 inputs/input18_set inputs/input18_num outputs/output18 8 > /dev/null
	diff expected/expected18 outputs/output18

perftest17: pa13
	./pa13 inputs/input18_set inputs/input18_num /dev/null 8 > outputs/timeinfo17

corrtest18: pa13
	$(VALGRIND) --log-file=outputs/memoutput18 ./pa13 inputs/input19_set inputs/input19_num outputs/output19 9 > /dev/null
	diff expected/expected19 outputs/output19

perftest18: pa13
	./pa13 inputs/input19_set inputs/input19_num /dev/null 9 > outputs/timeinfo18

corrtest19: pa13
	$(VALGRIND) --log-file=outputs/memoutput19 ./pa13 inputs/input20_set inputs/input20_num outputs/output20 10 > /dev/null
	diff expected/expected20 outputs/output20

perftest19: pa13
	./pa13 inputs/input20_set inputs/input20_num /dev/null 10 > outputs/timeinfo19

corrtest20: pa13
	$(VALGRIND) --log-file=outputs/memoutput20 ./pa13 inputs/input21_set inputs/input21_num outputs/output21 4 > /dev/null
	diff expected/expected21 outputs/output21

perftest20: pa13
	./pa13 inputs/input21_set inputs/input21_num /dev/null 4 > outputs/timeinfo20

corrtest21: pa13
	$(VALGRIND) --log-file=outputs/memoutput21 ./pa13 inputs/input22_set inputs/input22_num outputs/output22 4 > /dev/null
	diff expected/expected22 outputs/output22

perftest21: pa13
	./pa13 inputs/input22_set inputs/input22_num /dev/null 4 > outputs/timeinfo21

corrtest22: pa13
	$(VALGRIND) --log-file=outputs/memoutput22 ./pa13 inputs/input23_set inputs/input23_num outputs/output23 4 > /dev/null
	diff expected/expected23 outputs/output23

perftest22: pa13
	./pa13 inputs/input23_set inputs/input23_num /dev/null 4 > outputs/timeinfo22

corrtest23: pa13
	$(VALGRIND) --log-file=outputs/memoutput23 ./pa13 inputs/input24_set inputs/input24_num outputs/output24 4 > /dev/null
	diff expected/expected24 outputs/output24

perftest23: pa13
	./pa13 inputs/input24_set inputs/input24_num /dev/null 4 > outputs/timeinfo23

corrtest24: pa13
	$(VALGRIND) --log-file=outputs/memoutput24 ./pa13 inputs/input25_set inputs/input25_num outputs/output25 5 > /dev/null
	diff expected/expected25 outputs/output25

perftest24: pa13
	./pa13 inputs/input25_set inputs/input25_num /dev/null 5 > outputs/timeinfo24

corrtest25: pa13
	$(VALGRIND) --log-file=outputs/memoutput25 ./pa13 inputs/input26_set inputs/input26_num outputs/output26 6 > /dev/null
	diff expected/expected26 outputs/output26

perftest25: pa13
	./pa13 inputs/input26_set inputs/input26_num /dev/null 6 > outputs/timeinfo25

corrtest26: pa13
	$(VALGRIND) --log-file=outputs/memoutput26 ./pa13 inputs/input27_set inputs/input27_num outputs/output27 7 > /dev/null
	diff expected/expected27 outputs/output27

perftest26: pa13
	./pa13 inputs/input27_set inputs/input27_num /dev/null 7 > outputs/timeinfo26
