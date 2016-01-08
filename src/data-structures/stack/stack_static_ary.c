#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack_static_ary.h"


T empty_stack;

stack *stack_new() {
	empty_placeholder(empty_stack)
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

uint stack_size(stack *s) {
	return s->size;
}

bool stack_empty(stack *s) {
	return s->size == 0;
}

bool stack_full(stack *s) {
	return s->size == MAX_STACK;
}


int main() {
	stack *s = stack_new();

	int v = 6;

	assert(stack_push(s, &v) == true);
	
	int top = *(int *) stack_top(s);
	assert(top == v);
	
	assert(stack_pop(s) == true);
	
	assert(stack_top(s) == empty_stack);

	puts("All assertions were successfull.");
}
