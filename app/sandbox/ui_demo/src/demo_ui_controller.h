#ifndef UI_DEMO_CONTROLLER_H
#define UI_DEMO_CONTROLLER_H

#include "ui_demo_elements.h"

#include <core/file.h>
#include <core/memory/element_buffer.h>
#include <core/memory/memory_zone.h>
#include <core/ui.h>
#include <core/window.h>

#include <shader/shader.h>
#include <shader/vao.h>
#include <shader/vbo.h>

class DemoUiController : public UiController {
    public:
        DemoUiController() : UiController() {
        }

        const Vao& vao() const noexcept {
            return m_vao;
        }

        void render() noexcept {
            m_vao.bind();
            for (auto* child : *ui_children()) {
                child->render();
            }
        }

    protected:
        void do_init(const RunnerContext &context) override {
            load_shader();

            size_t vert_cursor = 0,
                   idx_cursor = 0,
                   idx_pointer = 0;

            generate_meshes(buffer.vert_buffer.ptr, buffer.idx_buffer.ptr, &vert_cursor, &idx_cursor, &idx_pointer);

            m_vao.bind();
            m_vbo.storeData(buffer.vert_buffer.ptr, buffer.vert_buffer.max_size);
            m_ebo.storeData(buffer.idx_buffer.ptr, buffer.idx_buffer.max_size);

            m_vao.createAttribute(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) 0);
            m_vao.createAttribute(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) (2 * sizeof(GLfloat)));
            m_vao.createAttribute(2, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) (5 * sizeof(GLfloat)));
        }

    private:
        UiDemoElements elements;

        UiController m_top_bar = UiController(&elements.top_bar, this);
        UiController m_bottom_bar = UiController(&elements.bottom_bar, this);
        UiController m_button = UiController(&elements.button_bg, this);

        ElementBuffer buffer = ElementBuffer(MEGABYTES(10), MEGABYTES(3));

        Vao m_vao;
        Vbo m_vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
        Vbo m_ebo = Vbo(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);
        UiShader m_shader;

        void load_shader() {
            File vert = load_file(RES_PATH(shaders/ui.vert));
            File frag = load_file(RES_PATH(shaders/ui.frag));
            m_shader.load(vert.buffer, vert.size, frag.buffer, frag.size);
            m_shader.use();
        }

};

#endif // UI_DEMO_CONTROLLER_H
