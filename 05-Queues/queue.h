#ifndef QUEUE_H
#define QUEUE_H
#include<stdint.h>

typedef struct _queue_ Queue;
struct _queue_{
	uint32_t capacity;
	uint32_t count;
	uint32_t head;
	uint32_t tail;
	int32_t *data;
};

Queue *queue_new(uint32_t capacity);
uint32_t is_full(Queue *q);
uint32_t is_empty(Queue *q);
void enqueue(Queue *q, int32_t data);
int32_t dequeue (Queue *q);
void display_queue(Queue *q);
void free_queue(Queue *q);
#endif