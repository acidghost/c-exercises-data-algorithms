#include "../utils.h"

#define MAX_STACK 100


typedef struct {
	T data[MAX_STACK];
	uint size;
} stack;

extern void *empty_stack;

stack *stack_new();
T stack_top(stack *);
bool stack_push(stack *, T);
bool stack_pop(stack *);
uint stack_size(stack *);
bool stack_empty(stack *);
bool stack_full(stack *);
