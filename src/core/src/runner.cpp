#include "core/window.h"
#include "utils/glfw.h"

#include <core.h>

#include <GLFW/glfw3.h>

#include <spdlog/common.h>
#include <spdlog/spdlog.h>

inline void keyHandler(GLFWwindow*,int32_t,int32_t,int32_t,int32_t);
inline void windowSizeChangeHandler(GLFWwindow*,int32_t,int32_t);
inline static Runner *INSTANCE; // TODO refactor so there is a global map of GLFWwindows and Runners

Runner::Runner(GLFWwindow *glfw_window, const int32_t width, const int32_t height) : m_glfw_window(glfw_window), m_width(width), m_height(height) {
	INSTANCE = this;
	glfwSetKeyCallback(m_glfw_window, keyHandler);
	glfwSetWindowSizeCallback(m_glfw_window, windowSizeChangeHandler);
    window::update(width, height);

    spdlog::set_level(spdlog::level::info);
}

Runner::~Runner() noexcept {
	glfwTerminate();
}

const int32_t Runner::run() {
	const constexpr double_t dt = 1.0 / 60.0;

    RunnerContext context(m_registry, m_dispatcher);

	double_t time = 0.0;
	double_t accumulator = 0.0;
	double_t current_time = getRuntimeSeconds();
	double_t new_time = 0.0;
	double_t frame_time = 0.0;

	while (!glfwWindowShouldClose(m_glfw_window)) {
		glfwPollEvents();

		new_time = getRuntimeSeconds();
		frame_time = new_time - current_time;
		current_time = new_time;

		accumulator += frame_time;
        context.running = new_time;

		while (accumulator >= dt) {
            context.delta = accumulator;
			update(context);

			accumulator -= dt;
			time += dt;
		}

		doRender();
        input::reset();
	}

	return EXIT_SUCCESS;
}

void Runner::doRender() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	render();
	glfwSwapBuffers(m_glfw_window);
}

inline void keyHandler(GLFWwindow*, int32_t key, int32_t scancode, int32_t action, int32_t mods) {
	if (action == GLFW_REPEAT) return;
    input::key_event(key, scancode, action, mods);
}

inline void windowSizeChangeHandler(GLFWwindow*, int32_t w, int32_t h) {
	INSTANCE->windowSizeChanged(w, h);
    window::update(w, h);
}
