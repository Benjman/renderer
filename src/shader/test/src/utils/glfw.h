#ifndef TEXT_TEST_UTILS_GLFW_H
#define TEXT_TEST_UTILS_GLFW_H

#ifndef GL_LOADED
#define GL_LOADED

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#endif // GL_LOADED

#include <ctgmath> // for double_t

extern GLFWwindow *initializeGlfw(const char *title, int width, int height, bool headless = false);

extern void destroyGlfw(GLFWwindow *window);

extern double getRuntimeSeconds();

extern bool glfwShouldClose(GLFWwindow *window);

extern void glfwSwapBuffers(const GLFWwindow *window);

#endif // TEXT_TEST_UTILS_GLFW_H
