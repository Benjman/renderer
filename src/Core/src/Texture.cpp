#include <Core/Texture.h>

Texture::Texture(GLenum target, GLint mipmapLevel, GLint internalFormat, GLsizei width, GLenum format, GLenum type) : Texture(target, mipmapLevel, internalFormat, width, 0, 0, format, type) {
}

Texture::Texture(GLenum target, GLint mipmapLevel, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type) : Texture(target, mipmapLevel, internalFormat, width, height, 0, format, type) {
}

Texture::Texture(GLenum target, GLint mipmapLevel, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type) : target(target), mipmapLevel(mipmapLevel), internalFormat(internalFormat), width(width), height(height), depth(depth), format(format), type(type) {
	glGenTextures(1, &id);
}

void Texture::bind() {
	glBindTexture(target, id);
}

void Texture::unbind() {
	glBindTexture(target, 0);
}

void Texture::upload(const void* data) {
	switch(target) {
		case GL_TEXTURE_1D:
			return upload1d(data);
		case GL_TEXTURE_2D:
			return upload2d(data);
		case GL_TEXTURE_3D:
			return upload3d(data);
	}
}

void Texture::upload1d(const void* data) {
	glTexImage1D(target, mipmapLevel, internalFormat, width, 0, format, type, data);
}

void Texture::upload2d(const void* data) {
	glTexImage2D(target, mipmapLevel, internalFormat, width, height, 0, format, type, data);
}

void Texture::upload3d(const void* data) {
	glTexImage3D(target, mipmapLevel, internalFormat, width, height, depth, 0, format, type, data);
}

void Texture::parameter(GLenum pname, GLfloat param) {
	glTexParameterf(target, pname, param);
}

void Texture::parameter(GLenum pname, GLint param) {
	glTexParameteri(target, pname, param);
}

void Texture::parameter(GLenum pname, const GLfloat* params) {
	glTexParameterfv(target, pname, params);
}

void Texture::parameter(GLenum pname, const GLint* params) {
	glTexParameteriv(target, pname, params);
}

void Texture::parameter(GLenum pname, const GLuint* params) {
	glTexParameterIuiv(target, pname, params);
}

