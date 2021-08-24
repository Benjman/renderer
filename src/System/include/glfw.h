#ifndef SYSTEM_GLFW_H
#define SYSTEM_GLFW_H

#include <math.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

extern GLFWwindow *glfwWindow;

GLFWwindow *initializeGlfw(const char *title = "", size_t width = 0, size_t height = 0, bool headless = false);

void destroyGlfw();

double_t getRuntimeSeconds();

#endif // SYSTEM_GLFW_H
