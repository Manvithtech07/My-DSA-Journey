#include"stack.h"
stack *stk_new(uint32_t capacity){
    stack *stk = (stack*)malloc(sizeof(stack));
    stk->top=-1;
    stk->capacity=capacity;
    stk->data=(int32_t *)malloc(stk->capacity * sizeof(int32_t));
    return stk;
}
uint32_t is_full(stack *stk){
    return stk->top == stk->capacity-1;
}
uint32_t is_empty(stack *stk){
    return stk->top == -1;
}
void push(stack *stk, int32_t data){
    if(is_full(stk)){
        printf("Stack Overflow\n");
        return;
    }
    stk->data[++stk->top]=data;
}
int32_t pop(stack *stk){
    if(is_empty(stk)){
        printf("Stack Underflow");
        exit(EXIT_FAILURE);
    }
    return stk->data[stk->top--];
}

int32_t peek(stack *stk){
    if(is_empty(stk)){
        printf("Stack is Empty");
        exit(EXIT_FAILURE);
    }
    return stk->data[stk->top];
}
void find_and_display_key(stack *stk, int32_t key){
    //Searches for a key in the stack without permanently changing it.
    // 1. Create a temporary stack to hold the elements.
    stack *temp_stk = stk_new(stk->capacity);
    int32_t found = 0;
    // 2.Pop from original, check, push to temp.
    while(!is_empty(stk)){
        int32_t current_data = pop(stk);
        if(current_data == key){
            printf("Found the key: %d\n",current_data);
            found = 1;
        }
        push(temp_stk, current_data);
    }
    if(!found){
        printf("Key %d was not found in the stack.\n",key);
    }
    //3. Restore: Pop from temp, push back to original.
    while(!is_empty(temp_stk)){
        push(stk,pop(temp_stk));
    }
    free_stack(temp_stk);
}

void display_stack(stack *stk){
    if(is_empty(stk)){
        printf("Stack is Empty\n");
        return;
    }
    for(int32_t i=stk->top;i>=0;i--){
        printf("| %d |\n",stk->data[i]);
    }
}
void free_stack(stack *stk){
    free(stk->data);
    free(stk);
}




