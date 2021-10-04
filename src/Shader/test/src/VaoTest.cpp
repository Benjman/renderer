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
	Vao vao;
	ASSERT_GT(vao.id, GL_ZERO);

}

TEST_F(VaoTestFixture, bind) {
	glBindVertexArray(GL_ZERO);
	GLint id = GL_ZERO;

	testBoundVertexBuffer(GL_ZERO);

	Vao vao;

	// ensure creation doesn't bind
	testBoundVertexBuffer(GL_ZERO);

	vao.bind();
	ASSERT_GT(vao.id, GL_ZERO);

	testBoundVertexBuffer(vao.id);
}

TEST_F(VaoTestFixture, unbind) {
	Vao vao;
	vao.bind();

	GLint id = GL_ZERO;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &id);
	ASSERT_GT(id, GL_ZERO);

	vao.unbind();
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &id);
	ASSERT_EQ(id, GL_ZERO);

}

TEST_F(VaoTestFixture, findBoundVertexArray) {
	ASSERT_EQ(Vao::findBoundVertexArray(), GL_ZERO);
	Vao vao;
	vao.bind();
	ASSERT_GT(Vao::findBoundVertexArray(), GL_ZERO);
	ASSERT_EQ(Vao::findBoundVertexArray(), vao.id);
}

TEST_F(VaoTestFixture, destructorUnbinds) {
	Vao vao;
	vao.bind();
	ASSERT_EQ(Vao::findBoundVertexArray(), GL_ZERO);
}

TEST_F(VaoTestFixture, destructorDeletesBuffer) {
	Vao vao;
	vao.bind();

	GLuint id = vao.id;


	ASSERT_FALSE(glGetError());
	glBindVertexArray(id);
	ASSERT_TRUE(glGetError());
}

// TODO vao attribute testing
