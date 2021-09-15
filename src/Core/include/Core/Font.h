#ifndef CORE_FONT_H
#define CORE_FONT_H

#include <Core/Texture.h>
#include <string>

struct Font {
	Font(const std::string path);

	private:
		Texture texture = Texture(GL_TEXTURE_2D, 0, GL_RED, 1024, 1024, GL_RGB, GL_UNSIGNED_INT);

		void loadFont(const std::string path);

};

#endif // CORE_FONT_H
