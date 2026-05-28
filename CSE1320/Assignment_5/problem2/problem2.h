#ifndef PROBLEM2_H
#define PROBLEM2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vehicle Vehicle;
struct vehicle {
	int year;
	char *make;
	char *model;
	char *color;
	char *lisence_plate;
};

typedef struct node Node;
struct node {
    Vehicle data;
    Node *next;
};


#endif

