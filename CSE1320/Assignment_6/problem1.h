#ifndef PROBLEM1_H
#define PROBLEM1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int year;
	char *make;
	char *model;
	char *color;
	char *license;
} vehicle_t;

typedef struct {
	vehicle_t *data;
	int size;
} dynamic_array;

void trim(char *buffer);
void print_vehicle(vehicle_t);
vehicle_t getcarinfo();

#endif
