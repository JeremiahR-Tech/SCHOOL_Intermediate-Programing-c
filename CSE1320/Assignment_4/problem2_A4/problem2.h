#ifndef PROBLEM2_H
#define PROBLEM2_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double *data;
	int size;
} dynamic_array;

dynamic_array add_value(double, dynamic_array);
dynamic_array rm_value(int,dynamic_array);

#endif
