#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//快速排序非递归

typedef struct stack{
    int *data;
    int size;
}stack;

void initStack(stack* s,int size){
    int *data = (int*)calloc(size,sizeof(int));
    s->data = data;
    s->size = 0;
};

void push(stack* s,int num){
    s->data[s->size++] = num;
}

void pop(stack* s){
    s->size--;
}

int top(stack* s){
    return s->data[s->size-1];
}

int isEmpty(stack* s){
    return s->size == 0;
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void QuickSort(int *a,int size){

   
}