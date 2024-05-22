#include <stdio.h>
#include "BST.h"


int main(){
    int n;
    tree_t* tree = tree_new(cmp);
    while(scanf("%d", &n) !=EOF){
        tree_insert(tree, n);
    }
    tree_delete(tree);
    return 0;
}