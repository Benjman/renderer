#include <text/internal/generator.h>
#include <text.h>

#include <utility>
#include <limits>
#include <iostream>

TextBuilder Text::create(std::string value, Font *font, float_t display_height, float_t aspect_ratio) {
    return TextBuilder(value, font, display_height, aspect_ratio);
}

void Text::generate_mesh() {
    internal::TextMeshGenerator generator(*this);
    generator.generate_mesh();
}
