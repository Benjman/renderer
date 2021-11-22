#ifndef CORE_UI_UI_ELEMENT
#define CORE_UI_UI_ELEMENT

#include <shader/fwd.h>

#include <cmath>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

class UiElementBuilder;

class UiElement {
    public:
        static UiElement BLANK;
        static constexpr glm::vec4 NO_BACKGROUND = glm::vec4(-1.0);

        static UiElementBuilder create(UiElement* parent = nullptr) noexcept;

        static UiElement& blank() { return BLANK; }

        enum class Status {
            Active = 1, Dormant = 0
        };

    public:
        explicit UiElement(UiElement* parent = nullptr) : m_parent(parent) {
        }

        UiElement(const UiElement& element) {
            *this = element;
        }

        UiElement& operator=(const UiElement& element);

        glm::vec4 background_color() const noexcept {
            return m_background_color;
        }

        void background_color(float_t color) noexcept {
            background_color(color, color, color, 1);
        }

        void background_color(float_t r, float_t g, float_t b, float_t a) noexcept {
            m_background_color = glm::vec4(r, g, b, a);
        }

        void background_color(glm::vec4 background_color) noexcept {
            m_background_color = glm::vec4(background_color);
        }

        bool has_background_color() noexcept {
            return glm::vec4(-1) != m_background_color;
        }

        glm::vec2 pos() const noexcept {
            return m_pos;
        }

        void pos(float_t x, float_t y) noexcept {
            m_pos = glm::vec2(x, y);
        }

        void pos(glm::vec2 pos) noexcept {
            m_pos = glm::vec2(pos);
        }

        void height(float_t h) noexcept {
            m_size.y = h;
        }

        void width(float_t w) noexcept {
            m_size.x = w;
        }

        glm::vec2 size() const noexcept {
            return m_size;
        }

        void size(float_t x, float_t y) noexcept {
            m_size = glm::vec2(x, y);
        }

        void size(glm::vec2 size) noexcept {
            m_size = glm::vec2(size);
        }

        [[nodiscard]] UiElement* parent() const noexcept {
            return m_parent;
        }

        void parent(UiElement* parent) noexcept {
            m_parent = parent;
        }

        glm::vec2 screen_pos() const noexcept {
            if (parent()) {
                return parent()->pos() + pos();
            }
            return glm::vec2(pos());
        }

        Status status() const noexcept {
            return m_status;
        }

        void status(Status status) noexcept {
            m_status = status;
        }

        inline bool renderable() const noexcept {
            return m_renderable;
        }

        void renderable(bool renderable) noexcept {
            m_renderable = renderable;
        }

        void idx_count(size_t c) noexcept {
            m_idx_count = c;
        }

        size_t idx_count() const noexcept {
            return m_idx_count;
        }

        void vertex_count(size_t c) noexcept {
            m_vert_count = c;
        }

        size_t vertex_count() const noexcept {
            return m_vert_count;
        }

        void generate_mesh(float_t* vert_buf, uint32_t* idx_buf, size_t* vert_cursor, size_t* idx_cursor, size_t* idx_pointer);

        size_t buffer_offset() const noexcept {
            return m_buffer_offset;
        }

    private:
         UiElement* m_parent = nullptr;
         glm::vec4 m_background_color = glm::vec4(NO_BACKGROUND);
         glm::vec2 m_pos = glm::vec2(0);
         glm::vec2 m_size = glm::vec2(0);
         Status m_status = Status::Active;
         bool m_renderable = true;

         size_t m_vert_count = 0;
         size_t m_idx_count = 0;
         size_t m_buffer_offset = 0;

};

using UiElementStatus = UiElement::Status;

#endif // CORE_UI_UI_ELEMENT
