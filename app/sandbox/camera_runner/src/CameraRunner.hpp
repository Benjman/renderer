#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <camera.h>
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

				camera.update_orthogonal_matrix(640, 480, 0.1, 10.0);

				mvp_matrix.storeLocation(shader);
				mvp_matrix.load(camera.m_proj * camera.m_view);
		}

	protected:
		void update(const double time) override {
				camera.m_position += glm::vec3(0, 1 * time, 0);
				camera.update_view_matrix();
				mvp_matrix.load(camera.m_proj * camera.m_view);
		}

		void render() override {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		void keyEvent(int key, int mode) override {
		}

		void windowSizeChanged(int width, int height) override {
		}

	private:
		Vao vao;
		Vbo vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
		Camera camera;
		UniformMatrix4f mvp_matrix = UniformMatrix4f("mvp_matrix");
};

#endif // SIMULATION_HPP
