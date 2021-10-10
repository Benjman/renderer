#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <entt/entt.hpp>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "Events.h"

class Runner {
	public:
		Runner(GLFWwindow *window, const int width, const int height);

		~Runner() noexcept;

		const int run();

		virtual void keyEvent(int key, int mode) = 0;

		virtual void windowSizeChanged(int width, int height) = 0;

	protected:
		int m_width;
		int m_height;
		GLFWwindow *m_window;

		// TODO these entt classes should be in the implementing Runner classes
		entt::registry m_registry;
		entt::dispatcher m_dispatcher;

		Runner() = delete;

		virtual void update(const double time) = 0;

		virtual void render() = 0;

	private:
		void doRender();

};

#endif //CORE_GAME_H

