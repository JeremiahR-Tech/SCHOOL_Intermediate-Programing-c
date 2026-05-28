#ifndef PROBLEM1_H
#define PROBLEM1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vehicle Vehicle;
struct vehicle {
	long size;
	int year;
	char *make;
	char *model;
	char *color;
	char *lisence_plate;
};

#endif

