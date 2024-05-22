#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node_t;

struct node{
    int data;
    node_t *next;
};

typedef struct stack stack_t;

struct stack{
    int size;
    node_t *top;
};


stack_t* stack_new();
void stack_delete(void *self);
int stack_is_empty(const stack_t *self);
int stack_peek(const stack_t *self);
bool stack_push(stack_t *self, int data);
int stack_pop(stack_t *self);


#endif /* STACK_H */