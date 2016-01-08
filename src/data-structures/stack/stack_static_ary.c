#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack_static_ary.h"


void *empty_stack;

stack *stack_new() {
	static int es;
	if (!empty_stack) empty_stack = &es;
	stack *s = malloc(sizeof(stack));
	s->size = 0;
	return s;
}

T stack_top(stack *s) {
	if (s->size == 0) {
		return empty_stack;
	}

	return s->data[s->size-1];
}

bool stack_push(stack *s, T v) {
	if (s->size < MAX_STACK) {
		s->data[s->size++] = v;
		return true;
	} else {
		return false;
	}
}

bool stack_pop(stack *s) {
	if (s->size == 0) {
		return false;
	} else {
		s->size--;
		return true;
	}
}


int main() {
	stack *s = stack_new();

	assert(stack_push(s, (void *) 5) == true);
	
	int *top = (int *) stack_top(s);
	assert(top == 5);
	
	assert(stack_pop(s) == true);
	
	assert(stack_top(s) == empty_stack);

	puts("All assertions were successfull.");
}
