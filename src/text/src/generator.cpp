#include "generator.h"
#include <text.h>

#include <cstring>

#include <glm/vec4.hpp>

static constexpr size_t TEXT_ALIGN_HORIZONTAL_MASK = 0x3;
static constexpr size_t TEXT_ALIGN_VERTICAL_MASK = 0xc;

internal::TextMeshContext::TextMeshContext(const Text& root) : root(root), scale(root.get_font_scale()) {}

void internal::TextMeshGenerator::calc_buf_sizes(const Text& text, size_t* vert_size, size_t* idx_size) {
    std::vector<Line> lines;
    generate_structure(text, &lines);

    for (Line& line : lines) {
        for (Word& word : line.words) {
            *vert_size += word.value.size() * Text::VERT_COUNT * sizeof(float_t);
            *idx_size += word.value.size() * Text::IDX_COUNT * sizeof(uint32_t);
        }
    }
}

internal::TextAttribute* find_attribute(std::vector<internal::TextAttribute>* attributes, internal::text_attrib_t type);

void internal::TextMeshGenerator::generate(const Text &root, float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height, size_t *idx_pointer) {
    TextMeshContext context(root);
    context.display_height = display_height;
    context.display_width = display_width;
    context.idx_buffer = idx_buf;
    context.idx_pointer = idx_pointer;
    context.vertex_buffer = vert_buf;

    context.add_attrib(TextAttribPosition, TextAttribute(4, 0));
    context.add_attrib(TextAttribUV, TextAttribute(4, 2));

    generate(context);
}

void internal::TextMeshGenerator::generate(TextMeshContext& context) {
    (TextMeshGenerator(context));
}

internal::TextMeshGenerator::TextMeshGenerator(TextMeshContext& context) {
    std::vector<Line> lines;
    generate_structure(context.root, &lines);

    context.cursor_y = (float_t) context.root.m_pos_y + context.root.m_font->ascent;

    if (context.root.value().empty())
        return;

    for (const auto &line : lines) {
        switch (context.root.m_alignment & TEXT_ALIGN_HORIZONTAL_MASK) {
            case Text::TEXT_ALIGN_LEFT:
                context.cursor_x = (float_t) context.root.m_pos_x;
                break;

            case Text::TEXT_ALIGN_CENTER:
                context.cursor_x = (float_t) context.root.m_pos_x + (float_t) (context.root.m_max_width * 0.5 - line.width * 0.5);
                break;

            case Text::TEXT_ALIGN_RIGHT:
                context.cursor_x = (float_t)  context.root.m_pos_x + ((float_t) context.root.m_max_width - line.width);
                break;
        }

        process_line(line, context);
        context.cursor_y += context.root.m_font->ascent;
    }
}

void internal::TextMeshGenerator::generate_structure(const Text &root, std::vector<Line> *lines) {
    float_t scale = root.get_font_scale();
    Line line(root.m_max_width);
    Word word;

    float_t space_width = 0, tmp_x = 0, tmp_y = 0;
    root.m_font->get_char(' ', &space_width, &tmp_y, scale);

    for (size_t i = 0, len = root.m_value.size(); i < len; i++) {
        if (root.m_value.at(i) == ' ') {
            if (!line.try_add_word(word)) {
                line.width -= space_width;
                lines->emplace_back(line);
                line = Line(root.m_max_width);
                line.try_add_word(word);
            }
            word = Word();
            line.width += space_width;
            continue;
        }

        tmp_x = 0;
        root.m_font->get_char(root.m_value.at(i), &tmp_x, &tmp_y, scale);
        word.add_char(root.m_value.at(i), tmp_x);
    }

    if (!line.try_add_word(word)) {
        lines->emplace_back(line);
        line = Line(root.m_max_width);
        line.try_add_word(word);
    }

    lines->emplace_back(line);
}

void internal::TextMeshGenerator::process_line(const Line &line, TextMeshContext& context) const {
    for (auto word : line.words) {
        for (size_t i = 0, len = word.value.size(); i < len; i++) {
            stbtt_aligned_quad quad = context.root.m_font->get_char(word.value.at(i), &context.cursor_x, &context.cursor_y, context.scale);

            quad_to_screen_space(quad, context.display_width, context.display_height);
            store_quad(quad, context, *context.idx_pointer * 4, &context.vertex_buffer[*context.idx_pointer * Text::VERT_COUNT], &context.idx_buffer[*context.idx_pointer * Text::IDX_COUNT]);

            (*context.idx_pointer)++;

            // adjust for kerning
            if (len >= i + 1) {
                // *cursor_x += (float_t) stbtt_GetCodepointKernAdvance(&context.text->font->fontinfo, context.text->m_value.at(i), context.text->m_value.at(i + 1)) * context.scale;
            }
        }

        context.root.m_font->get_char(' ', &context.cursor_x, &context.cursor_y, context.scale);
    }
}

