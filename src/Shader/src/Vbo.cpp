#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Shader/Vao.h>
#include <Shader/Vbo.h>

#include <stdexcept>

Vbo *Vbo::createVbo(Vao *vao, GLenum target, GLenum usage, GLsizeiptr size, const void *data) {
	auto vbo = new Vbo(target, usage);
	if (vao)
		vao->bind();
	vbo->storeData(data, size);
	return vbo;
}

GLuint Vbo::findBoundVertexArrayBuffer() {
	GLint tmp;
	glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &tmp);
	return tmp;
}

Vbo::~Vbo() {
	if (target == GL_ARRAY_BUFFER
			&& id == Vbo::findBoundVertexArrayBuffer())
		unbind(target);
	glDeleteBuffers(1, &id);
}

void Vbo::unbind(GLenum target) {
	glBindBuffer(target, GL_ZERO);
}

void Vbo::resize(GLsizeiptr size, const void *data, GLsizeiptr offset) {
	if (this->size == 0 && size == 0)
		return;

	if (this->size > size)
		throw std::runtime_error("can not resize vbo with size smaller than that which was already allocated");

	GLuint old = id;

	// generate new buffer
	glGenBuffers(1, &id);
	bind();
	// allocate on gpu
	glBufferData(target, size, nullptr, usage);
	// write new data to end of buffer
	glBufferSubData(target, this->size, size - this->size, data);

	if (old > GL_ZERO) {
		// copy old buffer to new
		glBindBuffer(GL_COPY_READ_BUFFER, old);
		glBindBuffer(GL_COPY_WRITE_BUFFER, id);
		glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, this->size);

		// destroy old buffer
		glDeleteBuffers(1, &old);
	}

	this->size = size;
}

void Vbo::storeData(const void *data, GLsizeiptr size, GLsizeiptr offset) {
	if (this->size < size || this->size == 0) {
		resize(size, data, offset);
	} else {
		bind();
		glBufferSubData(target, offset, size, data);
	}
}

void Vbo::bind() const {
	glBindBuffer(target, id);
}

void Vbo::unbind() {
	unbind(target);
}
