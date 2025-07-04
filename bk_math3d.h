// bk_math3d.h - Combined math utilities for 3D transformations
// Provides helper functions using bk_vec3 and bk_mat4,
// including vector rotation and matrix basis extraction (forward, right, up).
// Useful for camera systems, object orientation, and directional logic.

#ifndef BK_MATH3D_H
#define BK_MATH3D_H

#include "bk_vec3.h"
#include "bk_mat4.h"

bk_vec3 bk_mat4_rotate_vec3(bk_mat4 m, bk_vec3 v) {
    return (bk_vec3){
        m.m[0] * v.x + m.m[4] * v.y + m.m[8]  * v.z,
        m.m[1] * v.x + m.m[5] * v.y + m.m[9]  * v.z,
        m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z
    };
}

bk_vec3 bk_mat4_get_forward(bk_mat4 m) {
    return (bk_vec3){-m.m[8], -m.m[9], -m.m[10]};
}

bk_vec3 bk_mat4_get_right(bk_mat4 m) {
    return (bk_vec3){-m.m[0], -m.m[1], -m.m[2]};
}

bk_vec3 bk_mat4_get_up(bk_mat4 m) {
    return (bk_vec3){-m.m[4], -m.m[5], -m.m[6]};
}

#endif