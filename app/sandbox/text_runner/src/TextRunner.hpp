#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "core/ui/ui_fonts.h"
#include <core/memory/element_buffer.h>
#include <core/memory/memory_allocator.h>
#include <core/window.h>
#include <text/font.h>
#include <core/file.h>
#include <core/runner.h>
#include <core/memory.h>
#include <shader.h>
#include <text.h>

#include <iostream>

class TextRunner : public Runner {
    public:
        TextRunner(GLFWwindow *window) : Runner(window) {
            size_t index_count = 0;

            index_count += top_left.generate_mesh(buffer.vert_buffer.ptr,
                    buffer.idx_buffer.ptr,
                    window::width(),
                    window::height(),
                    index_count * 4);
            top_left.update_metadata();

            index_count += top_center.generate_mesh(
                    &buffer.vert_buffer.ptr[index_count * Text::ELEMENTS_PER_VERT],
                    &buffer.idx_buffer.ptr[index_count * Text::ELEMENTS_PER_INDEX],
                    window::width(),
                    window::height(),
                    index_count * 4);
            top_center.update_metadata();

            index_count += top_right.generate_mesh(
                    &buffer.vert_buffer.ptr[index_count * Text::ELEMENTS_PER_VERT],
                    &buffer.idx_buffer.ptr[index_count * Text::ELEMENTS_PER_INDEX],
                    window::width(),
                    window::height(),
                    index_count * 4);
            top_right.update_metadata();

            vao.bind();
            vbo.storeData(buffer.vert_buffer.ptr, buffer.vert_buffer.max_size);
            ebo.storeData(buffer.idx_buffer.ptr, buffer.idx_buffer.max_size);

            vao.createAttribute(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) 0);
            vao.createAttribute(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));
        }

    protected:
        void init(const RunnerContext& context) override {
            load_shader();
        }

        void update(const RunnerContext& context) override {
        }

        void render() override {
            glClear(GL_COLOR_BUFFER_BIT);
            glDrawElements(GL_TRIANGLES, 6 * top_left.renderable_quad_count, GL_UNSIGNED_INT, (void*) 0);
            glDrawElements(GL_TRIANGLES, 6 * top_center.renderable_quad_count, GL_UNSIGNED_INT, (void*) (top_left.renderable_quad_count * 6 * sizeof(uint32_t)));
            glDrawElements(GL_TRIANGLES, 6 * top_right.renderable_quad_count, GL_UNSIGNED_INT, (void*) (top_left.renderable_quad_count * 6  * sizeof(uint32_t) + top_center.renderable_quad_count * 6 * sizeof(uint32_t)));
        }

    private:
        ElementBuffer buffer = ElementBuffer(KILOBYTES(10), KILOBYTES(1));

        Text top_left = Text::create("left aligned", fonts::DejaVuSans())
            .line_height(32)
            .max_width(window::width())
            .max_height(window::height())
            .alignment(Text::TEXT_ALIGN_LEFT);
        Text top_center = Text::create("center aligned", fonts::DejaVuSans())
            .line_height(32)
            .max_width(window::width())
            .max_height(window::height())
            .alignment(Text::TEXT_ALIGN_CENTER);
        Text top_right = Text::create("right aligned", fonts::DejaVuSans())
            .line_height(32)
            .max_width(window::width())
            .max_height(window::height())
            .alignment(Text::TEXT_ALIGN_RIGHT);

        Vao vao = Vao();
        Vbo vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
        Vbo ebo = Vbo(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);

        void load_shader() {
            File vert = load_file(RES_PATH(shaders/text.vert));
            File frag = load_file(RES_PATH(shaders/text.frag));
            Shader shader;
            shader.load((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size);
            shader.use();
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }

};

#endif // SIMULATION_HPP
