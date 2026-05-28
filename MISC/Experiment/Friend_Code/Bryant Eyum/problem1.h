#ifndef PROBLEM1_H_
#define PROBLEM1_H_

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
    vehicle_t data;
    int size;
} dynamic_array_t;


#endif /* PROBLEM1.H */
