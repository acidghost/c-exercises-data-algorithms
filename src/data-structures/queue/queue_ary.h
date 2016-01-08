#include "../utils.h"

typedef struct {
	T *data;
	uint last;
	size_t size;
	size_t t_size;
} queue;

extern T empty_queue;

queue *queue_new(const size_t, const uint);
bool queue_enqueue(queue *, T);
T queue_front(queue *);
bool queue_dequeue(queue *);
bool queue_empty(queue *);
bool queue_full(queue *);
uint queue_size(queue *);
