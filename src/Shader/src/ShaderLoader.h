#ifndef SHADER_SHADER_LOADER_H
#define SHADER_SHADER_LOADER_H

#include <Shader/Shader.h>

#include <gl.h>

#include <string>
#include <iostream> // TODO remove after logging is implemented
#include <cstring>

struct ShaderLoader {

	static GLuint loadShader(const char* vert, size_t vert_size, const char* frag, size_t frag_size) {
		std::string vertBuffer = vert;
		std::string fragBuffer = frag;

		GLuint vertId = compileShader(GL_VERTEX_SHADER, vertBuffer, vert_size);
		GLuint fragId = compileShader(GL_FRAGMENT_SHADER, fragBuffer, frag_size);

		return linkProgram(vertId, fragId);
	}

	private:
	static GLuint compileShader(GLuint type, std::string& source, size_t len) {
		GLuint id;
		if (!(id = glCreateShader(type)))
			return GL_ZERO;

		GLint length[] { (GLint) len };
		const char *src = source.c_str();
		glShaderSource(id, 1, &src, length);
		glCompileShader(id);

#ifdef SHADER_DEBUG
		// Error checking
		int success;
		char infoLog[1024];
		glGetShaderiv(id, GL_COMPILE_STATUS,& success);
		if (!success) {
			glGetShaderInfoLog(id, sizeof(infoLog) / sizeof(char), nullptr, infoLog);
			std::cerr << "Failed to compile shader.\nError from OpenGL: " << infoLog << std::endl;
		}
#endif

		return id;
	}

	static GLuint linkProgram(GLuint vertId, GLuint fragId) {
		if (vertId == GL_ZERO || fragId == GL_ZERO)
			return GL_ZERO;

		GLuint id;
		if (!(id = glCreateProgram()))
			return GL_ZERO;
		glAttachShader(id, vertId);
		glAttachShader(id, fragId);
		glLinkProgram(id);

#ifdef SHADER_DEBUG
		int success;
		char infoLog[1024];
		glGetProgramiv(id, GL_LINK_STATUS,& success);
		if (!success) {
			glGetProgramInfoLog(id, sizeof(infoLog) / sizeof(char), nullptr, infoLog);
			std::cerr << "Failed to link shader.\nError from OpenGL: " << infoLog << std::endl;
		}
#endif

		glDeleteShader(vertId);
		glDeleteShader(fragId);

		return id;
	}

};

#endif //SHADER_SHADER_LOADER_H

