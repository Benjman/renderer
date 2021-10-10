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

		void resize(GLsizeiptr size, const void *data, GLsizeiptr offset);

	public:
		static void unbind(GLenum target);
		static GLuint findBoundVertexArrayBuffer();

	public:
		Vbo(GLenum target, GLenum usage, GLsizeiptr size = 0, const void *data = nullptr, Vao *vao = nullptr);

		~Vbo();

		void bind() const;
		void storeData(const void *data, GLsizeiptr size, GLsizeiptr offset = 0);
		void unbind();
};

#endif // SHADER_VBO_H

