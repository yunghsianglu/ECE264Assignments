#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


typedef struct Item {
    int a;
    float b;
    char* name;
} Item;

int main(void) {
    Item item = { 5, 2.2, "George" };
    return 0;
}
