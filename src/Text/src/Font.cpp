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

GLuint load_font(Font& font, const u_char* font_buffer) {
	if (!stbtt_InitFont(&font.fontinfo, font_buffer, 0))
		// TODO error handling
		throw std::runtime_error("oh shit couldn't initialize stb_truetype\n");

	font.scale_factor = stbtt_ScaleForPixelHeight(&font.fontinfo, font.line_height);

	int32_t ascent, descent, line_gap;
	stbtt_GetFontVMetrics(&font.fontinfo, &ascent, &descent, &line_gap);

	font.ascent = roundf((float_t)ascent * font.scale_factor);
	font.descent = roundf((float_t)descent * font.scale_factor);
	font.line_gap = roundf((float_t)line_gap * font.scale_factor);

	if (!stbtt_BakeFontBitmap(font_buffer, 0, font.line_height, font.atlas_data,
				ATLAS_WIDTH, ATLAS_HEIGHT, 32, TEXT_CHAR_COUNT, font.chardata))
		// TODO error handling
		throw std::runtime_error("oh shit couldn't initialize stb_truetype\n");

	GLuint texture_id = GL_ZERO;

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, ATLAS_WIDTH, ATLAS_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE, font.atlas_data);

	stbi_write_jpg("test.jpg", ATLAS_WIDTH, ATLAS_HEIGHT, 1, font.atlas_data, 100);
	return texture_id;
}

