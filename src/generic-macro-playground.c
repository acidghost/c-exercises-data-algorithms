#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef enum { true = 1, false = 0 } bool;
typedef char* string;

#define generic_obj(type)				\
	type custom_max(type a, type b) {	\
		return a > b ? a : b;			\
	}									\
										\
	type custom_min(type a, type b) {	\
		return a < b ? a : b;			\
	}

#define generic_stack(type, max_size)						\
	type empty_##type##_stack;								\
															\
	typedef struct {										\
		type data[max_size];								\
		int size;											\
	} type##_stack;											\
															\
	type##_stack *type##_stack_new() {						\
		static type es;										\
		if (!empty_##type##_stack)							\
			empty_##type##_stack = es;						\
		type##_stack *s = malloc(sizeof(type##_stack));		\
		s->size = 0;										\
		return s;											\
	}														\
															\
	type type##_stack_top(type##_stack *s) {				\
		if (s->size == 0) {									\
			return empty_##type##_stack;					\
		}													\
		return s->data[s->size-1];							\
	}														\
															\
	bool type##_stack_push(type##_stack *s, type v) {		\
		if (s->size < max_size) {							\
			s->data[s->size++] = v;							\
			return true;									\
		} else {											\
			return false;									\
		}													\
	}														\
															\
	bool type##_stack_pop(type##_stack *s) {				\
		if (s->size == 0) {									\
			return false;									\
		} else {											\
			s->size--;										\
			return true;									\
		}													\
	}														\
															\
	int type##_stack_size(type##_stack *s) {				\
		return s->size;										\
	}														\
															\
	bool type##_stack_empty(type##_stack *s) {				\
		return s->size == 0;								\
	}														\
															\
	bool type##_stack_full(type##_stack *s) {				\
		return s->size == max_size;							\
	}

generic_obj(int)
generic_stack(int, 100)
generic_stack(string, 50)

void map(void *src, void *dest, size_t size, size_t elm_size, void *(f)(void *)) {
	for (int i=0; i<size; i++) {
		void *tmp = f(src + i*elm_size);
		memcpy(dest, &tmp, elm_size);
		dest += elm_size;
	}
}

void *double_int_val(void *val) {
	return (void *)(*(int *) val * 2);
}

int main() {
	puts("Macro test");
	int a = 1;
	int b = 10;
	printf("%d\n", custom_max(a, b));
	printf("%d\n", custom_min(a, b));


	puts("\n\nStack tests...");
	string v = "hello";
	string_stack *ss = string_stack_new();
	assert(string_stack_push(ss, v) == true);
	assert((string) string_stack_top(ss) == v);
	assert(string_stack_pop(ss) == true);
	assert((string) string_stack_top(ss) == empty_string_stack);
	assert(string_stack_pop(ss) == false);
	puts("...passed");


	puts("\n\nMap test");
	int ary[] = { 1, 2, 3 };
	int size = 3;
	int *ary2 = malloc(sizeof(int) * size);
	map(ary, ary2, size, sizeof(int), double_int_val);
	for (int i=0; i<size; i++)
		printf("%d\n", ary2[i]);
}
