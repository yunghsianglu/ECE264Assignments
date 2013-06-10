GCC = gcc
CFLAGS = -g -Wall -Wshadow
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

TARGET= intgen filter strgen

TARGET: intgen filter strgen

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(TARGET)






