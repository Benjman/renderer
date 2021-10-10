#include "shader_test_fixture.h"
#include <shader/vao.h>

void testBoundVertexBuffer(GLuint id) {
	GLint tmp = Vao::findBoundVertexArray();
	ASSERT_EQ(tmp, id);
}
