#include <GL/gl.h>
#include <core/ui/ui_element.h>
#include <core/ui/ui_element_builder.h>
#include <core/ui/ui_element_mesh_generator.h>

UiElementBuilder UiElement::create(UiElement *parent) noexcept {
    return UiElementBuilder(parent);
}

UiElement& UiElement::operator=(const UiElement& element) {
    m_background_color = element.m_background_color;
    m_idx_count = element.m_idx_count;
    m_parent = element.m_parent;
    m_pos = element.m_pos;
    m_renderable = element.m_renderable;
    m_size = element.m_size;
    m_status = element.m_status;
    m_vert_count = element.m_vert_count;
    return *this;
}

size_t UiElement::generate_mesh(float_t *vert_buf, uint32_t *idx_buf, size_t idx_pointer) {
    m_buffer_offset = idx_pointer * 6;
    size_t quad_count = 0;
    quad_count = UiElementMeshGenerator::generate(this, vert_buf, idx_buf, idx_pointer);
    m_idx_count = quad_count * Text::ELEMENTS_PER_INDEX;
    return quad_count;
}