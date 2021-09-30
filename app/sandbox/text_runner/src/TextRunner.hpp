#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Text/internal/TextMeshGenerator.h"
#include <Core/File.h>
#include <Core/Runner.h>
#include <Shader.h>
#include <Text.h>

#include <iostream>

class TextRunner : public Runner {
	public:
		TextRunner(GLFWwindow *window, const int width, const int height) : Runner(window, width, height) {
			File text_vert = load_file(RES_PATH("shaders/text.vert"));
			File text_frag = load_file(RES_PATH("shaders/text.frag"));

			text_shader.load((const char*) text_vert.buffer, text_vert.size, (const char*) text_frag.buffer, text_frag.size);
			text_shader.use();

			Font dejavu_font;
			load_font(dejavu_font, RES_PATH("fonts/DejaVuSans.ttf"));
			Texture texture(GL_TEXTURE_2D, 0, GL_RED, ATLAS_WIDTH, ATLAS_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE);
			texture.bind();
			texture.upload(dejavu_font.atlas_data);
			texture.upload(dejavu_font.atlas_data);
			texture.parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
			texture.parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
			texture.parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			texture.parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			text = new Text("Oh this is a test with a longer value to see if the line wrapping works.", &dejavu_font, glm::vec2(), TEXT_ALIGN_LEFT | DISPLAY_PROFILE_640_480 | TEXT_SIZE_32);
			text->generate_mesh();

			text_vao = Vao::createVao();
			text_vao->bind();
			Vbo::createVbo(text_vao, GL_ARRAY_BUFFER, GL_STATIC_DRAW, text->v_buffer_size, text->v_buffer);
			Vbo::createVbo(text_vao, GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, text->i_buffer_size, text->i_buffer);
			VertexAttribute(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) 0);
			VertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


			// // debug rows
			// float debug_buffer[] = {
			// 	// positions      // texture coords
			// 	1.0f,  1.0f,      1.0f, 1.0f, // top right
			// 	1.0f, -1.0f,      1.0f, 0.0f, // bottom right
			// 	-1.0f, -1.0f,     0.0f, 0.0f, // bottom left
			// 	-1.0f,  1.0f,     0.0f, 1.0f  // top left
			// };

			// unsigned int debug_indices[] = {
			// 	0, 1, 3, // first triangle
			// 	1, 2, 3  // second triangle
			// };

			// debug_vao = Vao::createVao();
			// debug_vao->bind();
			// Vbo::createVbo(debug_vao, GL_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(debug_buffer), debug_buffer);
			// Vbo::createVbo(debug_vao, GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(debug_indices), debug_indices);
			// VertexAttribute(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) 0);
			// VertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));
		}

	protected:
		void update(const double time) override {
		}

		void render() override {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			text_shader.use();
			text_vao->bind();
			glDrawElements(GL_TRIANGLES, 6 * text->char_count, GL_UNSIGNED_INT, 0);

			// debug_vao->bind();
			// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		void keyEvent(int key, int mode) override {
		}

		void windowSizeChanged(int width, int height) override {
		}

	private:
		Shader text_shader;
		Vao* text_vao;
		Text* text;

		Vao* debug_vao;
};

#endif // SIMULATION_HPP
