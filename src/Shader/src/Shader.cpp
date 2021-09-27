#include "ShaderLoader.h"

#include <Shader/Shader.h>

Shader Shader::createShader(const char* vert, size_t vert_size, const char* frag, size_t frag_size) {
	GLuint id = ShaderLoader::loadShader(vert, vert_size, frag, frag_size);
	Shader shader(id);
	return shader;
}

void Shader::use() const {
	glUseProgram(id);
}
