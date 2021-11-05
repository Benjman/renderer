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
#define TEXT_ALIGN_LEFT 1

class Text {
    friend class TextBuilder;
    friend class internal::TextMeshGenerator;

    private:
        std::string m_value = "";
        const Font* m_font = nullptr;
        uint16_t m_alignment = TEXT_ALIGN_LEFT;
        uint16_t m_max_width = std::numeric_limits<int16_t>::max();
        uint16_t m_max_height = std::numeric_limits<int16_t>::max();
        uint16_t m_pos_x = 0;
        uint16_t m_pos_y = 0;
        float_t m_line_gap = 0.0;
        float_t m_line_height = 32.0;
        float_t m_display_height = 480.0;
        float_t m_aspect_ratio = 1.0;

    Text() = default;

	public:
		void generate_mesh();

        static TextBuilder create(std::string value, Font* font, float_t display_height, float_t aspect_ratio);

        uint32_t* m_idx_buf{};
        size_t m_idx_buf_size = 0;
        float_t* m_vert_buf{};
        size_t m_vert_buf_size = 0;

        size_t m_char_count = 0; // non-whitespace chars
};

#endif // TEXT_TEXT_H
