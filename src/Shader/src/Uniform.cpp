#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Shader/Shader.h>
#include <Shader/Uniform.h>
#include <iostream>

void IUniform::storeLocation(Shader& shader) {
	storeLocation(shader.getId());
}

void IUniform::storeLocation(GLuint programId) {
	_id = glGetUniformLocation(programId, _name);
	if (_id == INVALID_UNIFORM_ID) {
		std::cerr << "Uniform not found for '" << _name << "'.\n";
	}
}

void Uniform1f::doLoad() {
	glUniform1fv(_id, 1, &_value);
}

void Uniform2f::doLoad() {
	glUniform2fv(_id, 1, &_value[0]);
}

void Uniform3f::doLoad() {
	glUniform3fv(_id, 1, &_value[0]);
}

void Uniform4f::doLoad() {
	glUniform4fv(_id, 1, &_value[0]);
}

void Uniform1i::doLoad() {
	glUniform1iv(_id, 1, &_value);
}

void Uniform2i::doLoad() {
	glUniform2iv(_id, 1, &_value[0]);
}

void Uniform3i::doLoad() {
	glUniform3iv(_id, 1, &_value[0]);
}

void Uniform4i::doLoad() {
	glUniform4iv(_id, 1, &_value[0]);
}

void Uniform1ui::doLoad() {
	glUniform1uiv(_id, 1, &_value);
}

void Uniform2ui::doLoad() {
	glUniform2uiv(_id, 1, &_value[0]);
}

void Uniform3ui::doLoad() {
	glUniform3uiv(_id, 1, &_value[0]);
}

void Uniform4ui::doLoad() {
	glUniform4uiv(_id, 1, &_value[0]);
}

void UniformMatrix2f::load(glm::mat2 value) {
	glUniformMatrix2fv(_id, 1, GL_FALSE, &value[0][0]);
}

void UniformMatrix3f::load(glm::mat3 value) {
	glUniformMatrix3fv(_id, 1, GL_FALSE, &value[0][0]);
}

void UniformMatrix4f::load(glm::mat4 value) {
	glUniformMatrix4fv(_id, 1, GL_FALSE, &value[0][0]);
}

