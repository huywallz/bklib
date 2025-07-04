// bk_math.h
// Core math utility functions for 3D graphics

#ifndef BK_MATH_H
#define BK_MATH_H

#define BK_PI 3.14159265358979323846f

float bk_sin(float x);
float bk_cos(float x);
float bk_tan(float x);
float bk_atan2(float y, float x);
float bk_acos(float x);
float bk_sqrt(float x);
float bk_rad(float deg);
float bk_deg(float rad);
float bk_round(float x);
float bk_floor(float x);
float bk_ceil(float x);
float bk_abs(float x);
float bk_min(float x, float y);
float bk_max(float x, float y);
float bk_clamp(float x, float min, float max);
float bk_lerp(float x, float y, float t);

#endif