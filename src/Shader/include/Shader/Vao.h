#ifndef SHADER_VAO_H
#define SHADER_VAO_H

#include <vector>

#include <GL/gl.h>

class VertexAttribute;

class Vao {
	private:
		std::vector<VertexAttribute *> attributes;
		GLuint id;

		Vao(GLuint id) : id(id) {}

	public:
		static Vao *createVao();
		static void unbind();
		static GLuint findBoundVertexArray();

	public:
		~Vao();

		void bind();
		VertexAttribute *createAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset);

};

#endif // SHADER_VAO_H
