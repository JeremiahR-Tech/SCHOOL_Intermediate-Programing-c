#ifndef VECTOR_TYPES_H_
#define VECTOR_TYPES_H_

#include <stdio.h>

#define VEC2F_MAX 2
#define VEC3F_MAX 3
#define VEC4F_MAX 4

typedef struct{
	float vector[VEC2F_MAX];
}vec2f;

typedef struct{
	float vector[VEC3F_MAX];
}vec3f;

typedef struct{
	float vector[VEC4F_MAX];
}vec4f;

// This will add any vector array with another and print it
void vect_add2f(float *, float *, int);
void vect_add3f(float *, float *, int);
void vect_add2f(float *, float *, int);
// This will multiple any vector array with another and print it
void vect_mult2f(float *vect1, float, int);
void vect_mult3f(float *vect1, float, int);
void vect_mult4f(float *vect1, float, int);
// This will intialize all vectors
vec2f intial_vect2f(vec2f);
vec3f intial_vect3f(vec3f);
vec4f intial_vect4f(vec4f);


#endif
