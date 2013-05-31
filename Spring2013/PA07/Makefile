GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = pa07.o bmp.o
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa07: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o pa07 outputs/*


grade:
	perl grader.pl 4 2 8

test0: pa07
	@$(VALGRIND) --log-file=outputs/memoutput0 ./pa07 inputs/car.bmp outputs/car.bmp
	@diff outputs/car.bmp expected/car.bmp

test1: pa07
	@$(VALGRIND) --log-file=outputs/memoutput1 ./pa07 inputs/airplane.bmp outputs/airplane.bmp
	@diff outputs/airplane.bmp expected/airplane.bmp

test2: pa07
	@$(VALGRIND) --log-file=outputs/memoutput2 ./pa07 inputs/purduetrain.bmp outputs/purduetrain.bmp
	@diff outputs/purduetrain.bmp expected/purduetrain.bmp

test3: pa07
	@$(VALGRIND) --log-file=outputs/memoutput3 ./pa07 inputs/wizard.bmp outputs/wizard.bmp
	@diff outputs/wizard.bmp expected/wizard.bmp

test4: pa07
	@$(VALGRIND) --log-file=outputs/memoutput4 ./pa07 inputs/blue_rose.bmp outputs/blue_rose.bmp
	@diff outputs/blue_rose.bmp expected/blue_rose.bmp

test5: pa07
	@$(VALGRIND) --log-file=outputs/memoutput5 ./pa07 inputs/checkerboard.bmp outputs/checkerboard.bmp
	@diff outputs/checkerboard.bmp expected/checkerboard.bmp

test6: pa07
	@$(VALGRIND) --log-file=outputs/memoutput6 ./pa07 inputs/green_earth.bmp outputs/green_earth.bmp
	@diff outputs/green_earth.bmp expected/green_earth.bmp

test7: pa07
	@$(VALGRIND) --log-file=outputs/memoutput7 ./pa07 inputs/red_pirate.bmp outputs/red_pirate.bmp
	@diff outputs/red_pirate.bmp expected/red_pirate.bmp
