#include "ShaderTestFixture.h"
#define private public
#include <Shader/Vao.h>

struct VaoTestFixture : public ShaderTestFixture {
	protected:
		void TearDown() override {
			Vao::unbind();
			ASSERT_FALSE(glGetError());
		}

	void SetUp() override {
		ASSERT_FALSE(glGetError());
	}
};

TEST_F(VaoTestFixture, createVao) {
	Vao *result = Vao::createVao();

	ASSERT_NE(result, nullptr);
	ASSERT_GT(result->id, GL_ZERO);

	delete result;
}

TEST_F(VaoTestFixture, bind) {
	glBindVertexArray(GL_ZERO);
	GLint id = GL_ZERO;

	testBoundVertexBuffer(GL_ZERO);

	Vao *result = Vao::createVao();

	// ensure creation doesn't bind
	testBoundVertexBuffer(GL_ZERO);

	result->bind();
	ASSERT_GT(result->id, GL_ZERO);

	testBoundVertexBuffer(result->id);

	delete result;
}

TEST_F(VaoTestFixture, unbind) {
	Vao *result = Vao::createVao();
	result->bind();

	GLint id = GL_ZERO;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &id);
	ASSERT_GT(id, GL_ZERO);

	result->unbind();
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &id);
	ASSERT_EQ(id, GL_ZERO);

	delete result;
}

TEST_F(VaoTestFixture, findBoundVertexArray) {
	ASSERT_EQ(Vao::findBoundVertexArray(), GL_ZERO);
	Vao *vao = Vao::createVao();
	vao->bind();
	ASSERT_GT(Vao::findBoundVertexArray(), GL_ZERO);
	ASSERT_EQ(Vao::findBoundVertexArray(), vao->id);
	delete vao;
}

TEST_F(VaoTestFixture, destructorUnbinds) {
	Vao *vao = Vao::createVao();
	vao->bind();
	delete vao;
	ASSERT_EQ(Vao::findBoundVertexArray(), GL_ZERO);
}

TEST_F(VaoTestFixture, destructorDeletesBuffer) {
	Vao *vao = Vao::createVao();
	vao->bind();

	GLuint id = vao->id;

	delete vao;

	ASSERT_FALSE(glGetError());
	glBindVertexArray(id);
	ASSERT_TRUE(glGetError());
}

// TODO vao attribute testing
