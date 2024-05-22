#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#ifndef BST_H
#define BST_H


#include <stddef.h>

typedef struct node_t node_t;

struct node_t{
    int data;
    node_t* left;
    node_t* right;
};

typedef struct tree_t tree_t;

typedef short (*cmp_fn)(int, int);

struct tree_t{
    node_t* root;
    cmp_fn cmp;
};

short cmp(int a, int b);

static node_t* node_new(int value);

tree_t* tree_new(cmp_fn cmp);

static void _tree_delete(node_t *node);
void tree_delete(void *self);

bool tree_is_empty(const tree_t *self);

static size_t _tree_height(const node_t *node);
size_t tree_height(const tree_t *self);

static bool _tree_contains(node_t *node, int value, cmp_fn cmp);
bool tree_contains(const tree_t *self, int value);

int tree_min(const tree_t *self);
int tree_max(const tree_t *self);

static bool _tree_insert(node_t **node, int value, cmp_fn cmp);
bool tree_insert(tree_t *self, int value);

static bool _tree_remove(node_t **node, int value, cmp_fn cmp);
bool tree_remove(tree_t *self, int value);

#endif /* BST_H */