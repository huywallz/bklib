#include "bk_math.h"
#include "bk_math3d.h"
#include "bk_freecam.h"

bk_vec3 bk_freecam_get_forward(const bk_freecam* cam) {
    float yaw = bk_rad(cam->yaw);
    float pitch = bk_rad(cam->pitch);

    float x = bk_cos(pitch) * bk_cos(yaw);
    float y = bk_sin(pitch);
    float z = bk_cos(pitch) * bk_sin(yaw);

    return bk_vec3_normalize((bk_vec3){x, y, z});
}

bk_vec3 bk_freecam_get_right(const bk_freecam* cam) {
    return bk_vec3_normalize(bk_vec3_cross(bk_freecam_get_forward(cam), (bk_vec3){0.0f, 1.0f, 0.0f}));
}

bk_vec3 bk_freecam_get_up(const bk_freecam* cam) {
    bk_vec3 forward = bk_freecam_get_forward(cam);
    bk_vec3 right = bk_freecam_get_right(cam);

    return bk_vec3_normalize(bk_vec3_cross(right, forward));
}

bk_mat4 bk_freecam_get_view(const bk_freecam* cam) {
    bk_vec3 forward = bk_freecam_get_forward(cam);
    bk_vec3 target = bk_vec3_add(cam->pos, forward);
    bk_vec3 up = {0.0f, 1.0f, 0.0f};

    return bk_mat4_lookat(cam->pos, target, up);
}

void bk_freecam_init(bk_freecam* cam, bk_vec3 pos) {
    cam->pos = pos;
    cam->yaw = 0.0f;
    cam->pitch = 0.0f;
}

void bk_freecam_rotate(bk_freecam* cam, float dx, float dy, float sensitivity) {
    cam->yaw += dx * sensitivity;
    cam->pitch += dy * sensitivity;
    cam->pitch = bk_clamp(cam->pitch, -89.0f, 89.0f);
}

void bk_freecam_move(bk_freecam* cam, bk_vec3 dir, float speed) {
    bk_vec3 forward = bk_freecam_get_forward(cam);
    bk_vec3 right = bk_freecam_get_right(cam);
    bk_vec3 up = bk_freecam_get_up(cam);

    cam->pos = bk_vec3_add(cam->pos, bk_vec3_scale(forward, dir.z * speed));
    cam->pos = bk_vec3_add(cam->pos, bk_vec3_scale(right, dir.x * speed));
    cam->pos = bk_vec3_add(cam->pos, bk_vec3_scale(up, dir.y * speed));
}