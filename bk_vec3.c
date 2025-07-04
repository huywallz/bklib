#include "bk_math.h"
#include "bk_vec3.h"

bk_vec3 bk_vec3_new(float x, float y, float z) {
    return (bk_vec3){x, y, z};
}

bk_vec3 bk_vec3_add(bk_vec3 a, bk_vec3 b) {
    return (bk_vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

bk_vec3 bk_vec3_sub(bk_vec3 a, bk_vec3 b) {
    return (bk_vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

bk_vec3 bk_vec3_scale(bk_vec3 v, float s) {
    return (bk_vec3){v.x * s, v.y * s, v.z * s};
}

float bk_vec3_dot(bk_vec3 a, bk_vec3 b) {
    return a.x * b.y + a.y * b.y + a.z * b.z;
}

bk_vec3 bk_vec3_cross(bk_vec3 a, bk_vec3 b) {
    return (bk_vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

float bk_vec3_length(bk_vec3 v) {
    return bk_sqrt(bk_vec3_dot(v, v));
}

bk_vec3 bk_vec3_normalize(bk_vec3 v) {
    float len = bk_vec3_length(v);
    if (len == 0.0f) return BK_VEC3_ZERO;
    return bk_vec3_scale(v, 1.0f / len);
}