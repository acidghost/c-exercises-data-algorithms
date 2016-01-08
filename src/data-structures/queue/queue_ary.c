#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "queue_ary.h"


T empty_queue;

queue *queue_new(const size_t t_size, const uint initial_size) {
	empty_placeholder(empty_queue)
	queue *q = malloc(sizeof(queue));
	*q = (queue) {
		.t_size=t_size,
		.data=malloc(initial_size * t_size),
		.size=initial_size,
		.last=initial_size-1
	};
	return q;
}

bool queue_enqueue(queue *q, T v) {
	if (queue_full(q)) {
		q->size *= 2;
		q->data = realloc(q->data, q->size * q->t_size);
	}
	q->data[q->last++] = v;
	return true;
}

T queue_front(queue *q) {
	if (queue_empty(q)) {
		return empty_queue;
	}
	return q->data[0];
}

bool queue_dequeue(queue *q) {
	if (queue_empty(q)) {
		return false;
	}
	memcpy(q->data, &q->data[1], q->last);
	q->last--;
	return true;
}

bool queue_empty(queue *q) {
	return q->last == 0;
}

bool queue_full(queue *q) {
	return q->last == q->size;
}

uint queue_size(queue *q) {
	return q->last;
}

int main() {
	int v = 10;
	queue *q = queue_new(sizeof(int), 1);
	assert(queue_enqueue(q, &v) == true);
	assert(queue_enqueue(q, &v) == true);
	assert(*(int *) queue_front(q) == v);
	assert((int *) queue_front(q) == &v);
	assert(queue_dequeue(q) == true);
	assert(queue_dequeue(q) == true);
	assert(queue_dequeue(q) == false);
	assert(queue_front(q) == empty_queue);
	puts("All assertions passed.");
}
