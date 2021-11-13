#ifndef CORE_GLFW_H
#define CORE_GLFW_H

#ifndef GL_LOADED
#define GL_LOADED

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#endif // GL_LOADED

#include <core/window.h>

extern GLFWwindow* initializeGlfw(const char* title, display_profile_t display_profile, bool headless = false);

extern GLFWwindow* initializeGlfw(const char* title, int width, int height, bool headless = false);

extern void destroyGlfw(GLFWwindow* glfw_window);

extern double_t getRuntimeSeconds();

extern bool glfwShouldClose(GLFWwindow* glfw_window);

extern void glfwSwapBuffers(const GLFWwindow* glfw_window);

#endif // CORE_GLFW_H
