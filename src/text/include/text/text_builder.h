#ifndef TEXT_TEXT_BUILDER_H
#define TEXT_TEXT_BUILDER_H

#include "text.h"

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

#endif // TEXT_TEXT_BUILDER_H
