#include <core/glfw.h>

#include <stdexcept>

extern GLFWwindow* initializeGlfw(const char* title, display_profile_t display_profile, bool headless) {
    size_t width = window::find_display_profile_width(display_profile);
    size_t height = window::find_display_profile_height(display_profile);
    return initializeGlfw(title, width, height, headless);
}

extern GLFWwindow* initializeGlfw(const char* title, int width, int height, bool headless) {
	if (!glfwInit())
		throw std::runtime_error("Failed to initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if (headless)
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	GLFWwindow* glfw_window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (!glfw_window)
		throw std::runtime_error("Failed to create GLFW window");

	glfwMakeContextCurrent(glfw_window);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		throw std::runtime_error("Failed to initialize glad");

	return glfw_window;
}

extern void destroyGlfw(GLFWwindow* glfw_window) {
	if (glfw_window == nullptr)
		glfwDestroyWindow(glfw_window);
	glfwTerminate();
	glfw_window = nullptr;
}

extern double_t getRuntimeSeconds() {
	return glfwGetTime();
}

extern bool glfwShouldClose(GLFWwindow* glfw_window) {
	return glfwWindowShouldClose(glfw_window);
}

extern void glfwSwapBuffers(const GLFWwindow* glfw_window) {
	glfwSwapBuffers(glfw_window);
}

