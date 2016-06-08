/**

	VEX_MATH.H

	Custom math functions and variables

**/

#ifndef VEX_MATH_H
#define VEX_MATH_H

#include <math.h>

typedef struct _vec2 {
	float x;
	float y;
} vec2;

typedef struct _vec3 {
	float x;
	float y;
	float z;
} vec3;

// Initialize vectors
vec2* vex_math_vec2_new(float x, float y);
vec3* vex_math_vec3_new(float x, float y, float z);

// Dot products
float vex_math_vec2_dot(vec2* a, vec2* b);
float vex_math_vec3_dot(vec3* a, vec3* b);

// Distance between points
float vex_math_vec2_distance(vec2* a, vec2* b);
float vex_math_vec3_distance(vec3* a, vec3* b);

// Add two vectors
vec2* vex_math_vec2_add(vec2* a, vec2* b);
vec3* vex_math_vec3_add(vec3* a, vec3* b);

// Scalar multiplication
vec2* vex_math_vec2_scalar(vec2* a, float scalar);
vec3* vex_math_vec3_scalar(vec3* a, float scalar);

//
//
// IMPLEMENTATION
//
//

vec2* vex_math_vec2_new(float x, float y) {
	vec2* self = (vec2*)malloc(sizeof(vec2));
	self->x = x;
	self->y = y;
	return self;
}

vec3* vex_math_vec3_new(float x, float y, float z) {
	vec3* self = (vec3*)malloc(sizeof(vec3));
	self->x = x;
	self->y = y;
	self->z = z;
	return self;
}

float vex_math_vec2_dot(vec2* a, vec2* b) {
	return (a->x * b->x) + (a->y * b->y);
}

float vex_math_vec3_dot(vec3* a, vec3* b) {
	return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

float vex_math_vec2_distance(vec2* a, vec2* b) {
	return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

float vex_math_vec3_distance(vec3* a, vec3* b) {
	return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2) + pow(b->z - a->z, 2));
}

vec2* vex_math_vec2_add(vec2* a, vec2* b) {
	return vex_math_vec2_new(a->x + b->x, a->y + b->y);
}

vec3* vex_math_vec3_add(vec3* a, vec3* b) {
	return vex_math_vec3_new(a->x + b->x, a->y + b->y, a->z + b->z);
}

vec2* vex_math_vec2_scalar(vec2* a, float scalar) {
	return vex_math_vec2_new(a->x * scalar, a->y * scalar);
}

vec3* vex_math_vec3_scalar(vec3* a, float scalar) {
	return vex_math_vec3_new(a->x * scalar, a->y * scalar, a->z * scalar);
}

#endif // VEX_MATH_H