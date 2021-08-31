#include "../include/Core/Game.h"
#include <gl.h>

inline void gameKeyCallback(GLFWwindow*,int,int,int,int);
inline static Game *INSTANCE; // TODO refactor so there is a global map of GLFWwindows and Games

Game::Game(GLFWwindow *window, const int width, const int height) : m_window(window), m_width(width), m_height(height) {
	glfwSetKeyCallback(m_window, gameKeyCallback);
	INSTANCE = this;
}

Game::~Game() noexcept {
	glfwTerminate();
}

const int Game::run() {
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

		render();
		glfwPollEvents();
	}

	return EXIT_SUCCESS;
}

inline void gameKeyCallback(GLFWwindow*, int key, int scancode, int action, int mods) {
	if (action == GLFW_REPEAT) return;
	INSTANCE->keyEvent(key, action);
}
