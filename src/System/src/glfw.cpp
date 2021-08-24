#include "../include/glfw.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

GLFWwindow *glfwWindow = nullptr;

GLFWwindow *initializeGlfw(const char *title, size_t width, size_t height, bool headless) {
	if (!glfwInit()) {
		return nullptr;
	}

	if (glfwWindow != nullptr)
		return nullptr;

	if (!glfwInit())
		throw std::runtime_error("Failed to initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_VISIBLE, !headless);

	glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!glfwWindow)
		throw std::runtime_error("Failed to create GLFW window");

	glfwMakeContextCurrent(glfwWindow);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		throw std::runtime_error("Failed to initialize glad");

	return glfwWindow;
}

void destroyGlfw() {
	if (glfwWindow == nullptr)
		glfwDestroyWindow(glfwWindow);
	glfwTerminate();
	glfwWindow = nullptr;
	return;
}

double_t getRuntimeSeconds() {
	return glfwGetTime();
}

bool glfwShouldClose() {
	return glfwWindowShouldClose(glfwWindow);
}

void glfwSwapBuffers() {
	glfwSwapBuffers(glfwWindow);
}
