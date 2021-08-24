#include <vector>
#include <iostream>

#include <Shader.h>

#include "../components/All.h"
#include "../events/KeyDown.h"
#include "../events/KeyUp.h"

#include "Game.h"

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

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

inline static Game *instance;

Game::Game(const char *title, const int width, const int height) : width(width), height(height) {
	instance = this;
	initializeGlfw(title, width, height, false);
	glfwSetKeyCallback(glfwWindow, key_callback);

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

	texture = std::vector<GLfloat>(width * height * 3);

	// Here, we are creating the entities using EnTT and attaching the relevant components and tags.
	// We can invoke the constructor of the component or tag in the assign() and attach() methods of the registry.

	const auto player_paddle = registry.create();
	const auto ai_paddle = registry.create();
	const auto ball = registry.create();

	// Assign component data to entities.
	registry.emplace<Sprite>(player_paddle, 12, 96, glm::vec3(1.));
	registry.emplace<Position>(player_paddle, 20., height - 20.);
	registry.emplace<Player>(player_paddle);

	registry.emplace<Sprite>(ai_paddle, 12, 96, glm::vec3(1.));
	registry.emplace<Position>(ai_paddle, width - 30., 20.);
	registry.emplace<AI>(ai_paddle, width - 30, 20);

	registry.emplace<Sprite>(ball, 8, glm::vec3(1.));
	registry.emplace<Position>(ball, (width / 2.) - 16., (height / 2.) - 16.);
	registry.emplace<Ball>(ball, 35, 35);

	// Assign events to systems.
	dispatcher.sink<KeyDown>().connect<&MoveSystem::on_key_down>(move_system);

	// Set up collideables
	collideables.ai = ai_paddle;
	collideables.player = player_paddle;
	collideables.ball = ball;
	collideables.registry = &registry;
	dispatcher.sink<KeyUp>().connect<&MoveSystem::on_key_up>(move_system);
}

Game::~Game() noexcept {
	glfwTerminate();
}

const int Game::run() {
	const constexpr double dt = 1000. / 60. * .01;

	double time = 0.;
	double accumulator = 0.;
	double current_time = getRuntimeSeconds();
	double new_time = 0.;
	double frame_time = 0.;

	while (!glfwWindowShouldClose(glfwWindow)) {
		new_time = getRuntimeSeconds() * 5;
		frame_time = new_time - current_time;
		current_time = new_time;

		accumulator += frame_time;

		while (accumulator >= dt) {
			update(accumulator);

			accumulator -= dt;
			time += dt;
		}

		render();
		glfwPollEvents();
	}

	return EXIT_SUCCESS;
}

void Game::keyEvent(int key, int mode) {
	if (mode == GLFW_PRESS) {
		dispatcher.trigger<KeyDown>(key);
	} else {
		dispatcher.trigger<KeyUp>(key);
	}
}

void Game::update(const double time) {
	move_system.update(time, registry);
	ai_system.update(time, registry);
	collision_system.update(time, collideables);
}

void Game::render() {
	std::fill(texture.begin(), texture.end(), 0.1);

	auto sprite_view = registry.view<Sprite, Position>();
	sprite_view.each([&](Sprite &sprite, Position &position) {
		auto row_end = position.m_y + sprite.radius + sprite.height;
		auto col_end = position.m_x + sprite.radius + sprite.width;
		if (row_end > height) row_end = height;
		if (col_end > width) col_end = width;
		for (auto y = (uint32_t) position.m_y; y < row_end; y++) {
			for (auto x = (uint32_t)position.m_x; x < col_end; x++) {
				size_t location = (x + y * width) * 3;
				texture.at(location + 0) = sprite.color.r;
				texture.at(location + 1) = sprite.color.g;
				texture.at(location + 2) = sprite.color.b;
			}
		}
	});

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_FLOAT, &texture.at(0));

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(glfwWindow);
	glfwPollEvents();
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (action == GLFW_REPEAT) return;
	instance->keyEvent(key, action);
}
