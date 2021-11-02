#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <cmath>
#include <entt/entt.hpp>
#include <GL/gl.h>

#include "fwd.hpp"

#include "runner_context.h"

class GLFWwindow;

class Runner {
	public:
		Runner(GLFWwindow *glfw_window, const int width, const int height);

		~Runner() noexcept;

		const int run();


		virtual void windowSizeChanged(int width, int height) = 0;

	protected:
		int m_width;
		int m_height;
		GLFWwindow *m_glfw_window;

		// TODO these entt references should be in the implementing Runner classes
		entt::registry m_registry;
		entt::dispatcher m_dispatcher;

		Runner() = delete;

        virtual void init(const RunnerContext& context) = 0;

		virtual void update(const RunnerContext& context) = 0;

		virtual void render() = 0;

	private:
		void doRender();
};

#endif //CORE_GAME_H

