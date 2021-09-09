#include <Core/Font.h>

#define STB_TRUETYPE_IMPLEMENTATION
#define STB_RECT_PACK_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stb_rect_pack.h>
#include <stb_truetype.h>
#include <stb_image_write.h>

#undef STB_TRUETYPE_IMPLEMENTATION
#undef STB_RECT_PACK_IMPLEMENTATION
#undef STB_IMAGE_WRITE_IMPLEMENTATION


Font::Font(const std::string path) {
	loadFont(path);
}

void Font::loadFont(const std::string path) {
	// TODO
}
