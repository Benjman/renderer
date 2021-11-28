#include "text/generator.h"
#include <text.h>

#include <cstring>
#include <glm/vec4.hpp>

static constexpr size_t TEXT_ALIGN_HORIZONTAL_MASK = 0x3;
static constexpr size_t TEXT_ALIGN_VERTICAL_MASK = 0xc;

void TextMeshGenerator::calc_buffer_sizes(const Text* text, size_t* vert_size, size_t* idx_size) {
    std::vector<Line> lines;
    generate_structure(text, &lines);

    for (Line& line : lines) {
        for (Word& word : line.words) {
            *vert_size += word.value.size() * Text::ELEMENTS_PER_VERT * sizeof(float_t);
            *idx_size += word.value.size() * Text::ELEMENTS_PER_INDEX * sizeof(uint32_t);
        }
    }
}

TextAttribute* find_attribute(std::vector<TextAttribute>* attributes, text_attrib_t type);

size_t TextMeshGenerator::generate(const Text* root, float_t *vertex_buffer, uint32_t *index_buffer, float_t display_width, float_t display_height, size_t index_offset) {
    TextMeshContext context(root);
    context.display_height = display_height;
    context.display_width = display_width;
    context.idx_buffer = index_buffer;
    context.idx_offset = index_offset;
    context.vertex_buffer = vertex_buffer;

    context.add_attrib(TextAttribPosition, TextAttribute(2, 4, 0));
    context.add_attrib(TextAttribUV, TextAttribute(2, 4, 2));

    return generate(context);
}

size_t TextMeshGenerator::generate(TextMeshContext& context) {
    TextMeshGenerator generator(context);
    return generator.start();
}

TextMeshGenerator::TextMeshGenerator(TextMeshContext& context) : context(context) {
    context.elements_per_vert = context.find_elements_per_vert();
}

size_t TextMeshGenerator::start() {
    std::vector<Line> lines;
    generate_structure(context.root, &lines);

    context.cursor_y = (float_t) context.root->m_pos_y + context.root->m_font->ascent;

    if (context.root->value().empty())
        return 0;

    size_t idx_offset = context.idx_offset;

    for (const auto &line : lines) {
        context.cursor_x = find_horizontal_start(context.root, line.width);
        idx_offset = process_line(line, idx_offset);
        context.cursor_y += context.root->m_font->ascent;
    }

    return context.chars_processed;
}

void TextMeshGenerator::generate_structure(const Text* root, std::vector<Line> *lines) {
    float_t scale = root->get_font_scale();
    Line line(root->m_max_width);
    Word word;

    float_t space_width = 0, tmp_x = 0, tmp_y = 0;
    root->m_font->get_char(' ', &space_width, &tmp_y, scale);

    for (size_t i = 0, len = root->m_value.size(); i < len; i++) {
        if (root->m_value.at(i) == ' ') {
            if (!line.try_add_word(word)) {
                line.width -= space_width;
                lines->emplace_back(line);
                line = Line(root->m_max_width);
                line.try_add_word(word);
            }
            word = Word();
            line.width += space_width;
            continue;
        }

        tmp_x = 0;
        root->m_font->get_char(root->m_value.at(i), &tmp_x, &tmp_y, scale);
        word.add_char(root->m_value.at(i), tmp_x);
    }

    if (!line.try_add_word(word)) {
        lines->emplace_back(line);
        line = Line(root->m_max_width);
        line.try_add_word(word);
    }

    lines->emplace_back(line);
}

size_t TextMeshGenerator::process_line(const Line &line, size_t idx_offset) const {
    for (auto word : line.words) {
        for (size_t i = 0, len = word.value.size(); i < len; i++) {
            stbtt_aligned_quad quad = context.root->m_font->get_char(word.value.at(i), &context.cursor_x, &context.cursor_y, context.scale);

            quad_to_screen_space(quad, context.display_width, context.display_height);
            store_quad(quad, context);

            // indices
            context.idx_buffer[0] = 0 + idx_offset;
            context.idx_buffer[1] = 1 + idx_offset;
            context.idx_buffer[2] = 3 + idx_offset;
            context.idx_buffer[3] = 1 + idx_offset;
            context.idx_buffer[4] = 2 + idx_offset;
            context.idx_buffer[5] = 3 + idx_offset;

            context.char_processed();

            idx_offset += 4;

            // adjust for kerning
            if (len >= i + 1) {
                // *cursor_x += (float_t) stbtt_GetCodepointKernAdvance(&context.text->font->fontinfo, context.text->m_value.at(i), context.text->m_value.at(i + 1)) * context.scale;
            }
        }

        // increase cursor_x one space width
        context.root->m_font->get_char(' ', &context.cursor_x, &context.cursor_y, context.scale);
    }

    return idx_offset;
}

void TextMeshGenerator::quad_to_screen_space(stbtt_aligned_quad &quad, float_t display_width, float_t display_height) {
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

    // invert texture y-axis
    quad.t0 *= -1.0;
    quad.t1 *= -1.0;
}

