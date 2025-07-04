#include "bk_math3d.h"

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

bk_mat4 bk_mat4_lookat(bk_vec3 eye, bk_vec3 center, bk_vec3 up) {
    bk_vec3 f = bk_vec3_normalize(bk_vec3_sub(center, eye));
    bk_vec3 s = bk_vec3_normalize(bk_vec3_cross(f, up));
    bk_vec3 u = bk_vec3_cross(s, f);

    bk_mat4 r = bk_mat4_identity();

    r.m[0] = s.x;
    r.m[1] = u.x;
    r.m[2] = -f.x;
    r.m[3] = 0.0f;

    r.m[4] = s.y;
    r.m[5] = u.y;
    r.m[6] = -f.y;
    r.m[7] = 0.0f;

    r.m[8]  = s.z;
    r.m[9]  = u.z;
    r.m[10] = -f.z;
    r.m[11] = 0.0f;

    r.m[12] = -bk_vec3_dot(s, eye);
    r.m[13] = -bk_vec3_dot(u, eye);
    r.m[14] = bk_vec3_dot(f, eye);
    r.m[15] = 1.0f;

    return r;
}