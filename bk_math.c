#include <math.h>

#include "bk_math.h"

float bk_sin(float x) {
    return sinf(x);
}

float bk_cos(float x) {
    return cosf(x);
}

float bk_tan(float x) {
    return tanf(x);
}

float bk_atan2(float y, float x) {
    return atan2f(y, x);
}

float bk_acos(float x) {
    return acosf(x);
}

float bk_sqrt(float x) {
    return sqrtf(x);
}

float bk_rad(float deg) {
    return deg * (BK_PI / 180.0f);
}

float bk_deg(float rad) {
    return rad * (180.0f / BK_PI);
}

float bk_round(float x) {
    return roundf(x);
}

float bk_floor(float x) {
    return floorf(x);
}

float bk_ceil(float x) {
    return ceilf(x);
}

float bk_abs(float x) {
    if (x < 0) return -x;
    return x;
}

float bk_min(float x, float y) {
    if (x > y) return y;
    else return x;
}

float bk_max(float x, float y) {
    if (x < y) return y;
    return x;
}

float bk_clamp(float x, float min, float max) {
    return bk_max(min, bk_min(x, max));
}

float bk_lerp(float x, float y, float t) {
    return x + t * (y - x);
}