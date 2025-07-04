// bk_math3d.h
// Combined math utilities for 3D transformations

#ifndef BK_MATH3D_H
#define BK_MATH3D_H

#include "bk_vec3.h"
#include "bk_mat4.h"

bk_vec3 bk_mat4_rotate_vec3(bk_mat4 m, bk_vec3 v);
bk_vec3 bk_mat4_get_forward(bk_mat4 m);
bk_vec3 bk_mat4_get_right(bk_mat4 m);
bk_vec3 bk_mat4_get_up(bk_mat4 m);
bk_mat4 bk_mat4_lookat(bk_vec3 eye, bk_vec3 center, bk_vec3 up);

#endif