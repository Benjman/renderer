#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <entt/entt.hpp>
#include <gl.h>

#include "Events.h"

class Game {
	public:
		Game(GLFWwindow *window, const int width, const int height);

		~Game() noexcept;

		const int run();

		virtual void keyEvent(int key, int mode) = 0;

		virtual void windowSizeChanged(int width, int height) = 0;

	protected:
		int m_width;
		int m_height;
		GLFWwindow *m_window;
		std::vector<GLfloat> m_texture;
		entt::registry m_registry;
		entt::dispatcher m_dispatcher;

		Game() = delete;

		virtual void update(const double time) = 0;

		virtual void render() = 0;

		void doRender();

};

#endif //CORE_GAME_H

