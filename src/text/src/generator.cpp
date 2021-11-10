// TODO calculated widths and max-widths not correct (try wrapping a line with 128 size text)
#include "generator.h"
#include <text.h>

#include <cstring>

inline constexpr size_t VERT_COUNT = 16;
inline constexpr size_t IDX_COUNT = 6;

void internal::TextMeshGenerator::calc_buf_sizes(Text& text, size_t* vert_size, size_t* idx_size) {
    // TODO make vector not reference
    std::vector<Line> lines;
    generate_structure(text, &lines);

    for (Line& line : lines) {
        for (Word& word : line.words) {
            *vert_size += word.value.size() * VERT_COUNT * sizeof(float_t);
            *idx_size += word.value.size() * IDX_COUNT * sizeof(uint32_t);
        }
    }
}

void internal::TextMeshGenerator::generate(Text &root, float_t* vert_buf, uint32_t* idx_buf, float_t display_height, float_t aspect_ratio) {
    TextMeshGenerator(root, vert_buf, idx_buf, display_height, aspect_ratio);
}

internal::TextMeshGenerator::TextMeshGenerator(Text& root, float_t* vert_buf, uint32_t* idx_buf, float_t display_height, float_t aspect_ratio)
    : scale(root.get_font_scale()) {
        std::vector<Line> lines;
        generate_structure(root, &lines);

        size_t pointer = 0;
        float_t cursor_x = (float_t) root.m_pos_x,
                cursor_y = (float_t) root.m_pos_y + root.m_font->ascent;

        if (!root.renderable_char_count)
            return;

        for (auto line : lines) {
            process_line(line, root, vert_buf, idx_buf, &cursor_x, &cursor_y, &pointer, display_height, aspect_ratio);
            cursor_y += Font::LINE_HEIGHT;
            cursor_x = root.m_pos_x;
        }
    }

void internal::TextMeshGenerator::generate_structure(Text& root, std::vector<Line>* lines) {
    root.reset();

    float_t scale = root.get_font_scale();

    Line line(root.m_max_width);
    Word word;

    for (size_t i = 0, len = root.m_value.size(); i < len; i++) {
        char c = root.m_value.at(i);
        if (c == ' ') {
            if (!line.try_add_word(word)) {
                lines->emplace_back(line);
                line = Line(root.m_max_width);
                line.try_add_word(word);
            }
            word = Word();
            float_t tmp_x = 0, tmp_y = 0;
            root.m_font->get_char(' ', &tmp_x, &tmp_y, scale);
            line.width += tmp_x;
            continue;
        }

        float_t kern = 0;
        if (i + 1 != len) {
            // kern = (float_t) stbtt_GetCodepointKernAdvance(&root.m_font->fontinfo, c, root.m_value.at(i + 1)) * context.scale;
        }

        word.add_char(root.m_font, scale, c, kern);
        root.renderable_char_count++;
    }

    if (!line.try_add_word(word)) {
        lines->emplace_back(line);
        line = Line(root.m_max_width);
        line.try_add_word(word);
    }
}

void internal::TextMeshGenerator::process_line(Line& line, Text& root, float_t* vert_buf, uint32_t* idx_buf, float_t* cursor_x, float_t* cursor_y, size_t* pointer, float_t display_height, float_t aspect_ratio) const {
    for (auto word : line.words) {
        for (size_t i = 0, len = word.value.size(); i < len; i++) {
            stbtt_aligned_quad quad = root.m_font->get_char(word.value.at(i), cursor_x, cursor_y, scale);

            process_quad(quad, display_height, aspect_ratio);
            store_quad(quad, *pointer * 4, &vert_buf[*pointer * VERT_COUNT], &idx_buf[*pointer * IDX_COUNT]);

            (*pointer)++;

            // adjust for kerning
            if (len >= i + 1) {
                // *cursor_x += (float_t) stbtt_GetCodepointKernAdvance(&context.text->font->fontinfo, context.text->m_value.at(i), context.text->m_value.at(i + 1)) * context.scale;
            }
        }

        root.m_font->get_char(' ', cursor_x, cursor_y, scale);
    }
}

void internal::TextMeshGenerator::process_quad(stbtt_aligned_quad& quad, float_t display_height, float_t aspect_ratio) {
    // normalize to screen space
    quad.x0 /= display_height;
    quad.x1 /= display_height;
    quad.y0 /= display_height;
    quad.y1 /= display_height;

    // scale for aspect ratio
    if (aspect_ratio > 1) {
        quad.y0 *= aspect_ratio;
        quad.y1 *= aspect_ratio;
    } else {
        quad.x0 *= aspect_ratio;
        quad.x1 *= aspect_ratio;
    }

    // map from [0,1] to [-1,1]
    quad.x0 =  2 * quad.x0 - 1;
    quad.x1 =  2 * quad.x1 - 1;
    quad.y0 = -2 * quad.y0 + 1;
    quad.y1 = -2 * quad.y1 + 1;
}

void internal::TextMeshGenerator::store_quad(stbtt_aligned_quad quad, size_t idx_offset, float_t* vert_buf, uint32_t* idx_buf) {
    // vert_0
    vert_buf[0] = quad.x0;   vert_buf[1] = quad.y0;     // pos
    vert_buf[2] = quad.s0;   vert_buf[3] = -quad.t0;    // uv
    // vert_1
    vert_buf[4] = quad.x0;   vert_buf[5] = quad.y1;     // pos
    vert_buf[6] = quad.s0;   vert_buf[7] = -quad.t1;    // uv
    // vert_2
    vert_buf[8] = quad.x1;   vert_buf[9] = quad.y1;     // pos
    vert_buf[10] = quad.s1;   vert_buf[11] = -quad.t1;  // uv
    // vert_3
    vert_buf[12] = quad.x1;   vert_buf[13] = quad.y0;   // pos
    vert_buf[14] = quad.s1;   vert_buf[15] = -quad.t0;  // uv

    // indices
    idx_buf[0] = 0 + idx_offset;
    idx_buf[1] = 1 + idx_offset;
    idx_buf[2] = 3 + idx_offset;
    idx_buf[3] = 1 + idx_offset;
    idx_buf[4] = 2 + idx_offset;
    idx_buf[5] = 3 + idx_offset;
}

bool internal::TextMeshGenerator::Line::try_add_word(Word& word) {
    if (max_width < width + word.width)
        return false;
    words.emplace_back(word);
    width += word.width;
    return true;
}

void internal::TextMeshGenerator::Word::add_char(const Font* font, float_t scale, char c, float_t kern) {
    float_t tmp_x = 0, tmp_y = 0;
    font->get_char(c, &tmp_x, &tmp_y, scale);
    width += tmp_x * scale + kern;
    value += c;
}
