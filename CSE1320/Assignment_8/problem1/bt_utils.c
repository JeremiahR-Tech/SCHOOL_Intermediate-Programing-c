#include "problem1.h"

BTNode *add_btnode(vehicle_t data) {
    BTNode *node = calloc(1, sizeof(BTNode));
    node->data = data;
    node->key = data.year;

    return node;
}

void enqueue(Node **queue, void *data) {
    if (*queue == NULL) {
        *queue = calloc(1, sizeof(Node));
        (*queue)->data = data;

        return;
    }

    Node *temp = *queue;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = calloc(1, sizeof(Node));
    temp->next->data = data;
}

Node *dequeue(Node **queue) {
    Node *n = *queue;
    *queue = (*queue)->next;

    return n;
}


void print_vehicles(vehicle_t v)
{
	printf("%d %s %s %s %s",v.year,v.make,v.model,v.color,v.license);
}


void bfs(BTNode *root) {
    BTNode *temp = root;
    Node *n = NULL;
    Node *queue = NULL;
    enqueue(&queue, temp);
    while (queue != NULL) {
        n = dequeue(&queue);
        temp = n->data;
        print_vehicles(temp->data);

        if (temp->left != NULL) {
            enqueue(&queue, temp->left);
        }

        if (temp->right != NULL) {
            enqueue(&queue, temp->right);
        }

        free(n);
    }
}

void dfs(BTNode *root, traverse_type t) {
//    int count = 0;
    if (root == NULL) {
//	printd("Root is NULL: %d\n",count);
        return;
    }

    if (t == PREORDER) {
//	printd("Found root in preorder: %d\n",count);
        print_vehicles(root->data);
    }

    dfs(root->left, t);

    if (t == INORDER) {
        print_vehicles(root->data);
    }

    dfs(root->right, t);

    if (t == POSTORDER) {
        print_vehicles(root->data);
    }
}

void insert(BTNode **root, vehicle_t v) {
    BTNode **temp = root;
    while (*temp != NULL) {
        if (v.year >= (*temp)->key) {
            temp = &(*temp)->right;
        } else {
            temp = &(*temp)->left;
        }
    }

    *temp = add_btnode(v);
}

BTNode *search(BTNode *node, int year) {
    if (node == NULL || year == node->key) {
        return node;
    } else if (year > node->key) {
        return search(node->right, year);
    } else {
        return search(node->left, year);
    }
}

void release_tree(BTNode *node) {
    if (node != NULL) {
	free(node->data.make);
	free(node->data.model);
	free(node->data.color);
	free(node->data.license);
        release_tree(node->left);
        release_tree(node->right);
        free(node);
    }
}
