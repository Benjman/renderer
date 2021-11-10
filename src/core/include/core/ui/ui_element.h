#ifndef CORE_UI_UI_ELEMENT
#define CORE_UI_UI_ELEMENT

#include <shader/fwd.h>

#include <cmath>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class UiElement {
    private:
        UiElement* m_parent;

        glm::vec2 m_pos = glm::vec2(0);
        glm::vec3 m_background_color = glm::vec3(-1); // -1 represents no bg
        Texture* m_texture = nullptr;

    public:
        // TODO copy and move constructors

        UiElement(UiElement* parent = nullptr) : m_parent(parent) {}

        glm::vec3 background_color() const noexcept {
            return m_background_color;
        }

        void background_color(float_t color) {
            background_color(color, color, color);
        }

        void background_color(float_t r, float_t g, float_t b) {
            m_background_color = glm::vec3(r, g, b);
        }

        void background_color(glm::vec3 background_color) {
            m_background_color = glm::vec3(background_color);
        }

        bool has_background_color() {
            return glm::vec3(-1) != m_background_color;
        }

        [[nodiscard]] Texture* texture() const noexcept {
            return m_texture;
        }

        void texture(Texture* texture) {
            m_texture = texture;
        }

        bool has_texture() {
            return m_texture != nullptr;
        }

        glm::vec2 pos() const noexcept {
            return m_pos;
        }

        void pos(float_t x, float_t y) {
            m_pos = glm::vec2(x, y);
        }

        void pos(glm::vec2 pos) {
            m_pos = glm::vec2(pos);
        }

        [[nodiscard]] UiElement* parent() const noexcept {
            return m_parent;
        }

        void parent(UiElement* parent) {
            m_parent = parent;
        }

        glm::vec2 screen_pos() const noexcept {
            if (parent()) {
                return parent()->pos() + pos();
            }
            return glm::vec2(pos());
        }

};

#endif // CORE_UI_UI_ELEMENT
