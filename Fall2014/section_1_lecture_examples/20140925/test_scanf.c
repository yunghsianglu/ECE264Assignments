#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	FILE* fp = fopen("test_scanf.txt", "r");
	char s[20000];
	int n;
	fscanf(fp, "%d %s", &n, s);
	fclose(fp);
	printf("n == %d\n\n", n);
	printf("s == \"%s\"\n\n", s);
	return 0;
}
