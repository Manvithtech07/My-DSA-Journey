#include<stdio.h>
#include "stack.h"

int main(){
    stack *stk = stk_new(10);
    push(stk, 40);
    push(stk, 55);
    push(stk, 75);
    push(stk, 65);
    push(stk, 25);
    push(stk, 33);
    push(stk, 50);
    display_stack(stk);
    printf("Top element is %d\n\n", peek(stk));
    find_and_display_key(stk, 65);
    free_stack(stk);
    return 0;
}