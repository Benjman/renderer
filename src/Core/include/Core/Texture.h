#ifndef CORE_TEXTURE_H
#define CORE_TEXTURE_H

#include <GL/gl.h>

// TODO this should really be in the Shaders project
struct Texture {
	GLuint id;

	/**
	 * Specifies the target texture.
	 *
	 * Must be GL_TEXTURE_2D, GL_PROXY_TEXTURE_2D, GL_TEXTURE_1D_ARRAY, GL_PROXY_TEXTURE_1D_ARRAY,
	 * GL_TEXTURE_RECTANGLE, GL_PROXY_TEXTURE_RECTANGLE, GL_TEXTURE_CUBE_MAP_POSITIVE_X,
	 * GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	 * GL_TEXTURE_CUBE_MAP_POSITIVE_Z, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, or GL_PROXY_TEXTURE_CUBE_MAP.
	 */
	const GLenum target;

	/**
	 * Specifies the level-of-detail number.
	 *
	 * Level 0 is the base image level. Level n is the nth mipmap reduction image. If target is
	 * GL_TEXTURE_RECTANGLE or GL_PROXY_TEXTURE_RECTANGLE, level must be 0.
	 */
	const GLint mipmapLevel;

	/**
	 * Specifies the number of color components in the texture. Must be one of base internal formats given in
	 * Table 1, one of the sized internal formats given in Table 2, or one of the compressed internal formats
	 * given in Table 3, below.
	 */
	const GLint internalFormat;

	/**
	 * Specifies the width of the texture image.
	 *
	 * All implementations support texture images that are at least 1024 texels wide.
	 */
	const GLsizei width;

	/**
	 * Specifies the height of the texture image, or the number of layers in a texture array, in the case of
	 * the GL_TEXTURE_1D_ARRAY and GL_PROXY_TEXTURE_1D_ARRAY targets.
	 * 
	 * All implementations support 2D texture images that are at least 1024 texels high, and texture arrays that
	 * are at least 256 layers deep.
	 */
	const GLsizei height;

	/**
	 * Specifies the depth of the texture image, or the number of layers in a texture array. All implementations
	 * support 3D texture images that are at least 256 texels deep, and texture arrays that are at least 256 layers deep.
	 */
	GLsizei depth;

	/**
	 * Specifies the format of the pixel data.
	 *
	 * The following symbolic values are accepted: GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, GL_BGRA, GL_RED_INTEGER,
	 * GL_RG_INTEGER, GL_RGB_INTEGER, GL_BGR_INTEGER, GL_RGBA_INTEGER, GL_BGRA_INTEGER, GL_STENCIL_INDEX,
	 * GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL
	 */
	const GLenum format;

	/**
	 * Specifies the data type of the pixel data.
	 *
	 * The following symbolic values are accepted: GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_INT,
	 * GL_INT, GL_HALF_FLOAT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, GL_UNSIGNED_SHORT_5_6_5,
	 * GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1,
	 * GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2,
	 * GL_UNSIGNED_INT_2_10_10_10_REV
	 */
	const GLenum type;

	Texture(GLenum target, GLint mipmapLevel, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLuint id = 0);

	void bind();
	void unbind();

	void upload(const void* data);

	void parameter(GLenum pname, GLfloat param);
	void parameter(GLenum pname, GLint param);
	void parameter(GLenum pname, const GLfloat* params);
	void parameter(GLenum pname, const GLint* params);
	void parameter(GLenum pname, const GLuint* params);

	private:
	void upload1d(const void* data);
	void upload2d(const void* data);
	void upload3d(const void* data);
};

#endif // CORE_TEXTURE_H
