#include "ShaderLoader.h"

#include <Shader/Shader.h>

Shader Shader::createShader(const char* vert, const char* frag) {
	GLuint id = ShaderLoader::loadShader(vert, frag);
	Shader shader(id);
	return shader;
}

void Shader::use() const {
	glUseProgram(id);
}
