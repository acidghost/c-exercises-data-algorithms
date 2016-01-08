#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack_dynamic_ary.h"


void *empty_stack;

stack *stack_new(const size_t elm_size, uint initial_size) {
	static int es;
	if (!empty_stack) empty_stack = &es;
	stack *s = malloc(sizeof(stack));
	s->elm_size = elm_size;
	s->data = malloc(initial_size * elm_size);
	s->size = initial_size;
	s->used = 0;
	return s;
}

T stack_top(stack *s) {
	if (stack_empty(s)) {
		return empty_stack;
	}
	return s->data[s->used-1];
}

bool stack_push(stack *s, T v) {
	if (stack_full(s)) {
		s->size *= 2;
		s->data = realloc(s->data, s->size * s->elm_size);
	}
	s->data[s->used++] = v;
	return true;
}

bool stack_pop(stack *s) {
	if (stack_empty(s)) {
		return false;
	}
	s->used--;
	return true;
}

uint stack_size(stack *s) {
	return s->used;
}

bool stack_empty(stack *s) {
	return s->used == 0;
}

bool stack_full(stack *s) {
	return s->used == s->size;
}


int main() {
	stack *s = stack_new(sizeof(int), 1);

	assert(stack_push(s, 5) == true);
	assert(stack_push(s, 5) == true);

	int *top = (int *) stack_top(s);
	assert(top == 5);

	assert(stack_pop(s) == true);
	assert((int *) stack_top(s) == 5);

	assert(stack_pop(s) == true);
	assert(stack_top(s) == empty_stack);

	puts("All assertions were successfull.");
}
