// bk_mat4.h - 4x4 matrix math for 3D graphics
// Provides functions for creating and manipulating 4x4 matrices:
// identity, orthographic and perspective projection, translation,
// scaling, rotation (X/Y/Z), and matrix multiplication.
// Designed for use in OpenGL-style column-major layout.

#ifndef BK_MAT4_H
#define BK_MAT4_H

typedef struct {
    float m[16];
} bk_mat4;

bk_mat4 bk_mat4_identity();
bk_mat4 bk_mat4_ortho(float left, float right, float bottom, float top, float near, float far);
bk_mat4 bk_mat4_perspective(float fov_rad, float aspect, float near, float far);
bk_mat4 bk_translate(float x, float y, float z);
bk_mat4 bk_mat4_scale(float x, float y, float z);
bk_mat4 bk_mat4_rotate_x(float angle_rad);
bk_mat4 bk_mat4_rotate_y(float angle_rad);
bk_mat4 bk_mat4_rotate_z(float angle_rad);
bk_mat4 bk_mat4_mul(bk_mat4 a, bk_mat4 b);

#endif