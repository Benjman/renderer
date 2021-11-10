#ifndef TEXT_FONT_H
#define TEXT_FONT_H

#include <cstdint>
#include <stb_truetype.h>

#include <cmath>
#include <limits>

struct Font {
    static constexpr size_t ATLAS_WIDTH = 1024;
    static constexpr size_t ATLAS_HEIGHT = 1024;
    static constexpr size_t TEXT_CHAR_COUNT = 95;
    static constexpr float_t line_height = 128;

    float_t ascent = std::numeric_limits<float_t>::max();
    float_t descent = std::numeric_limits<float_t>::max();
    float_t line_gap = std::numeric_limits<float_t>::max();

    uint16_t width = ATLAS_WIDTH;
    uint16_t height = ATLAS_HEIGHT;

    u_char atlas_data[ATLAS_WIDTH * ATLAS_HEIGHT]{};
    u_char font_data[1024 * 1024]{}; // 1mb

    stbtt_packedchar chardata[TEXT_CHAR_COUNT];

    stbtt_aligned_quad get_char(u_char c, float_t* cursor_x, float_t* cursor_y, float_t scale = 1) const;

    stbtt_pack_context context;
};

extern void load_font(Font& font, const char* path);

#endif // TEXT_FONT_H
