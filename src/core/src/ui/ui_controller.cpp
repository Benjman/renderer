#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <core/ui/ui_controller.h>

void UiController::render(const RunnerContext &context) {
}

void UiController::render() {
    if (element() && element()->renderable())
        glDrawElements(GL_TRIANGLES, element()->idx_count(), GL_UNSIGNED_INT, (void*) (element()->buffer_offset() * sizeof(GLuint)));

    if (!m_ui_children.empty()) {
        for (auto* child : m_ui_children) {
            child->render();
        }
    }
}

void UiController::generate_meshes(float_t *vert_buf, uint32_t *idx_buf, size_t *vert_cursor, size_t *idx_cursor, size_t* idx_pointer) {
    if (element())
        element()->generate_mesh(vert_buf, idx_buf, vert_cursor, idx_cursor, idx_pointer);

    for (auto* child : *ui_children()) {
        child->generate_meshes(vert_buf, idx_buf, vert_cursor, idx_cursor, idx_pointer);
    }
}
