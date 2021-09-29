#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Shader/Vao.h>
#include <Shader/VertexAttribute.h>

Vao *Vao::createVao() {
	GLuint id = GL_ZERO;
	glGenVertexArrays(1, &id);
	return new Vao(id);
}

GLuint Vao::findBoundVertexArray() {
	GLint id;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &id);
	return id;
}

Vao::~Vao() {
	if (Vao::findBoundVertexArray() == id)
		unbind();

	glDeleteVertexArrays(1, &id);
	for (auto attribute : attributes) {
		attribute->disable();
		delete attribute;
	}
}

void Vao::bind() {
	glBindVertexArray(id);
}

void Vao::unbind() {
	glBindVertexArray(0);
}

VertexAttribute *Vao::createAttribute(GLuint index, GLint size, GLenum type,
		GLboolean normalized, GLsizei stride, const void *offset) {
	bind();
	auto *attrib = new VertexAttribute(index, size, type, normalized, stride, offset);
	attributes.emplace_back(attrib);
	return attrib;
}