void internal::TextMeshGenerator::quad_to_screen_space(stbtt_aligned_quad &quad, float_t display_width, float_t display_height) {
    // normalize to screen space
    quad.x0 /= display_width;
    quad.y0 /= display_height;
    quad.x1 /= display_width;
    quad.y1 /= display_height;

    // map from [0,1] to [-1,1]
    quad.x0 =  2 * quad.x0 - 1;
    quad.y0 = -2 * quad.y0 + 1;
    quad.x1 =  2 * quad.x1 - 1;
    quad.y1 = -2 * quad.y1 + 1;
}

void internal::TextMeshGenerator::store_quad(stbtt_aligned_quad quad, TextMeshContext& context, size_t idx_offset, float_t* vert_buf, uint32_t* idx_buf) {
    if (TextAttribute* pos = context.find_attrib(TextAttribPosition))
        store_quad_pos(quad, *pos, vert_buf);

    if (TextAttribute* uv = context.find_attrib(TextAttribUV))
        store_quad_uv(quad, *uv, vert_buf);

    // TODO text color
    //if (TextAttribute* color = context.find_attrib(TextAttribColor))
        //store_quad_color();

    // indices
    idx_buf[0] = 0 + idx_offset;
    idx_buf[1] = 1 + idx_offset;
    idx_buf[2] = 3 + idx_offset;
    idx_buf[3] = 1 + idx_offset;
    idx_buf[4] = 2 + idx_offset;
    idx_buf[5] = 3 + idx_offset;
}

void internal::TextMeshGenerator::store_quad_pos(stbtt_aligned_quad quad, TextAttribute& attrib, float* vert_buf){
    vert_buf[attrib.offset + 0]                     = quad.x0;
    vert_buf[attrib.offset + 1]                     = quad.y0;
    vert_buf[attrib.offset + attrib.stride + 0]     = quad.x0;
    vert_buf[attrib.offset + attrib.stride + 1]     = quad.y1;
    vert_buf[attrib.offset + attrib.stride * 2 + 0] = quad.x1;
    vert_buf[attrib.offset + attrib.stride * 2 + 1] = quad.y1;
    vert_buf[attrib.offset + attrib.stride * 3 + 0] = quad.x1;
    vert_buf[attrib.offset + attrib.stride * 3 + 1] = quad.y0;
}

void internal::TextMeshGenerator::store_quad_uv(stbtt_aligned_quad quad, TextAttribute& attrib, float* vert_buf){
    vert_buf[attrib.offset + 0]                     =  quad.s0;
    vert_buf[attrib.offset + 1]                     = -quad.t0;
    vert_buf[attrib.offset + attrib.stride + 0]     =  quad.s0;
    vert_buf[attrib.offset + attrib.stride + 1]     = -quad.t1;
    vert_buf[attrib.offset + attrib.stride * 2 + 0] =  quad.s1;
    vert_buf[attrib.offset + attrib.stride * 2 + 1] = -quad.t1;
    vert_buf[attrib.offset + attrib.stride * 3 + 0] =  quad.s1;
    vert_buf[attrib.offset + attrib.stride * 3 + 1] = -quad.t0;
}

void internal::TextMeshGenerator::store_quad_color(glm::vec3& color, TextAttribute& attrib, float* vert_buf){
    vert_buf[attrib.offset + 0]                     = color.r;
    vert_buf[attrib.offset + 1]                     = color.g;
    vert_buf[attrib.offset + 2]                     = color.b;
    vert_buf[attrib.offset + attrib.stride + 0]     = color.r;
    vert_buf[attrib.offset + attrib.stride + 1]     = color.g;
    vert_buf[attrib.offset + attrib.stride + 2]     = color.b;
    vert_buf[attrib.offset + attrib.stride * 2 + 0] = color.r;
    vert_buf[attrib.offset + attrib.stride * 2 + 1] = color.g;
    vert_buf[attrib.offset + attrib.stride * 2 + 2] = color.b;
    vert_buf[attrib.offset + attrib.stride * 3 + 0] = color.r;
    vert_buf[attrib.offset + attrib.stride * 3 + 1] = color.g;
    vert_buf[attrib.offset + attrib.stride * 3 + 2] = color.b;
}

bool internal::TextMeshGenerator::Line::try_add_word(Word& word) {
    if (max_width < width + word.width)
        return false;
    words.emplace_back(word);
    width += word.width;
    return true;
}

void internal::TextMeshGenerator::Word::add_char(char c, float_t w) {
    width += w;
    value += c;
}
