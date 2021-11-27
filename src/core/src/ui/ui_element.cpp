#include <GL/gl.h>
#include <core/ui/ui_element.h>
#include <core/ui/ui_element_builder.h>
#include <core/ui/ui_element_mesh_generator.h>

UiElementBuilder UiElement::create(UiElement* parent) noexcept {
    return UiElementBuilder(parent);
}

UiElement& UiElement::operator=(const UiElement& element) {
    m_background_color = element.m_background_color;
    m_buffer_offset = element.m_buffer_offset;
    m_idx_count = element.m_idx_count;
    m_parent = element.m_parent;
    m_pos = element.m_pos;
    m_renderable = element.m_renderable;
    m_size = element.m_size;
    m_status = element.m_status;
    m_vert_count = element.m_vert_count;
    return *this;
}

void UiElement::generate_mesh(float_t* vert_buf, uint32_t* idx_buf, size_t* vert_cursor, size_t* idx_cursor, size_t* idx_pointer) {
    m_buffer_offset = *idx_cursor;

    UiElementMeshGenerator::generate(this,
            &vert_buf[*vert_cursor * UiElementMeshGenerator::ELEMENTS_PER_VERTEX],
            &idx_buf[*idx_cursor],
            &m_vert_count,
            &m_idx_count,
            *idx_pointer * 4);

    (*idx_pointer)++;
    *vert_cursor += m_vert_count;
    *idx_cursor += m_idx_count;
}
