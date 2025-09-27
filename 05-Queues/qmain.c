#include<stdio.h>
#include "queue.h"

int main(){
    Queue *q = queue_new(5);
    display_queue(q);
    printf("\n");
    enqueue(q,10);
    display_queue(q);
    printf("\n");
    enqueue(q,20);
    display_queue(q);
    printf("\n");
    enqueue(q,69);
    display_queue(q);
    printf("\n");
    dequeue(q);
    display_queue(q);
    printf("\n");
    free_queue(q);
    return 0;
}