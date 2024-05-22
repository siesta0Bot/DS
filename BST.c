#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>


short cmp(int a, int b){
    return a-b;
}

typedef struct node_t node_t;

struct node_t{
    int data;
    node_t* left;
    node_t* right;
};

static node_t* node_new(int value){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));

    if(newNode == NULL){
        printf("Node construct failure...\n");
        return newNode; 
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right =NULL;
    return newNode;
}

typedef struct tree_t tree_t;
typedef short (*cmp_fn)(int, int);

struct tree_t{
    node_t* root;
    cmp_fn cmp;
};

tree_t* tree_new(cmp_fn cmp){
    tree_t *self = (tree_t*)malloc(sizeof(tree_t));
    if(self == NULL){
        return self;
    }

    self->root = NULL;
    self->cmp = cmp;

    return self;
}

static void _tree_delete(node_t *node);

void tree_delete(void *self){
    if(self == NULL){
        return;
    }

    node_t *root = ((tree_t*) self)->root;
    _tree_delete(root);

    free(self);
}

static void _tree_delete(node_t *node){
    if(!node){
        return;
    }
    
    _tree_delete(node->left);
    _tree_delete(node->right);
    printf("node %p deleted...\n", node);
    free(node);
}

bool tree_is_empty(const tree_t *self){
    assert(self);

    return !(self->root);
}

static size_t _tree_height(const node_t *node);

size_t tree_height(const tree_t *self){
    assert(self);

    return _tree_height(self->root);
}

static size_t _tree_height(const node_t *node){
    if(!node){
        return 0;
    }
    
    size_t l = (!(node->left)) ? 0 : _tree_height(node->left);
    size_t r = (!(node->right)) ? 0 : _tree_height(node->right);
    size_t h = l>r ? l : r;

    return h+1;
}

static bool _tree_contains(node_t *node, int value, cmp_fn cmp);

bool tree_contains(const tree_t *self, int value){
    assert(self);

    return _tree_contains(self->root, value, self->cmp);
}

static bool _tree_contains(node_t *node, int value, cmp_fn cmp){
    if(!node) return false;

    if(cmp(value, node->data) == 0) return true;
    else if(cmp(value, node->data) < 0) return _tree_contains(node->left, value, cmp);
    else if(cmp(value, node->data) > 0) return _tree_contains(node->right, value, cmp);
    return false;
}

int tree_min(const tree_t *self){
    assert(!tree_is_empty(self));

    node_t* p = self->root->left;
    while(p->left!=NULL){
        p = p->left;
    }

    return p->data;
}

int tree_max(const tree_t *self){
    assert(tree_is_empty(self));

    node_t *p = self->root->right;
    while(p->right=NULL){
        p = p->right;
    }
    
    return p->data;
}

static bool _tree_insert(node_t **node, int value, cmp_fn cmp);

bool tree_insert(tree_t *self, int value){
    assert(self);

    return _tree_insert(&(self->root), value, self->cmp);
}

static bool _tree_insert(node_t **node, int value, cmp_fn cmp){
    if(*node == NULL){
        *node = node_new(value);
        printf("node added %p\n", *node);

        if(*node == NULL){
            return false;
        }

        return true;
    }

    if(cmp(value, (*node)->data) < 0){
        return _tree_insert(&((*node)->left), value, cmp);
    }
    else if(cmp(value, (*node)->data) >= 0){
        return _tree_insert(&((*node)->right), value, cmp);
    }

    return false;
}

static int _tree_min(const node_t *node){
    assert(node);

    if(node->left!=NULL){
        node = node->left;
    }
    return node->data;
}

static bool _tree_remove(node_t **node, int value, cmp_fn cmp);

bool tree_remove(tree_t *self, int value){
    if(tree_is_empty(self)){
        return false;
    }

    return _tree_remove(&(self->root), value, cmp);
}

static bool _tree_remove(node_t **node, int value, cmp_fn cmp){
    if(*node == NULL) return false;

    if(cmp(value, (*node)->data) < 0) return _tree_remove(&((*node)->left), value, cmp);
    else if(cmp(value, (*node)->data) > 0) return _tree_remove(&((*node)->right), value, cmp);

    if(((*node)->left)==NULL){
        node_t *temp = (*node)->right;
        printf("node %p removed...\n", *node);
        free(*node);
        *node = temp;
    }

    else if(((*node)->right)==NULL){
        node_t *temp = (*node)->left;
        printf("node %p removed...\n", *node);
        free(*node);
        *node = temp;
    }

    else{
        int min = _tree_min((*node)->right);
        (*node)->data = min;

        if(!_tree_remove(&((*node)->right), min, cmp)){
            return false;
        }
    }

    return true;

}