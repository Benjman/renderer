#ifndef TEXT_TEXT_MESH_GENERATOR_H
#define TEXT_TEXT_MESH_GENERATOR_H

#include <cmath>
#include <stb_truetype.h>
#include <string>
#include <vector>

class Text;
struct Font;

namespace internal {
    struct TextMeshGenerator {
		struct Word {
			std::string value;
			float_t width = 0;

			void add_char(TextMeshGenerator& generator, char c, float_t kern);
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

		Text& root;
        float_t scale = 1.0;
		std::vector<Line*> lines;

		TextMeshGenerator(Text& root) : root(root) {}

        ~TextMeshGenerator() {
            for (Line* line : lines) {
                delete line;
            }
        }

		void generate_mesh();

		void generate_structure();

		void process_line(Line* line, float_t* cursor_x, float_t* cursor_y, size_t* buffer_pointer);

		void process_quad(stbtt_aligned_quad quad, size_t* buffer_pointer);
    };
};

#endif // TEXT_TEXT_MESH_GENERATOR_H
