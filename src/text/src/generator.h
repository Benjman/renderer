#ifndef TEXT_TEXT_MESH_GENERATOR_H
#define TEXT_TEXT_MESH_GENERATOR_H

#include <cmath>
#include <stb_truetype.h>
#include <string>
#include <vector>

class Text;
struct Font;

namespace internal {
    class TextMeshGenerator {
        public:
            static void generate(Text &root, float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height);

            static void calc_buf_sizes(Text& text, size_t* vert_size, size_t* idx_size);

        private:
            struct Word {
                std::string value;
                float_t width = 0;

                void add_char(char c, float_t width);

            };

            struct Line {
                std::vector<Word> words;
                float_t width = 0;
                float_t max_width;

                explicit Line(float_t max_width) : max_width(max_width) {}

                bool try_add_word(Word& word);

            };


            static void generate_structure(Text &root, std::vector<Line> *lines);

            static void quad_to_screen_space(stbtt_aligned_quad &quad, float_t display_width, float_t display_height);

            static void store_quad(stbtt_aligned_quad quad, size_t idx_offset, float* vert_buf, uint32_t* idx_buf);


            float_t scale = 1.0;

            TextMeshGenerator(Text &root, float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height);

            void process_line(Line &line, Text &root, float_t *vert_buf, uint32_t *idx_buf, float_t *cursor_x, float_t *cursor_y, size_t *pointer, float_t display_width, float_t display_height) const;

    };
};

#endif // TEXT_TEXT_MESH_GENERATOR_H
