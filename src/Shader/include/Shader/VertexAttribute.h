#ifndef SHADER_VERTEX_ATTRIBUTE_H
#define SHADER_VERTEX_ATTRIBUTE_H

#include <gl.h>

class VertexAttribute {
	private:
		friend class Vao;

		GLuint index;
		bool enabled;

	public:
		VertexAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset, bool enabled = true);

		void enable(bool force = false);
		void disable(bool force = false);

};

#endif // SHADER_VERTEX_ATTRIBUTE_H
