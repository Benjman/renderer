// TODO fixme -- this runner isn't displaying anything
#ifndef PONG_PONG_H
#define PONG_PONG_H

#include <core/events.h>
#include <core/file.h>
#include <core/runner.h>
#include <core/components/position2d.h>
#include <core/input.h>
#include <shader.h>

#include "components/all.h"
#include "systems/ai_system.h"
#include "systems/collision_system.h"
#include "systems/move_system.h"
#include "systems/render_system.h"

#include <iostream>

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

class PongRunner : public Runner {
	Texture texture = Texture(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_FLOAT);

	public:
		PongRunner(GLFWwindow *window, const int width, const int height) : Runner(window, width, height), m_texture(std::vector<GLfloat>(width * height * 3)) {
			File vert = load_file(RES_PATH(shaders/basic.vert));
			File frag = load_file(RES_PATH(shaders/basic.frag));
			Shader shader;
			shader.load((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size);
			shader.use();

			Vao vao;
			Vbo vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(vertices), vertices, &vao);
			Vbo ebo(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(indices), indices, &vao);
			VertexAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *) 0);
			VertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void *) (12 * sizeof(GLfloat)));

			texture.bind();
			texture.parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
			texture.parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
			texture.parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			texture.parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			// Here, we are creating the entities using EnTT and attaching the relevant components and tags.
			// We can invoke the constructor of the component or tag in the assign() and attach() methods of the registry.

			const auto player_paddle = m_registry.create();
			const auto ai_paddle = m_registry.create();
			const auto ball = m_registry.create();

			// Assign component data to entities.
			m_registry.emplace<Sprite>(player_paddle, 12, 96, glm::vec3(1.));
			m_registry.emplace<Position2D>(player_paddle, 20., height - 20.);
			m_registry.emplace<Player>(player_paddle);

			m_registry.emplace<Sprite>(ai_paddle, 12, 96, glm::vec3(1.));
			m_registry.emplace<Position2D>(ai_paddle, width - 30., 20.);
			m_registry.emplace<AI>(ai_paddle, width - 30, 20);

			m_registry.emplace<Sprite>(ball, 8, glm::vec3(1.));
			m_registry.emplace<Position2D>(ball, (width / 2.) - 16., (height / 2.) - 16.);
			m_registry.emplace<Ball>(ball, MoveSystem::BALL_SPEED, MoveSystem::BALL_SPEED);

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
		void init(const RunnerContext& context) override {
		}

		void update(const RunnerContext& context) override {
            if (input::any_key_pressed()) {
                m_dispatcher.trigger<KeyDown>(input::last_key_pressed());
            }
            if (input::any_key_released()) {
                m_dispatcher.trigger<KeyUp>(input::last_key_released());
            }

            move_system.update(context.delta, m_registry);
            ai_system.update(context.delta, m_registry);
            collision_system.update(context.delta, collideables);
		}

		void render() override {
			render_system.render(m_registry, m_width, m_height, m_texture);
			texture.upload(&m_texture.at(0));
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

		void windowSizeChanged(int width, int height) override {
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
