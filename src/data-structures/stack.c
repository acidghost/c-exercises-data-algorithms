#include <stdio.h>

#define MAX_STACK 100

typedef struct {
	int data[MAX_STACK];
	int size;
} Stack;

void Stack_init(Stack *s) {
	s->size = 0;
}

int Stack_top(Stack *s) {
	if (s->size == 0) {
		printf("Error: stack empty\n");
		return -1;
	}

	return s->data[s->size-1];
}

void Stack_push(Stack *s, int v) {
	if (s->size < MAX_STACK) {
		s->data[s->size++] = v;
	} else {
		printf("Error: stack full\n");
	}
}

void Stack_pop(Stack *s) {
	if (s->size == 0) {
		printf("Error: stack empty\n");
	} else {
		s->size--;
	}
}


int main() {
	Stack s;
	Stack_init(&s);
	Stack_push(&s, 5);
	printf("%d\n", Stack_top(&s));
	Stack_pop(&s);
	Stack_top(&s);
}
