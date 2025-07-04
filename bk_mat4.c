#include <string.h>

#include "bk_math.h"
#include "bk_mat4.h"

bk_mat4 bk_mat4_identity() {
    bk_mat4 r;
    memset(r.m, 0, sizeof(r.m));
    r.m[0] = r.m[5] = r.m[10] = r.m[15] = 1.0f;

    return r;
}

bk_mat4 bk_mat4_ortho(float left, float right, float bottom, float top, float near, float far) {
    bk_mat4 r = bk_mat4_identity();
    r.m[0] = 2.0f / (right - left);
    r.m[5]  = 2.0f / (top - bottom);
    r.m[10] = -2.0f / (far - near);
    r.m[12] = -(right + left) / (right - left);
    r.m[13] = -(top + bottom) / (top - bottom);
    r.m[14] = -(far + near) / (far - near);

    return r;
}

bk_mat4 bk_mat4_perspective(float fov_rad, float aspect, float near, float far) {
    float f = 1.0f / bk_tan(fov_rad / 2.0f);
    bk_mat4 r = {0};
    r.m[0]  = f / aspect;
    r.m[5]  = f;
    r.m[10] = (far + near) / (near - far);
    r.m[11] = -1.0f;
    r.m[14] = (2.0f * far * near) / (near - far);

    return r;
}

bk_mat4 bk_translate(float x, float y, float z) {
    bk_mat4 r = bk_mat4_identity();
    r.m[12] = x;
    r.m[13] = y;
    r.m[14] = z;

    return r;
}

bk_mat4 bk_mat4_scale(float x, float y, float z) {
    bk_mat4 r = {0};
    r.m[0] = x;
    r.m[5] = y;
    r.m[10] = z;
    r.m[15] = 1.0f;

    return r;
}

bk_mat4 bk_mat4_rotate_x(float angle_rad) {
    float c = bk_cos(angle_rad);
    float s = bk_sin(angle_rad);

    bk_mat4 r = bk_mat4_identity();
    r.m[5]  = c;
    r.m[6]  = -s;
    r.m[9]  = s;
    r.m[10] = c;

    return r;
}

bk_mat4 bk_mat4_rotate_y(float angle_rad) {
    float c = bk_cos(angle_rad);
    float s = bk_sin(angle_rad);

    bk_mat4 r = bk_mat4_identity();
    r.m[0]  = c;
    r.m[2]  = s;
    r.m[8]  = -s;
    r.m[10] = c;

    return r;
}

bk_mat4 bk_mat4_rotate_z(float angle_rad) {
    float c = bk_cos(angle_rad);
    float s = bk_sin(angle_rad);

    bk_mat4 r = bk_mat4_identity();
    r.m[0] = c;
    r.m[4] = -s;
    r.m[1] = s;
    r.m[5] = c;

    return r;
}

bk_mat4 bk_mat4_mul(bk_mat4 a, bk_mat4 b) {
    bk_mat4 r = {0};
    for (int col = 0; col < 4; ++col) {
        for (int row = 0; row < 4; ++row) {
            for (int k = 0; k < 4; ++k) {
                r.m[col * 4 + row] += a.m[k * 4 + row] * b.m[col * 4 + k];
            }
        }
    }

    return r;
}