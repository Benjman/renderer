#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <Core/Game.h>

class CameraRunner : public Game {
	public:
		CameraRunner(GLFWwindow *window, const int width, const int height) : Game(window, width, height) {
		}

	protected:
		void update(const double time) override {
		}

		void render() override {
			// render_system.render(m_registry, m_width, m_height, m_texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_FLOAT, &m_texture.at(0));

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		void keyEvent(int key, int mode) override {
			if (mode == GLFW_PRESS) {
				m_dispatcher.trigger<KeyDown>(key);
			} else {
				m_dispatcher.trigger<KeyUp>(key);
			}
		}

		void windowSizeChanged(int width, int height) override {
		}

};

#endif // SIMULATION_HPP
