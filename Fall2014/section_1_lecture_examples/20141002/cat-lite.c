#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	char help_msg[] = 
	"Usage: cat-lite [--help] [FILE]...\n"
	"With no FILE, or when FILE is -, read standard input.\n"
	"\n"
	"Examples:\n"
	"  cat-lite README   Print the file README to standard output.\n"
	"  cat-lite f - g    Print f's contents, then standard input, \n"
	"                    then g's contents.\n"
	"  cat-lite          Copy standard input to standard output.\n";
	printf("%s\n", help_msg);


	return 0;
}
