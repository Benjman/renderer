#include "shader_test_fixture.h"
#define private public
#include <shader/vao.h>

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

    ASSERT_EQ(0, Vao::findBoundVertexArray());

	Vao vao;

	// ensure creation doesn't bind
    ASSERT_EQ(0, Vao::findBoundVertexArray());

	vao.bind();
	ASSERT_GT(vao.id, GL_ZERO);

    ASSERT_EQ(vao.id, Vao::findBoundVertexArray());
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
	Vao* vao = new Vao;
	vao->bind();
	ASSERT_EQ(vao->id, Vao::findBoundVertexArray());
    delete vao;
	ASSERT_EQ(0, Vao::findBoundVertexArray());
}

TEST_F(VaoTestFixture, destructorDeletesBuffer) {
	Vao* vao = new Vao;
	vao->bind();

	GLuint id = vao->id;

	ASSERT_FALSE(glGetError());
	glBindVertexArray(id);
	ASSERT_FALSE(glGetError());

    delete vao;
    glBindVertexArray(id);
	ASSERT_TRUE(glGetError());
}

// TODO vao attribute testing
