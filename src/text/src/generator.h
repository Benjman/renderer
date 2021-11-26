#ifndef TEXT_TEXT_MESH_GENERATOR_H
#define TEXT_TEXT_MESH_GENERATOR_H

#include <cmath>
#include <stb_truetype.h>
#include <string>
#include <vector>
#include <map>
#include <glm/vec3.hpp>

class Text;
struct Font;

namespace internal { // TODO remove internal namespace, this will be exposed as a public api

    using text_attrib_t = size_t;
    static constexpr text_attrib_t TextAttribPosition = 0x1;
    static constexpr text_attrib_t TextAttribUV = 0x2;
    static constexpr text_attrib_t TextAttribColor = 0x3;

    struct TextAttribute {
        size_t stride;
        size_t offset = 0;

        TextAttribute(size_t stride, size_t offset) : stride(stride), offset(offset) {}

    };

    struct TextMeshContext {
        public:
            const Text& root;
            float_t* vertex_buffer;
            uint32_t* idx_buffer;
            size_t* idx_pointer;
            float_t display_width,
                    display_height;

            TextMeshContext(const Text& root);

            void add_attrib(text_attrib_t type, TextAttribute attrib) {
                attributes.emplace(type, attrib);
            }

            TextAttribute* find_attrib(text_attrib_t type) {
                if (attributes.contains(type)) {
                    return &attributes.at(type);
                }
                return nullptr;
            }

        private:
            friend class TextMeshGenerator;

            std::map<text_attrib_t, TextAttribute> attributes;
            float_t cursor_x,
                    cursor_y,
                    scale;
    };

    class TextMeshGenerator {
        public:
            static void calc_buf_sizes(const Text& text, size_t* vert_size, size_t* idx_size);

            static void generate(const Text &root, float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height, size_t *idx_pointer);

            static void generate(TextMeshContext& context);

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


            static void generate_structure(const Text &root, std::vector<Line> *lines);

            static void quad_to_screen_space(stbtt_aligned_quad &quad, float_t display_width, float_t display_height);

            static void store_quad(stbtt_aligned_quad quad, TextMeshContext& context, size_t idx_offset, float* vert_buf, uint32_t* idx_buf);

            static void store_quad_pos(stbtt_aligned_quad quad, TextAttribute& attrib, float* vert_buf);

            static void store_quad_uv(stbtt_aligned_quad quad, TextAttribute& attrib, float* vert_buf);

            static void store_quad_color(glm::vec3& color, TextAttribute& attrib, float* vert_buf);

        private:
            explicit TextMeshGenerator(TextMeshContext& context);

            void process_line(const Line &line, TextMeshContext& context) const;

    };
};

#endif // TEXT_TEXT_MESH_GENERATOR_H
