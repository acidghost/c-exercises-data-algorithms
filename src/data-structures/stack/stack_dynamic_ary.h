#include "../utils.h"

typedef struct {
	T *data;
	size_t size;
	size_t used;
	size_t elm_size;
} stack;

extern void *empty_stack;

stack *stack_new(const size_t, uint);
T stack_top(stack *);
bool stack_push(stack *, T);
bool stack_pop(stack *);
uint stack_size(stack *);
bool stack_empty(stack *);
bool stack_full(stack *);
