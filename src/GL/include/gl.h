#ifndef GL_H
#define GL_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <cmath>

extern GLFWwindow *initializeGlfw(const char *title, int width, int height, bool headless = false);

extern void destroyGlfw(GLFWwindow *window);

extern double_t getRuntimeSeconds();

extern bool glfwShouldClose(GLFWwindow *window);

extern void glfwSwapBuffers(const GLFWwindow *window);

#endif // GL_H
