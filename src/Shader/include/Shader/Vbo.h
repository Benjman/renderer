#ifndef SHADER_VBO_H
#define SHADER_VBO_H

#include <GL/gl.h>

class Vao;

class Vbo {
	private:
		GLuint id = GL_ZERO;
		GLenum target;
		GLenum usage;
		GLsizeiptr size;

		Vbo(GLenum target, GLenum usage, GLsizeiptr size = 0) : target(target), usage(usage), size(size) {}

		void resize(GLsizeiptr size, const void *data, GLsizeiptr offset);

	public:
		static Vbo *createVbo(Vao *vao, GLenum target, GLenum usage, GLsizeiptr size = 0, const void *data = nullptr);
		static void unbind(GLenum target);
		static GLuint findBoundVertexArrayBuffer();

		~Vbo();

		void bind() const;
		void storeData(const void *data, GLsizeiptr size, GLsizeiptr offset = 0);
		void unbind();
};

#endif // SHADER_VBO_H

