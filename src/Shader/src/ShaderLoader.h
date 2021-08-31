#ifndef SHADER_SHADER_LOADER_H
#define SHADER_SHADER_LOADER_H

#include <Shader/Shader.h>

#include <gl.h>

#include <cstring>
#include <iostream> // TODO remove after logging is implemented
#include <cassert>

struct ShaderLoader {

	static GLuint loadShader(const char *vert, const char *frag, bool isSource) {
		std::string vertBuffer = vert;
		std::string fragBuffer = frag;

		if (!isSource) {
			loadSources(vert, &vertBuffer, frag, &fragBuffer);
		}

		assert(!std::string(vert).empty());
		assert(!std::string(frag).empty());

		GLuint vertId = compileShader(GL_VERTEX_SHADER, vertBuffer);
		GLuint fragId = compileShader(GL_FRAGMENT_SHADER, fragBuffer);

		return linkProgram(vertId, fragId);
	}

	private:
	static void loadSources(const char *vertPath, std::string *vertOut, const char *fragPath, std::string *fragOut) {
		assert(!std::string(vertPath).empty());
		assert(!std::string(fragPath).empty());

		size_t ignored;

		// TODO
//		loadResource(vertPath, &vertOut, &ignored);
//		loadResource(fragPath, &fragOut, &ignored);
	}

	static GLuint compileShader(GLuint type, std::string &source) {
		GLuint id;
		if (!(id = glCreateShader(type)))
			return GL_ZERO;

		const char *src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

#ifdef SHADER_DEBUG
		// Error checking
		int success;
		char infoLog[1024];
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
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
		glGetProgramiv(id, GL_LINK_STATUS, &success);
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

