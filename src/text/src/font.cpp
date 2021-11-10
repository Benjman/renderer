#define STB_RECT_PACK_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_rect_pack.h>
#include <stb_truetype.h>
#include <stb_image_write.h>
#undef STB_TRUETYPE_IMPLEMENTATION
#undef STB_RECT_PACK_IMPLEMENTATION
#undef STB_IMAGE_WRITE_IMPLEMENTATION

#include <text/font.h>
#include <iostream> // ghetto logging

namespace internal {
	FILE* get_file(const char *path, u_char* buffer);
}

void load_font(Font& font, const char* path) {
	internal::get_file(path, font.font_data);

	if (!stbtt_PackBegin(&font.context, font.atlas_data, font.width, font.height, 0, 1, nullptr))
		// TODO error handling
		throw std::runtime_error("oh shit couldn't initialize stb_truetype\n");

	stbtt_PackFontRange(&font.context, font.font_data, 0, font.line_height, 32, 95, font.chardata);
	stbtt_PackEnd(&font.context);

	// get metrics using old pai
	stbtt_fontinfo info;
	stbtt_InitFont(&info, font.font_data, 0);
	int32_t ascent, descent, line_gap;
	stbtt_GetFontVMetrics(&info, &ascent, &descent, &line_gap);
	float_t scale = stbtt_ScaleForPixelHeight(&info, font.line_height);
	font.ascent = (float_t) ascent * scale;
	font.descent = (float_t) descent * scale;
	font.line_gap = (float_t) line_gap * scale;
}

stbtt_aligned_quad Font::get_char(u_char c, float_t* cursor_x, float_t* cursor_y, float_t scale) const {
	stbtt_aligned_quad quad;
	stbtt_GetPackedQuad(chardata, width, height, c - 32, cursor_x, cursor_y, &quad, 0);
    quad.x0 *= scale;
    quad.y0 *= scale;
    quad.x1 *= scale;
    quad.y1 *= scale;
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
