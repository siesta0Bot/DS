#include "Stack.h"

node_t* node_new(int data){
    node_t *n = malloc(sizeof(node_t));
    if(!n) return NULL;
    n->data = data;
    return n;
}

stack_t* stack_new(){
    stack_t *s = malloc(sizeof(stack_t));
    if(!s){
        s->size = 0;
        return s;
    }
    s->top = NULL;
    return s;
}

void stack_delete(void *self){
    if(!self) return;

    node_t *curr = ((stack_t*) self)->top;
    while(curr){
        node_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(self);
}

int stack_is_empty(const stack_t *self){
    assert(self);
    return !(self->size);
}

int stack_peek(const stack_t *self){
    assert(!stack_is_empty(self));
    return self->top->data;
}

bool stack_push(stack_t *self, int data){
    node_t *n = node_new(data);
    if(!n) return false;
    n->next = self->top;
    self->top = n;
    return true;
}

int stack_pop(stack_t *self){
    assert(!stack_is_empty(self));
    node_t *curr = self->top;
    int popped = curr->data;
    self->top = curr->next;
    free(curr);
    self->size--;
    return popped;
}