#ifndef TEXT_FONT_H
#define TEXT_FONT_H

#include <GL/gl.h>
#include <stb_truetype.h>

#include <cmath>
#include <limits>

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

	uint16_t width = ATLAS_WIDTH;
	uint16_t height = ATLAS_HEIGHT;

	u_char atlas_data[ATLAS_WIDTH * ATLAS_HEIGHT]{};
	u_char font_data[1024 * 1024]{}; // 1mb

	stbtt_bakedchar chardata[TEXT_CHAR_COUNT]{};
	stbtt_fontinfo fontinfo{};

	stbtt_aligned_quad get_char(u_char c, float_t* cursor_x, float_t* cursor_y) const;

};

extern GLuint load_font(Font& font, const char* path, bool upload = true);

#endif // TEXT_FONT_H
