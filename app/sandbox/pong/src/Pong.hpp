#ifndef PONG_PONG_H
#define PONG_PONG_H

#include <Core/Game.h>
#include <Core/input//InputEvents.h>
#include <Shader.h>

#include "components/All.h"
#include "systems/AISystem.h"
#include "systems/CollisionSystem.h"
#include "systems/MoveSystem.h"
#include "systems/RenderSystem.h"

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

class Pong : public Game {
	public:
		Pong(GLFWwindow *window, const int width, const int height) : Game(window, width, height), m_texture(std::vector<GLfloat>(width * height * 3)) {
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

			// Here, we are creating the entities using EnTT and attaching the relevant components and tags.
			// We can invoke the constructor of the component or tag in the assign() and attach() methods of the registry.

			const auto player_paddle = m_registry.create();
			const auto ai_paddle = m_registry.create();
			const auto ball = m_registry.create();

			// Assign component data to entities.
			m_registry.emplace<Sprite>(player_paddle, 12, 96, glm::vec3(1.));
			m_registry.emplace<Position>(player_paddle, 20., height - 20.);
			m_registry.emplace<Player>(player_paddle);

			m_registry.emplace<Sprite>(ai_paddle, 12, 96, glm::vec3(1.));
			m_registry.emplace<Position>(ai_paddle, width - 30., 20.);
			m_registry.emplace<AI>(ai_paddle, width - 30, 20);

			m_registry.emplace<Sprite>(ball, 8, glm::vec3(1.));
			m_registry.emplace<Position>(ball, (width / 2.) - 16., (height / 2.) - 16.);
			m_registry.emplace<Ball>(ball, BALL_SPEED, BALL_SPEED);

			// Assign events to systems.
			m_dispatcher.sink<KeyDown>().connect<&MoveSystem::on_key_down>(move_system);
			m_dispatcher.sink<KeyUp>().connect<&MoveSystem::on_key_up>(move_system);

			// Set up collideables
			collideables.ai = ai_paddle;
			collideables.player = player_paddle;
			collideables.ball = ball;
			collideables.registry = &m_registry;
		}

	protected:
		void update(const double time) override {
			move_system.update(time, m_registry);
			ai_system.update(time, m_registry);
			collision_system.update(time, collideables);
		}

		void render() override {
			render_system.render(m_registry, m_width, m_height, m_texture);
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

	private:
		AISystem ai_system;
		CollisionSystem collision_system;
		CollisionHolder collideables;
		MoveSystem move_system;
		RenderSystem render_system;
		std::vector<GLfloat> m_texture;

};

#endif // PONG_PONG_H
