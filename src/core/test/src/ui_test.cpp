#include <gtest/gtest.h>
#include "utils/gl_fixture.h"

#include <text.h>
#include <shader/texture.h>

#define private public
#define protected public
#include <core/ui/ui_element.h>

/****************
 * Parent tests *
 ****************/

TEST(UiTest_parent, initial) {
    UiElement el;
    ASSERT_EQ(nullptr, el.parent()) << "Parent expected to be null if one is not passed.";
}

TEST(UiTest_parent, from_constructor) {
    UiElement parent;
    UiElement child = UiElement(&parent);
    ASSERT_EQ(&parent, child.parent());
}

TEST(UiTest_parent, from_setter) {
    UiElement el;
    ASSERT_EQ(nullptr, el.parent()) << "Parent expected to be null if one is not passed.";
    UiElement parent;
    el.parent(&parent);
    ASSERT_EQ(&parent, el.parent());
}


/******************
 * Position tests *
 ******************/

TEST(UiTest_pos, element_pos_initial) {
    UiElement el;
    ASSERT_EQ(glm::vec2(0), el.pos());
}

TEST(UiTest_pos, element_pos) {
    UiElement el;
    el.pos(30, 100);
    ASSERT_EQ(glm::vec2(30, 100), el.pos()) << "Setting position with (x,y) values failed.";
    ASSERT_EQ(glm::vec2(30, 100), el.screen_pos()) << "Screen position shouldn't change if parent is not present.";

    el.pos(glm::vec2(15, 20));
    ASSERT_EQ(glm::vec2(15, 20), el.pos()) << "Setting position with glm::vec2 failed.";
}

TEST(UiTest_pos, element_pos_with_parent) {
    UiElement parent;
    parent.pos(50, 100);
    UiElement el(&parent);
    el.pos(25, 50);
    ASSERT_EQ(glm::vec2(25, 50), el.pos()) << "Child position should remain relative to parent.";
    ASSERT_EQ(parent.pos() + el.pos(), el.screen_pos()) << "Child screen position should account for parent position.";
}


/********************
 * Background tests *
 ********************/

TEST(UiTest_background, color_initial) {
    UiElement el;
    ASSERT_EQ(glm::vec3(-1), el.background_color());
    ASSERT_FALSE(el.has_background_color());
}

TEST(UiTest_background, color_has_background_color) {
    UiElement el;
    ASSERT_FALSE(el.has_background_color());
    el.background_color(1.0);
    ASSERT_TRUE(el.has_background_color());
}

TEST(UiTest_background, color_single_value) {
    UiElement el;
    el.background_color(1.0);
    ASSERT_EQ(glm::vec3(1), el.background_color());
}

TEST(UiTest_background, color_set) {
    UiElement el;
    el.background_color(.25, .1, .8);
    ASSERT_EQ(glm::vec3(.25, .1, .8), el.background_color()) << "Setting background_color color with (r,g,b) values failed.";

    el.background_color(glm::vec3(.5, .75, .88));
    ASSERT_EQ(glm::vec3(.5, .75, .88), el.background_color()) << "Setting background_color color with glm::vec3 failed.";
}

TEST(UiTest_background, texture_initial) {
    UiElement el;
    ASSERT_EQ(nullptr, el.texture());
    ASSERT_FALSE(el.has_texture());
}

TEST_F(GLFixture, texture_set) {
    UiElement el;
    Texture tex(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 2, GL_RGB, GL_UNSIGNED_BYTE);
    el.texture(&tex);
    ASSERT_EQ(&tex, el.texture());
    ASSERT_TRUE(el.has_texture());
}

