// bk_vec3.h
// Minimal 3D vector math library for C

#ifndef BK_VEC3_H
#define BK_VEC3_H

#include "bk_vec3_type.h"

#define BK_VEC3_ZERO (bk_vec3){0, 0, 0}

bk_vec3 bk_vec3_add(bk_vec3 a, bk_vec3 b);
bk_vec3 bk_vec3_sub(bk_vec3 a, bk_vec3 b);
bk_vec3 bk_vec3_scale(bk_vec3 v, float s);
float bk_vec3_dot(bk_vec3 a, bk_vec3 b);
bk_vec3 bk_vec3_cross(bk_vec3 a, bk_vec3 b);
float bk_vec3_length(bk_vec3 v);
bk_vec3 bk_vec3_normalize(bk_vec3 v);

#endif