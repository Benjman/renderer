#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <Core/File.h>
#include <Core/Game.h>
#include <Core/Texture.h>
#include <Shader.h>
#include <Text.h>

class CameraRunner : public Game {
	public:
		CameraRunner(GLFWwindow *window, const int width, const int height) : Game(window, width, height) {
			const GLfloat vertices[] = {
				// positions
				1.f, 1.f, 0.f,
				1.f, -1.f, 0.f,
				-1.f, -1.f, 0.f,
				-1.f, 1.f, 0.f,

				// tex coords
				1.0f, 1.0f,
				1.0f, 0.0f,
				0.0f, 0.0f,
				0.0f, 1.0f,
			};

			const GLuint indices[] = {
				1, 2, 3,
				0, 1, 3,
			};

			File vert = load_file(RES_PATH("shaders/basic.vert"));
			File frag = load_file(RES_PATH("shaders/basic.frag"));
			Shader::createShader((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size).use();

			Vao *vao = Vao::createVao();
			Vbo::createVbo(vao, GL_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(vertices), vertices);
			Vbo::createVbo(vao, GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(indices), indices);
			VertexAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *) 0, true);
			VertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void *) (12 * sizeof(GLfloat)), true);

			Font dejavu_font;
			GLuint texture_id = load_font(dejavu_font, RES_PATH("fonts/DejaVuSans.ttf"));
			Texture texture(GL_TEXTURE_2D, 0, GL_RED, ATLAS_WIDTH, ATLAS_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE, texture_id);
			texture.bind();
			texture.parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
			texture.parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
			texture.parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			texture.parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

	protected:
		void update(const double time) override {
		}

		void render() override {
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
