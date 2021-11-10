#include "shader_test_fixture.h"
#include <shader/vao.h>
#include <shader/vbo.h>

void testBoundVertexArray(GLuint id) {
    ASSERT_EQ(Vao::findBoundVertexArray(), id);
}

void testBoundVertexBuffer(GLenum target, GLuint id) {
    ASSERT_EQ(Vbo::findBoundBuffer(target), id);
}
