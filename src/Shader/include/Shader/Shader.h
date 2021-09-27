#ifndef SHADER_SHADER_H
#define SHADER_SHADER_H

#include <gl.h>

class Vao;

struct Shader {
	public:
		friend class ShaderLoader;

		Shader() = default;

		void load(const char* vert, size_t vert_size, const char* frag, size_t frag_size, bool force = false);

		void use() const;

		void initialize() {
			use();
			loadUniforms();
		}

	protected:
		GLuint id = GL_ZERO;

		virtual void loadUniforms() {}
};

#endif // SHADER_SHADER_H
