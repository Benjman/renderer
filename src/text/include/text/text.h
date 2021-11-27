#ifndef TEXT_TEXT_H
#define TEXT_TEXT_H

#include <cmath>
#include <cstdint>
#include <string>

class Font;
struct TextBuilder;
class TextMeshGenerator;
struct TextMeshContext;

using text_align_t = size_t;

class Text {
    public:
        static inline constexpr size_t VERT_COUNT = 16;
        static inline constexpr size_t IDX_COUNT = 6;

        static inline constexpr text_align_t TEXT_ALIGN_LEFT = 0x1;
        static inline constexpr text_align_t TEXT_ALIGN_CENTER = 0x2;
        static inline constexpr text_align_t TEXT_ALIGN_RIGHT = 0x3;

        // TODO:
        static inline constexpr text_align_t TEXT_ALIGN_TOP = 0x1 << 2;
        static inline constexpr text_align_t TEXT_ALIGN_MIDDLE = 0x2 << 2;
        static inline constexpr text_align_t TEXT_ALIGN_BOTTOM = 0x3 << 2;

        static TextBuilder create(std::string value, const Font* font);

    public:
        Text() = default;

        Text(const Text& t);

        Text& operator=(const Text& text);

        void calc_sizes(size_t* vert_buf_size, size_t* idx_buf_size) const;

        void generate_mesh(float_t *vert_buf, uint32_t *idx_buf, float_t display_width, float_t display_height, size_t *idx_cursor = nullptr) const;

        void generate_mesh(TextMeshContext& context) const;

        void update_metadata();

        float_t get_font_scale() const;

        size_t renderable_char_count = 0;

        const Font* font() {
            return m_font;
        }

        std::string value() const {
            return m_value;
        }

    private:
        friend struct TextBuilder;
        friend class TextMeshGenerator;

        std::string m_value = "";
        const Font* m_font = nullptr;

         uint16_t m_alignment = TEXT_ALIGN_LEFT;
         float_t m_line_gap = 0.0;
         float_t m_line_height = 32.0;
         uint16_t m_max_height = std::numeric_limits<int16_t>::max();
         uint16_t m_max_width = std::numeric_limits<int16_t>::max();
         uint16_t m_pos_x = 0;
         uint16_t m_pos_y = 0;

        void reset();

};

#endif // TEXT_TEXT_H
