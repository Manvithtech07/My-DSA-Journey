#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Queue *queue_new(uint32_t capacity){
	Queue *q=(Queue *)malloc(sizeof(Queue));
	q->capacity=capacity;
	q->count=0;
	q->head=0;
	q->tail=0;
	q->data=(int32_t*)malloc(q->capacity * sizeof(int32_t));
	return q;
}
uint32_t is_full(Queue *q){
	return q->count==q->capacity;
}

uint32_t is_empty(Queue *q){
	return q->count==0;
}
void enqueue(Queue *q, int32_t data){
	if(is_full(q)){
		printf("Queue Overflow\n");
		return;
	}
	q->data[q->tail]=data;
	q->tail = (q->tail+1)%q->capacity;
	++q->count;
}
int32_t dequeue (Queue *q){
	if(is_empty(q)){
		printf("Queue Underflow\n");
		exit(EXIT_FAILURE);
	}
	int32_t data = q->data[q->head];
	q->head = (q->head+1)%q->capacity;
	--q->count;
	return data;
}
void display_queue(Queue *q){
	if(is_empty(q)){
		printf("Queue is Empty\n");
		return;
	}
	for(uint32_t i=0;i<q->count;i++){
		int index = (q->head+i)%q->capacity;
		printf("| %d |",q->data[index]);
	}
}
void free_queue(Queue *q){
	free(q->data);
	free(q);
}
