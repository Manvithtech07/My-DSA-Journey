#ifndef STACK_H
#define STACK_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _stack_ stack;
struct _stack_{
	int32_t top;
	uint32_t capacity;
	int32_t *data;
};
//function prototypes
stack *stk_new(uint32_t capacity);
uint32_t is_full(stack *stk);
uint32_t is_empty(stack *stk);
void push(stack *stk, int32_t data);
int32_t pop(stack *stk);
int32_t peek(stack *stk);
void find_and_display_key(stack *stk, int32_t key);
void display_stack(stack *stk);
void free_stack(stack*stk);
#endif