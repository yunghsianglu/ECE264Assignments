GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer06.o pa06.o
HDRS = pa06.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa06: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

grade: pa06
	perl grader.pl 4 2 10

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa06 $(OBJS) outputs/*

test0: pa06
	@$(VALGRIND) --log-file=outputs/memoutput0 ./pa06 inputs/input01 outputs/output01ID outputs/output01Name
	@diff -w outputs/output01ID expected/expected01ID
	@diff -w outputs/output01Name expected/expected01Name

test1: pa06
	@$(VALGRIND) --log-file=outputs/memoutput1 ./pa06 inputs/input02 outputs/output02ID outputs/output02Name
	@diff -w outputs/output02ID expected/expected02ID
	@diff -w outputs/output02Name expected/expected02Name

test2: pa06
	@$(VALGRIND) --log-file=outputs/memoutput2 ./pa06 inputs/input03 outputs/output03ID outputs/output03Name
	@diff -w outputs/output03ID expected/expected03ID
	@diff -w outputs/output03Name expected/expected03Name

test3: pa06
	@$(VALGRIND) --log-file=outputs/memoutput3 ./pa06 inputs/input04 outputs/output04ID outputs/output04Name
	@diff -w outputs/output04ID expected/expected04ID
	@diff -w outputs/output04Name expected/expected04Name

test4: pa06
	@$(VALGRIND) --log-file=outputs/memoutput4 ./pa06 inputs/input05 outputs/output05ID outputs/output05Name
	@diff -w outputs/output05ID expected/expected05ID
	@diff -w outputs/output05Name expected/expected05Name

test5: pa06
	@$(VALGRIND) --log-file=outputs/memoutput5 ./pa06 inputs/input06 outputs/output06ID outputs/output06Name
	@diff -w outputs/output06ID expected/expected06ID
	@diff -w outputs/output06Name expected/expected06Name

test6: pa06
	@$(VALGRIND) --log-file=outputs/memoutput6 ./pa06 inputs/input07 outputs/output07ID outputs/output07Name
	@diff -w outputs/output07ID expected/expected07ID
	@diff -w outputs/output07Name expected/expected07Name

test7: pa06
	@$(VALGRIND) --log-file=outputs/memoutput7 ./pa06 inputs/input08 outputs/output08ID outputs/output08Name
	@diff -w outputs/output08ID expected/expected08ID
	@diff -w outputs/output08Name expected/expected08Name

test8: pa06
	@$(VALGRIND) --log-file=outputs/memoutput8 ./pa06 inputs/input09 outputs/output09ID outputs/output09Name
	@diff -w outputs/output09ID expected/expected09ID
	@diff -w outputs/output09Name expected/expected09Name

test9: pa06
	@$(VALGRIND) --log-file=outputs/memoutput9 ./pa06 inputs/input10 outputs/output10ID outputs/output10Name
	@diff -w outputs/output10ID expected/expected10ID
	@diff -w outputs/output10Name expected/expected10Name




