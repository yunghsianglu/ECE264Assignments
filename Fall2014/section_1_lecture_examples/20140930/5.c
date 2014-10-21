#include <stdio.h>
#include <string.h>

// What does this do?

void swap_chars(char* l, char* r) {
	char temp = *l;
	*l = *r;
	*r = temp;
}
void f(char* s, int start_idx) {
	int i, len = strlen(s);
	if(start_idx == len - 1) {
		printf("%s\n", s);
	}
	else {
		for(i=start_idx; i < len; i++) {
			swap_chars(&s[start_idx], &s[i]);
			
			f(s, start_idx + 1); // RECURSIVE CALL

			swap_chars(&s[start_idx], &s[i]);
		}
	}
}
int main(int argc, char *argv[]) {
	char s[] = "ABCD";
	f(s, 0);
	return 0;
}
