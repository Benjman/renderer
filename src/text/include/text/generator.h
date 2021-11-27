#ifndef TEXT_TEXT_MESH_GENERATOR_H
#define TEXT_TEXT_MESH_GENERATOR_H

#include <cmath>
#include <stb_truetype.h>
#include <string>
#include <vector>
#include <map>
#include <glm/vec3.hpp>
#include <text/text.h>

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
        const Text* root;
        glm::vec3 color;
        float_t* vertex_buffer;
        uint32_t* idx_buffer;
        size_t* char_count;
        float_t display_width;
        float_t display_height;

        explicit TextMeshContext(const Text* root);

        void add_attrib(text_attrib_t type, TextAttribute attrib);

        void reset_attribs();

        TextAttribute* find_attrib(text_attrib_t type);

    private:
        friend class TextMeshGenerator;

        std::map<text_attrib_t, TextAttribute> attributes;
        float_t cursor_x;
        float_t cursor_y;
        float_t scale;

};

class TextMeshGenerator {
    public:
        static void calc_buf_sizes(const Text* text, size_t* vert_size, size_t* idx_size);

        static void generate(const Text* root, float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height, size_t *offset);

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


        static void generate_structure(const Text* root, std::vector<Line> *lines);

        static void quad_to_screen_space(stbtt_aligned_quad &quad, float_t display_width, float_t display_height);

        static void store_quad(stbtt_aligned_quad quad, TextMeshContext& context, float* vert_buf);

        static void store_quad_pos(stbtt_aligned_quad quad, TextAttribute& attrib, float_t* vert_buf);

        static void store_quad_uv(stbtt_aligned_quad quad, TextAttribute& attrib, float_t* vert_buf);

        static void store_quad_color(glm::vec3& color, TextAttribute& attrib, float_t* vert_buf);

        static float_t find_horizontal_start(const Text* root, float_t max_line_width);

    private:
        TextMeshContext& context;

        explicit TextMeshGenerator(TextMeshContext& context);

        void start();

        void process_line(const Line &line) const;

};

#endif // TEXT_TEXT_MESH_GENERATOR_H
