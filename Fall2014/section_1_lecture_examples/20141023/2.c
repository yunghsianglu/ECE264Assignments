#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node *next;
	int value;
} Node;

Node* create_node(int value) {
	Node* new_node = malloc(sizeof(Node));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

Node* insert_at_0(Node* head, int value) {
	Node* new_node = create_node(value);
	new_node->next = head;
	return new_node;
}

int main(int argc, char *argv[]) {
	Node* head = create_node(11);
	head = insert_at_0(head, 0);
	return 0;
}
