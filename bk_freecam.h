// bk_freecam.h
// Free camera movement and orientation control for 3D navigation

#ifndef BK_FREECAM_H
#define BK_FREECAM_H

#include "bk_vec3_type.h"
#include "bk_mat4_type.h"

typedef struct {
    bk_vec3 pos;
    float pitch;
    float yaw;
} bk_freecam;

bk_vec3 bk_freecam_get_forward(const bk_freecam* cam);
bk_vec3 bk_freecam_get_right(const bk_freecam* cam);
bk_vec3 bk_freecam_get_up(const bk_freecam* cam);
bk_mat4 bk_freecam_get_view(const bk_freecam* cam);

void bk_freecam_init(bk_freecam* cam, bk_vec3 pos);
void bk_freecam_rotate(bk_freecam* cam, float dx, float dy, float sensitivity);
void bk_freecam_move(bk_freecam* cam, bk_vec3 dir, float speed);

#endif