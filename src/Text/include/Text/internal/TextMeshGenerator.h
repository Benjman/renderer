#ifndef TEXT_TEXT_MESH_GENERATOR_H
#define TEXT_TEXT_MESH_GENERATOR_H

#include <cmath>
#include <stb_truetype.h>
#include <string>
#include <vector>

struct Text;
struct Font;

namespace internal {
	struct Line;

	struct TextMeshGenerationContext {
		std::vector<Line*> lines;
		Text* text;
		float_t width;
		float_t height;
		float_t aspect_ratio;
		float_t display_height;
		float_t text_size;
		float_t scale;

		~TextMeshGenerationContext();
	};

	struct Word {
		std::string value;
		float_t width = 0;

		void add_char(char c, TextMeshGenerationContext& context, float_t kern);
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

	void generate_text_mesh(Text* text);

	void generate_text_structure(Text *text, TextMeshGenerationContext& context);

	void process_line(Line* line, TextMeshGenerationContext& context, float_t* cursor_x, float_t* cursor_y, size_t* buffer_pointer);

	void process_quad(stbtt_aligned_quad quad, size_t* buffer_pointer, TextMeshGenerationContext& context);
};

#endif // TEXT_TEXT_MESH_GENERATOR_H
