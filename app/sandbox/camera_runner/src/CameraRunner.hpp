#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <core.h>
#include <shader.h>

#include <entt/entt.hpp>

class CameraRunner : public Runner {
	public:
		CameraRunner(GLFWwindow *window, const int width, const int height) : Runner(window, width, height) {
				File vert = load_file(RES_PATH("shaders/scene.basic.vert"));
				File frag = load_file(RES_PATH("shaders/scene.basic.frag"));
				Shader shader;
				shader.load((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size);
				shader.use();

				float vertices[] = {
					-0.5f, -0.5f, -0.5f,
					 0.5f, -0.5f, -0.5f,
					 0.5f,  0.5f, -0.5f,
					 0.5f,  0.5f, -0.5f,
					-0.5f,  0.5f, -0.5f,
					-0.5f, -0.5f, -0.5f,
					-0.5f, -0.5f,  0.5f,
					 0.5f, -0.5f,  0.5f,
					 0.5f,  0.5f,  0.5f,
					 0.5f,  0.5f,  0.5f,
					-0.5f,  0.5f,  0.5f,
					-0.5f, -0.5f,  0.5f,
					-0.5f,  0.5f,  0.5f,
					-0.5f,  0.5f, -0.5f,
					-0.5f, -0.5f, -0.5f,
					-0.5f, -0.5f, -0.5f,
					-0.5f, -0.5f,  0.5f,
					-0.5f,  0.5f,  0.5f,
					 0.5f,  0.5f,  0.5f,
					 0.5f,  0.5f, -0.5f,
					 0.5f, -0.5f, -0.5f,
					 0.5f, -0.5f, -0.5f,
					 0.5f, -0.5f,  0.5f,
					 0.5f,  0.5f,  0.5f,
					-0.5f, -0.5f, -0.5f,
					 0.5f, -0.5f, -0.5f,
					 0.5f, -0.5f,  0.5f,
					 0.5f, -0.5f,  0.5f,
					-0.5f, -0.5f,  0.5f,
					-0.5f, -0.5f, -0.5f,
					-0.5f,  0.5f, -0.5f,
					 0.5f,  0.5f, -0.5f,
					 0.5f,  0.5f,  0.5f,
					 0.5f,  0.5f,  0.5f,
					-0.5f,  0.5f,  0.5f,
					-0.5f,  0.5f, -0.5f,
				};

				vbo.storeData(vertices, sizeof(vertices));
				vao.createAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *) 0);

				glEnable(GL_DEPTH_TEST);
		}

	protected:
		void update(const double time) override {
		}

		void render() override {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		void windowSizeChanged(int width, int height) override {
		}

	private:
		Vao vao;
		Vbo vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
		UniformMatrix4f mvp_matrix = UniformMatrix4f("mvp_matrix");
};

#endif // SIMULATION_HPP
