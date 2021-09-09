#include "ShaderLoader.h"

#include <Shader/Shader.h>

Shader Shader::createShader(std::string& vert, std::string& frag) {
	GLuint id = ShaderLoader::loadShader(vert, frag);
	Shader shader(id);
	return {shader};
}

void Shader::use() const {
	glUseProgram(id);
}
