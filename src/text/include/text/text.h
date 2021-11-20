#ifndef TEXT_TEXT_H
#define TEXT_TEXT_H

#include <cmath>
#include <cstdint>
#include <string>

class Font;
struct TextBuilder;

namespace internal {
    struct TextMeshGenerator;
}

// TODO more aligns lol
inline constexpr size_t TEXT_ALIGN_LEFT = 1;

class Text {
    public:
        static TextBuilder create(std::string value, Font* font);

        void calc_sizes(size_t* vert_buf_size, size_t* idx_buf_size);

        void generate_mesh(float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height);

        float_t get_font_scale();

        size_t renderable_char_count = 0;

    private:
        friend struct TextBuilder;
        friend struct internal::TextMeshGenerator;

        std::string m_value = "";
        const Font* m_font = nullptr;
        uint16_t m_alignment = TEXT_ALIGN_LEFT;
        uint16_t m_max_width = std::numeric_limits<int16_t>::max();
        uint16_t m_max_height = std::numeric_limits<int16_t>::max();
        uint16_t m_pos_x = 0;
        uint16_t m_pos_y = 0;
        float_t m_line_gap = 0.0;
        float_t m_line_height = 32.0;

        Text() = default;

        void reset();

};

#endif // TEXT_TEXT_H
