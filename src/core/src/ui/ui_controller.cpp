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

size_t UiController::generate_meshes(float_t *vert_buf, uint32_t *idx_buf, size_t quad_count) {
    if (element())
        quad_count += element()->generate_mesh(vert_buf, idx_buf, quad_count);

    for (auto* child : *ui_children()) {
        quad_count += child->generate_meshes(&vert_buf[quad_count * UI_ELEMENTS_PER_VERT * 4],
                                             &idx_buf[quad_count * UI_ELEMENTS_PER_INDEX],
                                             quad_count);
    }

    return quad_count;
}

void UiController::child_added(Controller *child) {
    if (auto* ui_child = dynamic_cast<UiController *>(child)) {
        m_ui_children.emplace_back(ui_child);
    }
}

void UiController::child_removed(Controller *child) {
    if (auto* ui_child = dynamic_cast<UiController*>(child)) {
        auto it = std::find(m_ui_children.begin(), m_ui_children.end(), ui_child);
        if (it == m_ui_children.end())
            // TODO warning log
            return;

        m_ui_children.erase(it);
        m_ui_children.emplace_back(ui_child);
    }
}
