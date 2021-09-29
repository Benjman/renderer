#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Shader/VertexAttribute.h>

VertexAttribute::VertexAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
		const void *offset, bool enabled) : index(index), enabled(enabled) {
	glVertexAttribPointer(index, size, type, normalized, stride, offset);
	if (enabled)
		enable(true);
}

void VertexAttribute::enable(bool force) {
	if (enabled && !force) return;
	glEnableVertexAttribArray(index);
	enabled = true;
}

void VertexAttribute::disable(bool force) {
	if (!enabled && !force) return;
	glEnableVertexAttribArray(index);
	enabled = false;
}