void TextMeshGenerator::store_quad(stbtt_aligned_quad quad, TextMeshContext& context) {
    if (TextAttribute* attrib = context.find_attrib(TextAttribPosition))
        store_quad_pos(quad, *attrib, context.vertex_buffer);

    if (TextAttribute* attrib = context.find_attrib(TextAttribUV))
        store_quad_uv(quad, *attrib, context.vertex_buffer);

    if (TextAttribute* attrib = context.find_attrib(TextAttribColor))
        store_quad_color(context.color, *attrib, context.vertex_buffer);
}

void TextMeshGenerator::store_quad_pos(stbtt_aligned_quad quad, TextAttribute& attrib, float_t* vert_buf) {
    vert_buf[attrib.offset + attrib.stride * 0 + 0] = quad.x0;
    vert_buf[attrib.offset + attrib.stride * 0 + 1] = quad.y0;
    vert_buf[attrib.offset + attrib.stride * 1 + 0] = quad.x0;
    vert_buf[attrib.offset + attrib.stride * 1 + 1] = quad.y1;
    vert_buf[attrib.offset + attrib.stride * 2 + 0] = quad.x1;
    vert_buf[attrib.offset + attrib.stride * 2 + 1] = quad.y1;
    vert_buf[attrib.offset + attrib.stride * 3 + 0] = quad.x1;
    vert_buf[attrib.offset + attrib.stride * 3 + 1] = quad.y0;
}

void TextMeshGenerator::store_quad_uv(stbtt_aligned_quad quad, TextAttribute& attrib, float_t* vert_buf) {
    vert_buf[attrib.offset + attrib.stride * 0 + 0] = quad.s0;
    vert_buf[attrib.offset + attrib.stride * 0 + 1] = quad.t0;
    vert_buf[attrib.offset + attrib.stride * 1 + 0] = quad.s0;
    vert_buf[attrib.offset + attrib.stride * 1 + 1] = quad.t1;
    vert_buf[attrib.offset + attrib.stride * 2 + 0] = quad.s1;
    vert_buf[attrib.offset + attrib.stride * 2 + 1] = quad.t1;
    vert_buf[attrib.offset + attrib.stride * 3 + 0] = quad.s1;
    vert_buf[attrib.offset + attrib.stride * 3 + 1] = quad.t0;
}

void TextMeshGenerator::store_quad_color(glm::vec3& color, TextAttribute& attrib, float_t* vert_buf) {
    vert_buf[attrib.offset + attrib.stride * 0 + 0] = color.r;
    vert_buf[attrib.offset + attrib.stride * 0 + 1] = color.g;
    vert_buf[attrib.offset + attrib.stride * 0 + 2] = color.b;
    vert_buf[attrib.offset + attrib.stride * 1 + 0] = color.r;
    vert_buf[attrib.offset + attrib.stride * 1 + 1] = color.g;
    vert_buf[attrib.offset + attrib.stride * 1 + 2] = color.b;
    vert_buf[attrib.offset + attrib.stride * 2 + 0] = color.r;
    vert_buf[attrib.offset + attrib.stride * 2 + 1] = color.g;
    vert_buf[attrib.offset + attrib.stride * 2 + 2] = color.b;
    vert_buf[attrib.offset + attrib.stride * 3 + 0] = color.r;
    vert_buf[attrib.offset + attrib.stride * 3 + 1] = color.g;
    vert_buf[attrib.offset + attrib.stride * 3 + 2] = color.b;
}

bool TextMeshGenerator::Line::try_add_word(Word& word) {
    if (max_width < width + word.width)
        return false;
    words.emplace_back(word);
    width += word.width;
    return true;
}

void TextMeshGenerator::Word::add_char(char c, float_t w) {
    width += w;
    value += c;
}

float_t TextMeshGenerator::find_horizontal_start(const Text* root, float_t max_line_width) {
    switch (root->m_alignment & TEXT_ALIGN_HORIZONTAL_MASK) {
        case Text::TEXT_ALIGN_CENTER:
            return (float_t) root->m_pos_x + (float_t) (root->m_max_width * 0.5 - max_line_width * 0.5);

        case Text::TEXT_ALIGN_RIGHT:
            return (float_t)  root->m_pos_x + ((float_t) root->m_max_width - max_line_width);

        default:
            return (float_t) root->m_pos_x;
    }
}

TextMeshContext::TextMeshContext(const Text* root) : root(root) {
    if (root) {
        scale = root->get_font_scale();
    }
}

void TextMeshContext::add_attrib(text_attrib_t type, TextAttribute attrib) {
    attributes.emplace(type, attrib);
}

void TextMeshContext::reset_attribs() {
    attributes.clear();
}

void TextMeshContext::char_processed() {
    vertex_buffer = &vertex_buffer[attributes.begin()->second.stride * 4];
    idx_buffer = &idx_buffer[6];
    chars_processed++;
}

size_t TextMeshContext::find_elements_per_vert() {
    size_t elements = 0;

    if (TextAttribute* attrib = find_attrib(TextAttribPosition))
        elements += attrib->size;

    if (TextAttribute* attrib = find_attrib(TextAttribUV))
        elements += attrib->size;

    if (TextAttribute* attrib = find_attrib(TextAttribColor))
        elements += attrib->size;

    return elements;
}

TextAttribute* TextMeshContext::find_attrib(text_attrib_t type) {
    if (attributes.contains(type)) {
        return &attributes.at(type);
    }
    return nullptr;
}
