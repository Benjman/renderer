#include <iostream>

#include "utils/glfw.h"

#include <Core/Runner.h>

inline void keyHandler(GLFWwindow*,int,int,int,int);
inline void windowSizeChangeHandler(GLFWwindow*,int,int);
inline static Runner *INSTANCE; // TODO refactor so there is a global map of GLFWwindows and Runners

Runner::Runner(GLFWwindow *window, const int width, const int height) : m_window(window), m_width(width), m_height(height) {
	INSTANCE = this;
	glfwSetKeyCallback(m_window, keyHandler);
	glfwSetWindowSizeCallback(m_window, windowSizeChangeHandler);
}

Runner::~Runner() noexcept {
	glfwTerminate();
}

const int Runner::run() {
	const constexpr double dt = 1. / 60.;

	double time = 0.;
	double accumulator = 0.;
	double current_time = getRuntimeSeconds();
	double new_time = 0.;
	double frame_time = 0.;

	while (!glfwWindowShouldClose(m_window)) {
		new_time = getRuntimeSeconds();
		frame_time = new_time - current_time;
		current_time = new_time;

		accumulator += frame_time;

		while (accumulator >= dt) {
			update(accumulator);

			accumulator -= dt;
			time += dt;
		}

		doRender();
		glfwPollEvents();
	}

	return EXIT_SUCCESS;
}

void Runner::doRender() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	render();
	glfwSwapBuffers(m_window);
}

inline void keyHandler(GLFWwindow*, int key, int scancode, int action, int mods) {
	if (action == GLFW_REPEAT) return;
	INSTANCE->keyEvent(key, action);
}

inline void windowSizeChangeHandler(GLFWwindow*, int w, int h) {
	INSTANCE->windowSizeChanged(w, h);
}