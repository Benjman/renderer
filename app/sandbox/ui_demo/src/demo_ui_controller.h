#ifndef UI_DEMO_CONTROLLER_H
#define UI_DEMO_CONTROLLER_H

#include "core/ui/ui_fonts.h"
#include "ui_demo_elements.h"

#include <core/file.h>
#include <core/memory/element_buffer.h>
#include <core/ui.h>

#include <shader/vao.h>
#include <shader/vbo.h>

class DemoUiController : public UiController {
    public:
        DemoUiController() : UiController() {
        }

        void render() noexcept {
            vao.bind();
            for (auto* child : *ui_children()) {
                child->render();
            }
        }

    protected:
        void do_init(const RunnerContext &context) override {
            size_t vert_cursor = 0,
                   idx_cursor = 0,
                   idx_pointer = 0;

            float_t v[2048 * 4]{0};
            uint32_t i[2048 * 4]{0};

            generate_meshes(buffer.vert_buffer.ptr, buffer.idx_buffer.ptr, &vert_cursor, &idx_cursor, &idx_pointer);

            vao.bind();
            vbo.storeData(buffer.vert_buffer.ptr, buffer.vert_buffer.max_size);
            ebo.storeData(buffer.idx_buffer.ptr, buffer.idx_buffer.max_size);

            vao.createAttribute(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) 0);
            vao.createAttribute(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) (3 * sizeof(GLfloat)));
            vao.createAttribute(2, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) (5 * sizeof(GLfloat)));

            load_shader();
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }

    private:
        UiDemoElements elements;

        //UiController top_bar = UiController(&elements.top_bar, this);
        //UiController bottom_bar = UiController(&elements.bottom_bar, this);
        //UiController button = UiController(&elements.button_bg, this);
        LabelController label = LabelController(&elements.label, this);

        ElementBuffer buffer = ElementBuffer(KILOBYTES(5), KILOBYTES(5));

        Vao vao;
        Vbo vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
        Vbo ebo = Vbo(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);
        UiShader shader;

        void load_shader() {
            File vert = load_file(RES_PATH(shaders/ui.vert));
            File frag = load_file(RES_PATH(shaders/ui.frag));
            shader.load(vert.buffer, vert.size, frag.buffer, frag.size);
            shader.use();
        }

};

#endif // UI_DEMO_CONTROLLER_H
