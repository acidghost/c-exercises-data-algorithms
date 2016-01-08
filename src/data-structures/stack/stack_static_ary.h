#include "../utils.h"

#define MAX_STACK 100


typedef struct {
	T data[MAX_STACK];
	unsigned int size;
} stack;

extern void *empty_stack;

stack *stack_new();
T stack_top(stack *s);
bool stack_push(stack *s, T v);
bool stack_pop(stack *s);
