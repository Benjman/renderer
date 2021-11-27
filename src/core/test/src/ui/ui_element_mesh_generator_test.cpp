#include "core/memory/memory_allocator.h"
#include "core/ui/ui_element.h"
#include <gtest/gtest.h>

#include <core/ui/ui_element_builder.h>

#define private public
#include <core/ui/ui_element_mesh_generator.h>

TEST(UiElementMeshGenerator, generate) {
    window::display_profile(DISPLAY_PROFILE_640_480);

    UiElement el = UiElement::create()
        .pos(15.0, 15.0)
        .size(100.0, 150.0);

    float_t v_buf[KILOBYTES(5)];
    uint32_t i_buf[KILOBYTES(5)];

    size_t vert_cursor = 0;
    size_t idx_cursor = 0;
    size_t idx_pointer = 0;

    UiElementMeshGenerator::generate(&el, v_buf, i_buf, &vert_cursor, &idx_cursor, idx_pointer);
}
