#ifndef CORE_UI_UI_ELEMENT_BUILDER_H
#define CORE_UI_UI_ELEMENT_BUILDER_H

#include "ui_element.h"

#include <core/window.h>
#include <glm/ext/vector_float3.hpp>

class UiElementBuilder {
    public:
        UiElementBuilder(UiElement& root) : root(root) {
        }

        UiElementBuilder(UiElement* parent = nullptr) : root(parent) {
        }

        operator UiElement() const {
            return std::move(root);
        }

        UiElementBuilder& background_color(float_t color) {
            root.background_color(color);
            return *this;
        }

        UiElementBuilder& background_color(float_t r, float_t g, float_t b) {
            root.background_color(r, g, b, 1);
            return *this;
        }

        UiElementBuilder& background_color(float_t r, float_t g, float_t b, float_t a) {
            root.background_color(r, g, b, a);
            return *this;
        }

        UiElementBuilder& background_color(glm::vec3 background_color) {
            root.background_color(glm::vec4(background_color, 1.0));
            return *this;
        }

        UiElementBuilder& background_color(glm::vec4 background_color) {
            root.background_color(background_color);
            return *this;
        }

        UiElementBuilder& pos(float_t x, float_t y) {
            root.pos(x, y);
            return *this;
        }

        UiElementBuilder& pos(glm::vec2 pos) {
            root.pos(pos);
            return *this;
        }

        UiElementBuilder& size(display_profile_t display_profile) {
            root.size(window::find_display_profile_width(display_profile), window::find_display_profile_height(display_profile));
            return *this;
        }

        UiElementBuilder& height(float_t h) {
            root.height(h);
            return *this;
        }

        UiElementBuilder& width(float_t w) {
            root.width(w);
            return *this;
        }

        UiElementBuilder& size(float_t x, float_t y) {
            root.size(x, y);
            return *this;
        }

        UiElementBuilder& size(glm::vec2 size) {
            root.size(size);
            return *this;
        }

        UiElementBuilder& parent(UiElement* parent) {
            root.parent(parent);
            return *this;
        }

        UiElementBuilder& status(UiElementStatus status) {
            root.status(status);
            return *this;
        }

        UiElementBuilder& renderable(bool renderable) {
            root.renderable(renderable);
            return *this;
        }

    private:
        UiElement root;

};

#endif // CORE_UI_UI_ELEMENT_BUILDER_H
