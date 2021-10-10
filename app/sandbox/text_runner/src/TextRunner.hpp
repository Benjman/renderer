#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <core/file.h>
#include <core/runner.h>
#include <shader.h>
#include <text.h>

#include <iostream>

class TextRunner : public Runner {
	public:
		TextRunner(GLFWwindow *window, const uint32_t width, const uint32_t height) : Runner(window, width, height) {
			File vert = load_file(RES_PATH("shaders/text.vert"));
			File frag = load_file(RES_PATH("shaders/text.frag"));

			Shader shader;
			shader.load((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size);
			shader.use();

			Font font;
			load_font(font, RES_PATH("fonts/DejaVuSans.ttf"));
			Texture texture(GL_TEXTURE_2D, 0, GL_RED, ATLAS_WIDTH, ATLAS_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE);
			texture.bind();
			texture.upload(font.atlas_data);
			texture.parameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			texture.parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			Text text("Oh this is a test with a longer value to see if the line wrapping works.", &font, glm::vec2(), TEXT_ALIGN_LEFT | DISPLAY_PROFILE_640_480 | TEXT_SIZE_32);
			text.generate_mesh();

			vao = new Vao;
			vbo = new Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW, text.v_buffer_size, text.v_buffer, vao);
			ebo = new Vbo(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, text.i_buffer_size, text.i_buffer, vao);
			vao->createAttribute(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) 0);
			vao->createAttribute(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

	protected:
		void update(const double time) override {
		}

		void render() override {
			glDrawElements(GL_TRIANGLES, 6 * text->char_count, GL_UNSIGNED_INT, 0);
		}

		void keyEvent(int key, int mode) override {
		}

		void windowSizeChanged(int width, int height) override {
		}

	private:
		// TODO fixme pointer hell below
		Text* text;
		Vao* vao;
		Vbo* vbo;
		Vbo* ebo;

};

#endif // SIMULATION_HPP
