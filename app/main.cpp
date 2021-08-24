#include <Shader.h>
#include <iostream>
#include <vector>

#include <gl.h>
#include <glfw.h>

#include "logging.h"
#include "SimplexNoise.h"

const char *vertShader =	"#version 330 core\n"
							"layout (location = 0) in vec3 in_pos;"
							"layout (location = 1) in vec2 in_texCoord;"
							"out vec2 pass_texCoord;"
							"void main() {"
							"    pass_texCoord = in_texCoord;"
							"    gl_Position = vec4(in_pos, 1.0);"
							"}\0";
const char *fragShader =	"#version 330 core\n"
							"in vec2 pass_texCoord;"
							"out vec4 out_color;"
							"uniform sampler2D u_tex;"
							"void main() {"
							"    out_color = texture(u_tex, pass_texCoord);"
							"}\0";

const GLfloat vertices[] = {
	// positions
	 1.f,  1.f, 0.f,
	 1.f, -1.f, 0.f,
	-1.f, -1.f, 0.f,
	-1.f,  1.f, 0.f,

	// tex coords
	1.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 0.0f,
	0.0f, 1.0f,
};

const GLuint indices[] = {
	0, 1, 3,
	1, 2, 3
};

const size_t TEX_SIZE = 256;

struct Color {
	float_t r = 0, g = 0, b = 0;

	explicit Color(float_t v) : Color(v, v, v) {}
	Color(float_t r, float_t g, float_t b) : r(r), g(g), b(b) {}
};

float_t scale     = 100.f;
float_t lacunarity    = 1.99f;
float_t persistance   = 0.5f;
const SimplexNoise simplex(0.1f/scale, 0.5f, lacunarity, persistance); // Amplitude of 0.5 for the 1st octave : sum ~1.0f

void fillBuffer(std::vector<GLfloat> *texData, float_t time) {
	float_t speed_h = -.5f;
	float_t speed_v = -.25f;
	float_t offset_x  = 5.9f + time * speed_v;
	float_t offset_y  = 5.1f + time * speed_h;
	float_t offset_z  = 0.05f;

	int octaves = static_cast<int>(1 + std::log(scale)); // Estimate number of octaves needed for the current scale
	for (size_t row = 0; row < TEX_SIZE; row++) {
		const auto y = static_cast<float_t>((float_t) row - (float_t) TEX_SIZE/2 + offset_y*scale);

		for (size_t col = 0; col < TEX_SIZE; col++) {
			const auto x = static_cast<float_t>((float_t) col - (float_t) TEX_SIZE/2 + offset_x*scale);

			float_t val = simplex.fractal(octaves, x, y) + offset_z;
			val = (val + 1.0f) / 2.0f;

			Color color(val);
			if (col < 40 && row < 40) {
				color = Color(0, 0, 1);
			}
			if (col < 40 && row > TEX_SIZE - 40) {
				color = Color(1, 0, 0);
			}
			if (col > TEX_SIZE - 40 && row > TEX_SIZE - 40) {
				color = Color(1);
			}
			if (col > TEX_SIZE - 40 && row < 40) {
				color = Color(0, 1, 0);
			}

			size_t location = (row + col * TEX_SIZE) * 3;
			texData->at(location + 0) = color.r;
			texData->at(location + 1) = color.g;
			texData->at(location + 2) = color.b;
		}
	}
}

int main(const int argc, const char *argv[]) {
	spdlog::set_level(spdlog::level::trace);
	initializeGlfw("Testing", 800, 800);

	Shader shader = Shader::createShader(vertShader, fragShader);
	shader.use();
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

	std::vector<GLfloat> texData(TEX_SIZE * TEX_SIZE * 3);

	double_t renderInterval = 1.f / 60,
			nextRender = 0.f;

	double_t updateInterval = 1.f / 30,
			nextUpdate = 0.f;

	while (!glfwWindowShouldClose(glfwWindow)) {
		double_t time = glfwGetTime();

		if (time > nextRender) {
			nextRender = time + renderInterval;

			time = glfwGetTime();
			fillBuffer(&texData, time);
			spdlog::trace("fill time: {0}", (float_t)(glfwGetTime() - time));
			// LOG_TIME("fill time", glfwGetTime() - time);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEX_SIZE, TEX_SIZE, 0, GL_RGB, GL_FLOAT, &texData[0]);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(glfwWindow);
			glfwPollEvents();

			// std::cout << std::endl;
		}
	}

	std::atexit(destroyGlfw);
	return 0;
}
