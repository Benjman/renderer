#include "ShaderTestFixture.h"
#include <Shader/Vao.h>

void testBoundVertexBuffer(GLuint id) {
	GLint tmp = Vao::findBoundVertexArray();
	ASSERT_EQ(tmp, id);
}
