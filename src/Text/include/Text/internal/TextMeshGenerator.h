#ifndef TEXT_TEXT_MESH_GENERATOR_H
#define TEXT_TEXT_MESH_GENERATOR_H

#include <cmath> // float_t
#include <cstdint> // uint16_t
#include <vector>
#include <string>
#include <stb_truetype.h>

class Font;
class Text;

#define VERTICES_PER_CHAR 4

// elements: 2d position and uv
#define ELEMENTS_PER_VERT 4

namespace internal {
	class Line;

	struct Word {
		std::string value;
		float_t width = 0;

		void add_char(u_char c, Font* font, Line* line, float_t kern);
	};

	struct Line {
		std::vector<Word*> words;
		float_t width = 0;
		float_t max_width;

		Line(float_t max_width) : max_width(max_width) {}

		~Line() {
			for (auto word : words) {
				delete word;
			}
		}

		bool try_add_word(Word* word);
	};

	struct TextStructure {
		std::vector<Line*> lines;
		float_t width;
		float_t height;

		~TextStructure() {
			for (auto line : lines) {
				delete line;
			}
		}
	};

	void generate_text_mesh(Text* text);

	void generate_text_structure(Text *text, TextStructure& structure);

	void process_line(Line* line, Text* text, float_t* cursor_x, float_t* cursor_y, size_t* buffer_pointer);

	void process_quad(stbtt_aligned_quad quad, Text* text, size_t* buffer_pointer);
};

#endif // TEXT_TEXT_MESH_GENERATOR_H
