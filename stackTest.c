#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

int main(){
    stack_t *stk = stack_new();
    stack_push(stk, 1001);
    printf("%d\n", stack_peek(stk));
    stack_delete(stk);
    printf("test ended...\n");
    return 0;
}
