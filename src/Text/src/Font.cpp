#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#define STB_RECT_PACK_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_rect_pack.h>
#include <stb_truetype.h>
#include <stb_image_write.h>
#undef STB_TRUETYPE_IMPLEMENTATION
#undef STB_RECT_PACK_IMPLEMENTATION
#undef STB_IMAGE_WRITE_IMPLEMENTATION

#include <Text/Font.h>
#include <iostream> // ghetto logging

namespace internal {
	FILE* get_file(const char *path, u_char* buffer);

	GLuint upload(Font& font);
}

GLuint load_font(Font& font, const char* path, bool upload) {
	internal::get_file(path, font.font_data);

	if (!stbtt_InitFont(&font.fontinfo, font.font_data, 0))
		// TODO error handling
		throw std::runtime_error("oh shit couldn't initialize stb_truetype\n");

	font.scale_factor = stbtt_ScaleForPixelHeight(&font.fontinfo, font.line_height);

	int32_t ascent, descent, line_gap;
	stbtt_GetFontVMetrics(&font.fontinfo, &ascent, &descent, &line_gap);

	font.ascent = roundf((float_t)ascent * font.scale_factor);
	font.descent = roundf((float_t)descent * font.scale_factor);
	font.line_gap = roundf((float_t)line_gap * font.scale_factor);

	if (!stbtt_BakeFontBitmap(font.font_data, 0, font.line_height, font.atlas_data,
				font.width, font.height, 32, TEXT_CHAR_COUNT, font.chardata))
		// TODO error handling
		throw std::runtime_error("oh shit couldn't initialize stb_truetype\n");

	if (!upload)
		return GL_ZERO;

	return internal::upload(font);
}

stbtt_aligned_quad Font::get_char(u_char c, float_t* cursor_x, float_t* cursor_y) const {
	stbtt_aligned_quad quad;
	stbtt_GetBakedQuad(chardata, width, height, c - 32, cursor_x, cursor_y, &quad, 0);
	return quad;
}

FILE* internal::get_file(const char *path, u_char* buffer) {
	FILE* file = fopen(path, "rb");
	if (!file) {
		throw std::runtime_error(std::string(std::string("TrueType file not found: ") + path).c_str());
	}
	fread(buffer, 1, 1024 * 1024 * 5, file);
	fclose(file);
	return file;
}

GLuint internal::upload(Font& font) {
	GLuint texture_id = GL_ZERO;

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, font.width, font.height, 0, GL_RED, GL_UNSIGNED_BYTE, font.atlas_data);

	 stbi_write_jpg("test.jpg", font.width, font.height, 1, font.atlas_data, 100);
	return texture_id;
}
