#include <iostream>

#include <Core/Game.h>
#include <Core/input/InputEvents.h>
#include <Shader.h>

#include "./components/Ball.h"
#include "./components/Block.h"
#include "./components/Player.h"
#include "./components/Position.h"
#include "./components/Sprite.h"

#include "./systems/CollisionSystem.h"
#include "./systems/MoveSystem.h"
#include "./systems/RenderSystem.h"

const char *vertShader = "#version 330 core\n"
						 "layout (location = 0) in vec3 in_pos;"
						 "layout (location = 1) in vec2 in_texCoord;"
						 "out vec2 pass_texCoord;"
						 "void main() {"
						 "    pass_texCoord = in_texCoord;"
						 "    gl_Position = vec4(in_pos, 1.0);"
						 "}\0";
const char *fragShader = "#version 330 core\n"
						 "in vec2 pass_texCoord;"
						 "out vec4 out_color;"
						 "uniform sampler2D u_tex;"
						 "void main() {"
						 "    out_color = texture(u_tex, pass_texCoord);"
						 "}\0";

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


class Breakout : public Game {
	public:
		Breakout(GLFWwindow *window, const int width, const int height) : Game(window, width, height) {
			Shader::createShader(vertShader, fragShader).use();
			Vao *vao = Vao::createVao();
			Vbo::createVbo(vao, GL_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(vertices), vertices);
			Vbo::createVbo(vao, GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(indices), indices);
			VertexAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *) 0, true);
			VertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void *) (12 * sizeof(GLfloat)), true);

			// Generate texture
			GLuint texId;
			glGenTextures(1, &texId);
			glBindTexture(GL_TEXTURE_2D, texId);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			render_system.setViewport(width, height);
			move_system.setSize(width, height);

			const auto ball = m_registry.create();
			m_registry.emplace<Ball>(ball, -80, -80);
			m_registry.emplace<Position>(ball, 220, 250);
			m_registry.emplace<Sprite>(ball, 10, glm::vec3(0, 1, 0));

			const auto player = m_registry.create();
			m_registry.emplace<Player>(player, 150);
			m_registry.emplace<Position>(player, 38, 50);
			m_registry.emplace<Sprite>(player, 150, 10, glm::vec3(0, 1, 1));

			auto rows = 8;
			auto cols = 15;
			for (auto row = 0; row < rows; row++) {
				for (auto col = 0; col < cols; col++) {
					const auto x = (col + 1.) / cols * width;
					const auto y = ((row + 1.) / rows * height) + 50;

					const auto brick = m_registry.create();
					m_registry.emplace<Block>(brick, 1);
					m_registry.emplace<Position>(brick, x, y);
					m_registry.emplace<Sprite>(brick, 25, 15, glm::vec3(.8, .5, .5));
					collideables.blocks.emplace_back(brick);
				}
			}

			// Assign events to systems.
			m_dispatcher.sink<KeyDown>().connect<&MoveSystem::on_key_down>(move_system);
			m_dispatcher.sink<KeyUp>().connect<&MoveSystem::on_key_up>(move_system);

			collideables.ball = ball;
			collideables.player = player;
			collideables.registry = &m_registry;
		}

	protected:
		void update(const double time) override {
			move_system.update(time, m_registry);
			collision_system.update(time, collideables);
		}

		void render() override {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			render_system.render(m_registry);

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

	private:
		CollisionHolder collideables;
		CollisionSystem collision_system;
		MoveSystem move_system;
		RenderSystem render_system;
};
