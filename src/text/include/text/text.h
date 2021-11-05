#ifndef TEXT_TEXT_H
#define TEXT_TEXT_H

#include <cmath>
#include <cstdint>
#include <string>

class Font;

class TextBuilder;

namespace internal {
	struct TextMeshGenerator;
}

// TODO more aligns lol
#define TEXT_ALIGN_LEFT 1

class Text {
    friend class TextBuilder;
    friend class internal::TextMeshGenerator;

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

struct TextBuilder {
    Text m_root;

    TextBuilder(std::string value, Font* font, float_t display_height, float_t aspect_ratio) {
        m_root.m_value = value;
        m_root.m_font = font;
        m_root.m_display_height = display_height;
        m_root.m_aspect_ratio = aspect_ratio;
    }

    operator Text() const {
        return std::move(m_root);
    }

    TextBuilder& alignment(uint16_t alignment) {
        m_root.m_alignment = alignment;
        return *this;
    }

    TextBuilder& max_width(uint16_t max_width) {
        m_root.m_max_width = max_width;
        return *this;
    }

    TextBuilder& max_height(uint16_t max_height) {
        m_root.m_max_height = max_height;
        return *this;
    }

    TextBuilder& pos(uint16_t x, uint16_t y) {
        m_root.m_pos_x = x;
        m_root.m_pos_y = y;
        return *this;
    }

    TextBuilder& line_gap(float_t line_gap) {
        m_root.m_line_gap = line_gap;
        return *this;
    }

    TextBuilder& line_height(float_t line_height) {
        m_root.m_line_height = line_height;
        return *this;
    }

    TextBuilder& value(std::string value) {
        m_root.m_value = value;
        return *this;
    }

    TextBuilder& font(const Font* font) {
        m_root.m_font = font;
        return *this;
    }
};

#endif // TEXT_TEXT_H
