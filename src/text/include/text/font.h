#ifndef TEXT_FONT_H
#define TEXT_FONT_H

#include <cmath>
#include <cstdint>
#include <stb_truetype.h>

inline constexpr size_t VERT_COUNT = 16;
inline constexpr size_t IDX_COUNT = 6;

class Font {
    public:
        static inline constexpr size_t ATLAS_WIDTH = 1024;
        static inline constexpr size_t ATLAS_HEIGHT = 1024;
        static inline constexpr size_t TEXT_CHAR_COUNT = 95;
        static inline constexpr float_t LINE_HEIGHT = 128;

        static void load_font(const char* path, Font* font);

        float_t ascent = std::numeric_limits<float_t>::max();
        float_t descent = std::numeric_limits<float_t>::max();
        float_t line_gap = std::numeric_limits<float_t>::max();

        uint16_t width = ATLAS_WIDTH;
        uint16_t height = ATLAS_HEIGHT;

        u_char atlas_data[ATLAS_WIDTH * ATLAS_HEIGHT]{};
        stbtt_packedchar chardata[TEXT_CHAR_COUNT];

        stbtt_aligned_quad get_char(u_char c, float_t* cursor_x, float_t* cursor_y, float_t scale = 1) const;

        stbtt_pack_context context;

};

#endif // TEXT_FONT_H
