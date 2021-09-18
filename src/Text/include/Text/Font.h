#ifndef TEXT_FONT_H
#define TEXT_FONT_H

#include "internal/gl.hpp"
#include <cmath>
#include <limits>

#include <stb_truetype.h>

#define ATLAS_WIDTH (1024)
#define ATLAS_HEIGHT (1024)
#define TEXT_CHAR_COUNT (95)

struct Font {
	GLuint textureId = 0;

	const float_t line_height = 128;

	float_t ascent = std::numeric_limits<float_t>::max();
	float_t descent = std::numeric_limits<float_t>::max();
	float_t line_gap = std::numeric_limits<float_t>::max();
	float_t scale_factor = std::numeric_limits<float_t>::max();

	u_char atlas_data[ATLAS_WIDTH * ATLAS_HEIGHT]{};
	u_char font_data[1024 * 1024]{};

	stbtt_bakedchar chardata[TEXT_CHAR_COUNT]{};
	stbtt_fontinfo fontinfo{};

};

extern GLuint load_font(Font& font, u_char* font_buffer);

#endif // TEXT_FONT_H
