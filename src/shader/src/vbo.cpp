#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <shader/vao.h>
#include <shader/vbo.h>

#include <stdexcept>

namespace internal {
    GLenum findBufferTargetBinding(GLenum target);
}

Vbo::Vbo(GLenum target, GLenum usage, GLsizeiptr size, const void *data, Vao *vao) : target(target), usage(usage), size(0) {
	if (vao)
		vao->bind();
	if (data)
		storeData(data, size);
}

Vbo::~Vbo() {
	if (id == Vbo::findBoundBuffer(target))
		unbind(target);
	glDeleteBuffers(1, &id);
}

GLuint Vbo::findBoundBuffer(GLenum target) {
	GLint tmp;
	glGetIntegerv(internal::findBufferTargetBinding(target), &tmp);
	return tmp;
}

void Vbo::unbind(GLenum target) {
	glBindBuffer(target, GL_ZERO);
}

void Vbo::bind() const {
	glBindBuffer(target, id);
}

void Vbo::unbind() {
	unbind(target);
}

void Vbo::storeData(const void *data, GLsizeiptr size, GLsizeiptr offset) {
	if (this->size < offset + size || this->size == 0) {
		resize(size, data, offset);
	} else {
		bind();
		glBufferSubData(target, offset, size, data);
	}
}

void Vbo::resize(GLsizeiptr size, const void *data, GLsizeiptr offset) {
	if (this->size == 0 && size == 0)
		return;

	if (this->size > offset + size)
		throw std::runtime_error("can not resize vbo with size smaller than that which was already allocated");

	GLuint old = id;

	// generate new buffer
	glGenBuffers(1, &id);
	bind();
	// allocate on gpu
	glBufferData(target, size, nullptr, usage);
	// write new data to end of buffer
	glBufferSubData(target, this->size, size - this->size, data);

	if (old != GL_ZERO) {
		// copy old buffer to new
		glBindBuffer(GL_COPY_READ_BUFFER, old);
		glBindBuffer(GL_COPY_WRITE_BUFFER, id);
		glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, this->size);

		// destroy old buffer
		glDeleteBuffers(1, &old);
	}

	this->size = size;
}

GLenum internal::findBufferTargetBinding(GLenum target) {
    switch (target) {
        case GL_ARRAY_BUFFER:
            return GL_ARRAY_BUFFER_BINDING;
        case GL_ELEMENT_ARRAY_BUFFER:
            return GL_ELEMENT_ARRAY_BUFFER_BINDING;
        default:
            // probably just need to make from target to `target_BINDING`
            throw std::runtime_error(std::string("Unknown target: ") + std::to_string(target));
    }
}
