#include "ShaderTestFixture.h"
#include <Shader/Vao.h>
#define private public
#include <Shader/VertexAttribute.h>

struct VertexAttribFixture : public ShaderTestFixture {
protected:
	static void SetUpTestSuite() {
		ShaderTestFixture::SetUpTestSuite();
		vao = new Vao();
		vao->bind();
	}

	static void TearDownTestSuite() {
		delete vao;
		ShaderTestFixture::TearDownTestSuite();
	}

	void TearDown() override {
		ASSERT_FALSE(glGetError());
	}

	void SetUp() override {
		ASSERT_FALSE(glGetError());
	}

	static Vao* vao;
};

Vao* VertexAttribFixture::vao = nullptr;

TEST_F(VertexAttribFixture, fieldInitialization) {
	VertexAttribute attrib(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float_t), (void *)0, false);
	ASSERT_EQ(attrib.index, 1);
	ASSERT_EQ(attrib.enabled, false);
}
