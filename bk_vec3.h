// bk_vec3.h - Minimal 3D vector math library for C
// Provides basic operations for 3D vectors: addition, subtraction, scaling,
// dot product, cross product, length, and normalization.
// Designed for use in 3D graphics, physics, and game development.

#ifndef BK_VEC3_H
#define BK_VEC3_H

typedef struct {
    float x;
    float y;
    float z;
} bk_vec3;

#define BK_VEC3_ZERO (bk_vec3){0, 0, 0}

bk_vec3 bk_vec3_new(float x, float y, float z);
bk_vec3 bk_vec3_add(bk_vec3 a, bk_vec3 b);
bk_vec3 bk_vec3_sub(bk_vec3 a, bk_vec3 b);
bk_vec3 bk_vec3_scale(bk_vec3 v, float s);
float bk_vec3_dot(bk_vec3 a, bk_vec3 b);
bk_vec3 bk_vec3_cross(bk_vec3 a, bk_vec3 b);
float bk_vec3_length(bk_vec3 v);
bk_vec3 vec3_normalize(bk_vec3 v);

#endif