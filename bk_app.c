// still in working progress..

#include <GLFW/glfw3.h>

#include "bk_app.h"
#include "bk_vec2_type.h"

GLFWwindow* __window;

void bk_app_init(int width, int height, const char* title) {
    glfwInit();
    __window = glfwCreateWindow(width, height, title, NULL, NULL);
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(__window, (mode->width - width) / 2, (mode->height - height) / 2);
    glfwSwapInterval(1);
    glfwMakeContextCurrent(__window);
}

void bk_app_close() {
    glfwTerminate();
}

int bk_app_window_closed() {
    return glfwWindowShouldClose(__window);
}

void bk_app_window_update() {
    glfwSwapBuffers(__window);
}

void bk_app_set_cursor_mode(bk_app_cursor_mode mode) {
    switch (mode) {
        case BK_CURSOR_NORMAL: {
            glfwSetInputMode(__window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        } break;
        case BK_CURSOR_HIDDEN: {
            glfwSetInputMode(__window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        } break;
        case BK_CURSOR_DISABLED: {
            glfwSetInputMode(__window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        } break;
    }
}