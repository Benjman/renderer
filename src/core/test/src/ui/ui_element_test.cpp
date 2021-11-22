#include <gtest/gtest.h>
#include "core/memory/element_buffer.h"
#include "../utils/gl_fixture.h"

#include <text.h>
#include <core/file.h>

#define private public
#define protected public
#include <core/ui/ui_element.h>
#include <core/ui/ui_element_builder.h>

static Text EMPTY_TEXT = Text::create("", nullptr);
static Font FONT_DEJAVU = Font::load_font(RES_PATH(fonts/DejaVuSans.ttf));

TEST(TextUiElement, parent_initial) {
    UiElement el;
    ASSERT_EQ(nullptr, el.m_parent) << "Parent expected to be null if one is not passed.";
}

TEST(UiElement, parent_from_constructor) {
    UiElement parent;
    UiElement child = UiElement(&parent);
    ASSERT_EQ(&parent, child.m_parent);
}

TEST(UiElement, parent_from_setter) {
    UiElement el;
    ASSERT_EQ(nullptr, el.m_parent) << "Parent expected to be null if one is not passed.";
    UiElement parent;
    el.parent(&parent);
    ASSERT_EQ(&parent, el.m_parent);
}


TEST(UiElement, pos_element_pos_initial) {
    UiElement el;
    ASSERT_EQ(glm::vec2(0), el.pos());
}

TEST(UiElement, pos_element_pos) {
    UiElement el;
    el.pos(30, 100);
    ASSERT_EQ(glm::vec2(30, 100), el.pos()) << "Setting position with (x,y) values failed.";
    ASSERT_EQ(glm::vec2(30, 100), el.screen_pos()) << "Screen position shouldn't change if parent is not present.";

    el.pos(glm::vec2(15, 20));
    ASSERT_EQ(glm::vec2(15, 20), el.pos()) << "Setting position with glm::vec2 failed.";
}

TEST(UiElement, pos_element_pos_with_parent) {
    UiElement parent;
    parent.pos(50, 100);
    UiElement el(&parent);
    el.pos(25, 50);
    ASSERT_EQ(glm::vec2(25, 50), el.pos()) << "Child position should remain relative to parent.";
    ASSERT_EQ(parent.pos() + el.pos(), el.screen_pos()) << "Child screen position should account for parent position.";
}


TEST(UiElement, background_color_initial) {
    UiElement el;
    ASSERT_EQ(glm::vec4(-1), el.background_color());
    ASSERT_FALSE(el.has_background_color());
}

TEST(UiElement, background_color_has_background_color) {
    UiElement el;
    ASSERT_FALSE(el.has_background_color());
    el.background_color(1.0);
    ASSERT_TRUE(el.has_background_color());
}

TEST(UiElement, background_color_single_value) {
    UiElement el;
    el.background_color(1.0);
    ASSERT_EQ(glm::vec4(1), el.background_color());
}

TEST(UiElement, background_color_set) {
    UiElement el;
    el.background_color(.25, .1, .8, 1.0);
    ASSERT_EQ(glm::vec4(.25, .1, .8, 1.0), el.background_color()) << "Setting background_color color with (r,g,b) values failed.";

    el.background_color(glm::vec4(.5, .75, .88, 1.0));
    ASSERT_EQ(glm::vec4(.5, .75, .88, 1.0), el.background_color()) << "Setting background_color color with glm::vec4 failed.";
}

TEST(UiElementBuilder, background_color) {
    float_t color = 1.0;
    UiElementBuilder builder;
    builder.background_color(color);
    ASSERT_EQ(glm::vec4(color), builder.root.background_color());
}

TEST(UiElementBuilder, background_color_r_g_b) {
    float_t r = 1.0;
    float_t g = 2.0;
    float_t b = 3.0;
    float_t a = 1.0;
    UiElementBuilder builder;
    builder.background_color(r, g, b);
    ASSERT_EQ(glm::vec4(r, g, b, 1.0), builder.root.background_color()) << "Alpha channel should default to 1.0";
    builder.background_color(r, g, b, a);
    ASSERT_EQ(glm::vec4(r, g, b, a), builder.root.background_color());
}

TEST(UiElementBuilder, background_color_background_color) {
    glm::vec4 background_color = glm::vec4(2, 4, 6, 1.0);
    UiElementBuilder builder;
    builder.background_color(background_color);
    ASSERT_EQ(background_color, builder.root.background_color());
}

TEST(UiElementBuilder, pos_x_y) {
    float_t x = 3;
    float_t y = 7;
    UiElementBuilder builder;
    builder.pos(x, y);
    ASSERT_EQ(glm::vec2(x, y), builder.root.pos());
}

TEST(UiElementBuilder, pos_pos) {
    glm::vec2 pos = glm::vec2(13, 17);
    UiElementBuilder builder;
    builder.pos(pos);
    ASSERT_EQ(pos, builder.root.pos());
}

TEST(UiElementBuilder, parent_parent_from_constructor) {
    UiElement parent;
    UiElementBuilder builder(&parent);
    ASSERT_EQ(&parent, builder.root.m_parent);
}

TEST(UiElementBuilder, parent_parent_from_setter) {
    UiElement parent;
    UiElementBuilder builder;
    builder.parent(&parent);
    ASSERT_EQ(&parent, builder.root.m_parent);
}

TEST(UiElementBuilder, with_root) {
    UiElement root;
    root.pos(13, 23);
    UiElementBuilder builder(root);
    ASSERT_EQ(glm::vec2(13, 23), builder.root.pos());
}
