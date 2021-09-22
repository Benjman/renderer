#ifndef TEXT_TEST_UTILS_GLFW_H
#define TEXT_TEST_UTILS_GLFW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

extern GLFWwindow* initializeGlfw(const char *title, int width, int height, bool headless);

extern void destroyGlfw(GLFWwindow *window);

#endif //#ifndef TEXT_TEST_UTILS_GLFW_H
