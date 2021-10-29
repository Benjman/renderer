#include "shader_test_fixture.h"
#define private public
#include <shader/vao.h>
#include <shader/vbo.h>

GLuint TARGET = GL_ARRAY_BUFFER;

struct VboTestFixture : public ShaderTestFixture {
	protected:
		void SetUp() override {
			vao = new Vao();
			vbo = new Vbo(TARGET, GL_STATIC_DRAW);
			ASSERT_FALSE(glGetError());
		}

		void TearDown() override {
            GLuint error;
			if ((error = glGetError()) != GL_NO_ERROR)
				throw std::runtime_error("GL Error: " + std::to_string(error));
			Vbo::unbind(TARGET);
			delete vbo;
			delete vao;
			ASSERT_FALSE(glGetError());
		}

		Vao *vao = nullptr;
		Vbo *vbo = nullptr;
};

GLuint getArrayBufferBoundVBO() {
	GLint tmp;
	glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &tmp);
	return tmp;
}

TEST_F(VboTestFixture, fieldInitialization) {
	Vbo vbo(TARGET, GL_STATIC_DRAW);
	ASSERT_EQ(vbo.target, TARGET);
	ASSERT_EQ(vbo.usage, GL_STATIC_DRAW);
}

TEST_F(VboTestFixture, createVbo_vboDoesntBindWithNoData) {
	Vao::unbind();
	Vao vao;
	ASSERT_GT(vao.id, 0);

	ASSERT_EQ(Vao::findBoundVertexArray(), 0);
	Vbo vbo(TARGET, GL_STATIC_DRAW);
	ASSERT_EQ(Vao::findBoundVertexArray(), 0);
}

TEST_F(VboTestFixture, createVbo_vboBindsWithData) {
    GLfloat data[] = {1.f};

	Vao::unbind();
	Vao vao;
	ASSERT_GT(vao.id, 0);

	ASSERT_EQ(Vao::findBoundVertexArray(), 0);
	Vbo vbo(TARGET, GL_STATIC_DRAW, sizeof(data), data, &vao);
	ASSERT_EQ(Vao::findBoundVertexArray(), vao.id);
	vbo.unbind();
}

TEST_F(VboTestFixture, createVbo_bufferBinds) {
	ASSERT_EQ(vbo->id, getArrayBufferBoundVBO());
}

TEST_F(VboTestFixture, unbind) {
	ASSERT_EQ(vbo->id, Vbo::findBoundBuffer(vbo->target));
	vbo->unbind();
	ASSERT_EQ(0, Vbo::findBoundBuffer(vbo->target));
}

TEST_F(VboTestFixture, storeData) {
	GLfloat vertices[] = {
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
	};

	vbo->storeData(vertices, sizeof(vertices));

	GLint size = GL_ZERO;
	glGetBufferParameteriv(TARGET, GL_BUFFER_SIZE, &size);
	ASSERT_EQ(sizeof(vertices), size);

	GLfloat outData[size / sizeof(GLfloat)];
	glGetBufferSubData(TARGET, 0, size, &outData);

	for (size_t i = 0, len = size / sizeof(GLfloat); i < len; i++) {
		ASSERT_EQ(vertices[i], outData[i]);
	}
}

// // TODO
// TEST_F(VboTestFixture, resizing) {
// }
