#include "generator.h"
#include <text.h>

#include <utility>
#include <limits>
#include <iostream>

TextBuilder Text::create(std::string value, Font *font) {
    return TextBuilder(value, font);
}

using namespace internal;
void Text::calc_sizes(size_t *vert_buf_size, size_t *idx_buf_size) {
    TextMeshGenerator::calc_buf_sizes(this, vert_buf_size, idx_buf_size);
}

void Text::generate_mesh(float_t* vert_buf, uint32_t* idx_buf, float_t display_height, float_t aspect_ratio) {
    TextMeshGenerator::generate(*this, vert_buf, idx_buf, display_height, aspect_ratio);
}

void Text::reset() {
    renderable_char_count = 0;
}