#include "ShaderTestFixture.h"
#define private public
#include <Shader/VertexAttribute.h>

struct VertexAttribFixture : public ShaderTestFixture {
	protected:
};

TEST_F(VertexAttribFixture, fieldInitialization) {
	VertexAttribute attrib(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void *)0, false);
	ASSERT_EQ(attrib.index, 1);
	ASSERT_EQ(attrib.enabled, false);
}
