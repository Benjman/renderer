#include <core/config.h>
#include <core/ui/ui_fonts.h>
#include <text/font.h>
#include <shader/texture.h>

static Font* font_DejaVuSans = nullptr;
static Texture* texture_DejaVuSans = nullptr;

void init_font_texture(Font* font, Texture* texture) {
    texture = new Texture(GL_TEXTURE_2D, 0, GL_RED, Font::ATLAS_WIDTH, Font::ATLAS_HEIGHT, 0, GL_RED, GL_UNSIGNED_BYTE);
    texture->bind();
    texture->upload(font->atlas_data);
    texture->parameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    texture->parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Font* fonts::DejaVuSans() {
    if (!font_DejaVuSans) {
        font_DejaVuSans = new Font;
        Font::load_font(RES_PATH(fonts/DejaVuSans.ttf), font_DejaVuSans);
        init_font_texture(font_DejaVuSans, texture_DejaVuSans);
    }
    return font_DejaVuSans;
}

void fonts::cleanup() {
    delete font_DejaVuSans;
    delete texture_DejaVuSans;
}
