GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = student.o pa08.o
HDRS = student.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa08: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

grade:
	perl grader.pl 4 1 10

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa08 $(OBJS) outputs/*

test0: pa08
	@$(VALGRIND) --log-file=outputs/memoutput0 ./pa08 inputs/input01 outputs/output01ID outputs/output01Name
	@diff -w outputs/output01ID expected/expected01ID
	@diff -w outputs/output01Name expected/expected01Name

test1: pa08
	@$(VALGRIND) --log-file=outputs/memoutput1 ./pa08 inputs/input02 outputs/output02ID outputs/output02Name
	@diff -w outputs/output02ID expected/expected02ID
	@diff -w outputs/output02Name expected/expected02Name

test2: pa08
	@$(VALGRIND) --log-file=outputs/memoutput2 ./pa08 inputs/input03 outputs/output03ID outputs/output03Name
	@diff -w outputs/output03ID expected/expected03ID
	@diff -w outputs/output03Name expected/expected03Name

test3: pa08
	@$(VALGRIND) --log-file=outputs/memoutput3 ./pa08 inputs/input04 outputs/output04ID outputs/output04Name
	@diff -w outputs/output04ID expected/expected04ID
	@diff -w outputs/output04Name expected/expected04Name

test4: pa08
	@$(VALGRIND) --log-file=outputs/memoutput4 ./pa08 inputs/input05 outputs/output05ID outputs/output05Name
	@diff -w outputs/output05ID expected/expected05ID
	@diff -w outputs/output05Name expected/expected05Name

test5: pa08
	@$(VALGRIND) --log-file=outputs/memoutput5 ./pa08 inputs/input08 outputs/output08ID outputs/output08Name
	@diff -w outputs/output08ID expected/expected08ID
	@diff -w outputs/output08Name expected/expected08Name

test6: pa08
	@$(VALGRIND) --log-file=outputs/memoutput6 ./pa08 inputs/input07 outputs/output07ID outputs/output07Name
	@diff -w outputs/output07ID expected/expected07ID
	@diff -w outputs/output07Name expected/expected07Name

test7: pa08
	@$(VALGRIND) --log-file=outputs/memoutput7 ./pa08 inputs/input08 outputs/output08ID outputs/output08Name
	@diff -w outputs/output08ID expected/expected08ID
	@diff -w outputs/output08Name expected/expected08Name

test8: pa08
	@$(VALGRIND) --log-file=outputs/memoutput8 ./pa08 inputs/input09 outputs/output09ID outputs/output09Name
	@diff -w outputs/output09ID expected/expected09ID
	@diff -w outputs/output09Name expected/expected09Name

test9: pa08
	@$(VALGRIND) --log-file=outputs/memoutput9 ./pa08 inputs/input10 outputs/output10ID outputs/output10Name
	@diff -w outputs/output10ID expected/expected10ID
	@diff -w outputs/output10Name expected/expected10Name

test10: pa08
	@$(VALGRIND) --log-file=outputs/memoutput10 ./pa08 inputs/input11 outputs/output11ID outputs/output11Name
	@diff -w outputs/output11ID expected/expected11ID
	@diff -w outputs/output11Name expected/expected11Name

test11: pa08
	@$(VALGRIND) --log-file=outputs/memoutput11 ./pa08 inputs/input12 outputs/output12ID outputs/output12Name

test12: pa08
	@touch outputs/output13ID
	@touch outputs/output13Name
	@chmod 444 outputs/output13ID
	@chmod 444 outputs/output13Name
	@$(VALGRIND) --log-file=outputs/memoutput12 ./pa08 inputs/input01 outputs/output13ID outputs/output13Name
	@rm outputs/output13ID
	@rm outputs/output13Name



