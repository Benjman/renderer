#ifndef GLFW_IMPLEMENTATION
#define GLFW_IMPLEMENTATION

#include "glfw.h"
#include <stdexcept>

extern GLFWwindow *initializeGlfw(const char *title, int width, int height, bool headless) {
    if (!glfwInit())
        return nullptr;

    static GLFWwindow *glfwWindow;

    if (glfwWindow != nullptr)
        return nullptr;

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    if (headless)
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!glfwWindow)
        throw std::runtime_error("Failed to create GLFW window");

    glfwMakeContextCurrent(glfwWindow);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize glad");

    return glfwWindow;
}

extern void destroyGlfw(GLFWwindow *window) {
    if (window == nullptr)
        glfwDestroyWindow(window);
    glfwTerminate();
    window = nullptr;
}

extern double_t getRuntimeSeconds() {
    return glfwGetTime();
}

extern bool glfwShouldClose(GLFWwindow *window) {
    return glfwWindowShouldClose(window);
}

extern void glfwSwapBuffers(const GLFWwindow *window) {
    glfwSwapBuffers(window);
}


#endif // GLFW_IMPLEMENTATION
