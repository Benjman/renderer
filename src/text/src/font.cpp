#include <cstdlib>
#define STB_RECT_PACK_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

// stb has a bunch of Wall errors, disabling them for the make process
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <stb_rect_pack.h>
#include <stb_truetype.h>
#include <stb_image_write.h>

#pragma GCC diagnostic pop

#undef STB_TRUETYPE_IMPLEMENTATION
#undef STB_RECT_PACK_IMPLEMENTATION
#undef STB_IMAGE_WRITE_IMPLEMENTATION

#include <text/font.h>
#include <iostream> // ghetto logging
#include <fstream>
#include <sstream>

Font Font::load_font(const char *path) {
    Font font;

    auto ss = std::ostringstream{};
    std::ifstream ifile(path);
    if (!ifile.is_open()) {
        std::cerr << "Couldn't open truetype file\n";
        exit(EXIT_FAILURE);
    }
    ss << ifile.rdbuf();
    auto buf = ss.str();

    if (!stbtt_PackBegin(&font.context, font.atlas_data, font.width, font.height, 0, 1, nullptr))
        // TODO error handling
        throw std::runtime_error("oh shit couldn't initialize stb_truetype\n");

    stbtt_PackFontRange(&font.context, (u_char*)&buf[0], 0, font.LINE_HEIGHT, 32, 95, font.chardata);
    stbtt_PackEnd(&font.context);

    // get metrics using old pai
    stbtt_fontinfo info;
    stbtt_InitFont(&info, (u_char*)&buf[0], 0);
    int32_t ascent, descent, line_gap;
    stbtt_GetFontVMetrics(&info, &ascent, &descent, &line_gap);
    float_t scale = stbtt_ScaleForPixelHeight(&info, font.LINE_HEIGHT);
    font.ascent = (float_t) ascent * scale;
    font.descent = (float_t) descent * scale;
    font.line_gap = (float_t) line_gap * scale;

    return font;
}

stbtt_aligned_quad Font::get_char(u_char c, float_t* cursor_x, float_t* cursor_y, float_t scale) const {
    stbtt_aligned_quad quad;
    float_t tmp_x = 0;
    stbtt_GetPackedQuad(chardata, width, height, c - 32, &tmp_x, cursor_y, &quad, 0);

    quad.x0 = quad.x0 * scale + *cursor_x;
    quad.x1 = quad.x1 * scale + *cursor_x;

    quad.y0 *= scale;
    quad.y1 *= scale;

    *cursor_x += tmp_x * scale;

    return quad;
}
