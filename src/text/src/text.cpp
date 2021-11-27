#include <text.h>

#include <utility>
#include <limits>
#include <iostream>
#include <regex>

TextBuilder Text::create(std::string value, const Font *font) {
    return {std::move(value), font};
}

Text::Text(const Text& text) {
    *this = text;
}

Text& Text::operator=(const Text& text) {
    this->m_alignment = text.m_alignment;
    this->m_font = text.m_font;
    this->m_line_gap = text.m_line_gap;
    this->m_line_height = text.m_line_height;
    this->m_max_height = text.m_max_height;
    this->m_max_width = text.m_max_width;
    this->m_pos_x = text.m_pos_x;
    this->m_pos_y = text.m_pos_y;
    this->m_value = text.m_value;
    return *this;
}

void Text::calc_sizes(size_t *vert_buf_size, size_t *idx_buf_size) const {
    TextMeshGenerator::calc_buf_sizes(this, vert_buf_size, idx_buf_size);
}

void Text::generate_mesh(float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height, size_t *idx_cursor) const {
    size_t tmp_cursor = 0;
    TextMeshGenerator::generate(this, vert_buf, idx_buf, display_width, display_height, idx_cursor ? idx_cursor : &tmp_cursor);
}

void Text::generate_mesh(TextMeshContext& context) const {
    TextMeshGenerator::generate(context);
}

void Text::update_metadata() {
    // calculate renderable character count
    std::regex expression("[\\x21-\\x7f]"); // ascii range from characters 33 to 126, inclusive
    renderable_char_count = std::ptrdiff_t(std::distance( std::sregex_iterator(m_value.begin(), m_value.end(), expression), std::sregex_iterator()));
}

void Text::reset() {
    renderable_char_count = 0;
}

float_t Text::get_font_scale() const {
    return m_line_height / Font::LINE_HEIGHT;
}
