#include <stdio.h>
#include "LinkedList.h"

int main(){
    int n;
    ListNode* node = NULL;
    
    while(1){
        scanf("%d", &n);
        if(n<0) break;
        addNode(&node, n);
    }
    printNodes(node);
    inverse_printNodes(node);
    LinkedList_delete(node);
}