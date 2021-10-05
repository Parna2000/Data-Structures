#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int*arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1)
    return 1;
    else
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1)
    return 1;
    else
    return 0;
}

struct stack* createStack(int capacity){
    struct stack*s=(struct stack*)malloc(sizeof(struct stack));
    s->size=capacity;
    s->top=-1;
    s->arr=(int*)malloc(capacity * sizeof(int));
}

int pop(struct stack*ptr){
    if(isEmpty(ptr))
    return -1;
    else{
        int val=ptr->arr[ptr->top];
        return val;
    }
}

void push(struct stack*ptr,int x){
    if(isFull(ptr))
    return;
    else{
        ptr->top++;
        ptr->arr[ptr->top]=x;
    }
}

