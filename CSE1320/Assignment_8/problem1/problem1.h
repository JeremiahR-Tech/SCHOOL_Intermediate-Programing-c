#ifndef PROBLEM1_H
#define PROBLEM1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef BUF_SIZE
#define BUF_SIZE 128
#endif

#ifdef DEBUG
#define printd(str, args...) printf("[DEBUG] "); printf(str, args)
#else
#define printd(str, args...)
#endif


typedef struct {
	int year;
	char *make;
	char *model;
	char *color;
	char *license;
} vehicle_t;

typedef struct BTNode BTNode;
struct BTNode {
    int key;
    vehicle_t data;
    BTNode *left;
    BTNode *right;
};

typedef struct Node Node;
struct Node {
    void *data;
    Node *next;
};

typedef enum {
    PREORDER,
    INORDER,
    POSTORDER
} traverse_type;

BTNode *add_btnode(vehicle_t);
void enqueue(Node **, void *);
Node *dequeue(Node **);
void bfs(BTNode *);
void dfs(BTNode *, traverse_type);
void insert(BTNode **, vehicle_t v);
BTNode *search(BTNode *,int);
void release_tree(BTNode *);
void print_vehicles(vehicle_t);


#endif
