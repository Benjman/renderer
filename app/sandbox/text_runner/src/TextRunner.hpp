#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Text/internal/TextMeshGenerator.h"
#include <Core/File.h>
#include <Core/Game.h>
#include <Core/Texture.h>
#include <Shader.h>
#include <Text.h>

class TextRunner : public Game {
	public:
		TextRunner(GLFWwindow *window, const int width, const int height) : Game(window, width, height) {
			File vert = load_file(RES_PATH("shaders/text.vert"));
			File frag = load_file(RES_PATH("shaders/text.frag"));
			Shader::createShader((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size).use();

			Font dejavu_font;
			GLuint texture_id = load_font(dejavu_font, RES_PATH("fonts/DejaVuSans.ttf"));
			Texture texture(GL_TEXTURE_2D, 0, GL_RED, ATLAS_WIDTH, ATLAS_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE, texture_id);
			texture.bind();
			texture.parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
			texture.parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
			texture.parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			texture.parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			text = new Text("This is a test.", &dejavu_font, glm::vec2(), TEXT_ALIGN_LEFT | DISPLAY_PROFILE_640_480 | TEXT_SIZE_32);
			text->generate_mesh();

			Vao *vao = Vao::createVao();
			Vbo::createVbo(vao, GL_ARRAY_BUFFER, GL_STATIC_DRAW, text->v_buffer_size, text->v_buffer);
			Vbo::createVbo(vao, GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, text->i_buffer_size, text->i_buffer);
			VertexAttribute(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) 0);
			VertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

	protected:
		void update(const double time) override {
		}

		void render() override {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawElements(GL_TRIANGLES, 6 * text->char_count, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		void keyEvent(int key, int mode) override {
		}

		void windowSizeChanged(int width, int height) override {
		}

	private:
		Text* text;
};

#endif // SIMULATION_HPP
