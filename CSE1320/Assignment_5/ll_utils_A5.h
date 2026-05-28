#ifndef LL_UTILS_H_
#define LL_UTILS_H_

#include <stdlib.h>
#include "problem2.h"

typedef struct node Node;
struct node {
    Vehicle data;
    Node *next;
};

Node *create_node(void *);
void insert_node(Node **, Node *, int);
void *remove_node(Node **, void *, int (*)(const void *, const void *));

#endif // LL_UTILS_H_
