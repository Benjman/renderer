#pragma once

#include "shader/uniform.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <core/file.h>
#include <core/runner.h>
#include <glm/trigonometric.hpp>
#include <shader.h>
#include <sys/types.h>
#include <text.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#undef STB_IMAGE_IMPLEMENTATION

class SandboxRunner : public Runner {
    public:
        SandboxRunner(GLFWwindow *window, const uint32_t width, const uint32_t height) : Runner(window, width, height) {
            float_t aspect = (float_t) width / (float_t) height ;
            float vertices[] = {
                -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
                 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

                -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
                 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
            };

            File vert = load_file(RES_PATH("shaders/texture3d.vert"));
            File frag = load_file(RES_PATH("shaders/texture3d.frag"));

            shader.load((const char*) vert.buffer, vert.size, (const char*) frag.buffer, frag.size);
            shader.use();

            mvp.storeLocation(shader);

            vao.bind();
            vbo.storeData(vertices, sizeof(vertices));

            vao.createAttribute(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *) 0);
            vao.createAttribute(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *) (3 * sizeof(GLfloat)));

            int img_width, img_height, channels;
            stbi_set_flip_vertically_on_load(true);
            u_char* img_data = stbi_load(RES_PATH("textures/wall.jpg"), &img_width, &img_height, &channels, 3);

            Texture tex_wall(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 2, GL_RGB, GL_UNSIGNED_BYTE);
            tex_wall.upload(&img_data[0]);
            stbi_image_free(img_data);

            tex_wall.parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
            tex_wall.parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
            tex_wall.parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            tex_wall.parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            glEnable(GL_DEPTH_TEST);
        }

    protected:
        void update(const RunnerContext& context) override {
            // TODO this should really be in the render, add RunnerContext to render()
            glm::mat4 model = glm::rotate(glm::mat4(1.0), (float_t) context.running, glm::vec3(0.5, 1.0, 0.0));
            glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, -3.0));
            glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float_t) m_width / (float_t) m_height, 0.1f, 100.0f);
            mvp.load(proj * view * model);
        }

        void render() override {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        void windowSizeChanged(int width, int height) override {
        }

    private:
        Shader shader;

        Vao vao;
        Vbo vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
        UniformMatrix4f mvp = UniformMatrix4f("u_mvp");


};
