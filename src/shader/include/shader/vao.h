#ifndef SHADER_VAO_H
#define SHADER_VAO_H

#include <GL/gl.h>
#include <vector>

class VertexAttribute;

class Vao {
	private:
		std::vector<VertexAttribute *> attributes;
		GLuint id;

	public:
		static void unbind();
		static GLuint findBoundVertexArray();

	public:
		// TODO create copy constructor and equals operator (like camera does)
		Vao();

		~Vao();

		void bind();
		VertexAttribute *createAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset);

};

#endif // SHADER_VAO_H
