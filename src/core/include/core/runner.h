#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <cmath>
#include <entt/entt.hpp>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "events.h"
#include "input.h"

struct RunnerContext {
	double_t delta;
    double_t running;
	entt::registry& registry;
	entt::dispatcher& dispatcher;
    InputState& input;

    RunnerContext(entt::registry& registry, entt::dispatcher& dispatcher, InputState& input)
        : registry(registry), dispatcher(dispatcher), input(input)
    { }

};

class Runner {
	public:
        InputState m_input;

		Runner(GLFWwindow *window, const int width, const int height);

		~Runner() noexcept;

		const int run();


		virtual void windowSizeChanged(int width, int height) = 0;

	protected:
		int m_width;
		int m_height;
		GLFWwindow *m_window;

		// TODO these entt references should be in the implementing Runner classes
		entt::registry m_registry;
		entt::dispatcher m_dispatcher;

		Runner() = delete;

		virtual void update(const RunnerContext& context) = 0;

		virtual void render() = 0;

	private:
		void doRender();
};

#endif //CORE_GAME_H

