#include <iostream>

#include <core/components/position2d.h>
#include <core/file.h>
#include <core/input.h>
#include <core/runner.h>

#include <shader.h>

#include "./components/ball.h"
#include "./components/block.h"
#include "./components/player.h"
#include "./components/sprite.h"

#include "./systems/collision_system.h"
#include "./systems/move_system.h"
#include "./systems/render_system.h"

const GLfloat vertices[] = {
    // positions
     1.f,  1.f, 0.f,
     1.f, -1.f, 0.f,
    -1.f, -1.f, 0.f,
    -1.f,  1.f, 0.f,

    // tex coords
    1.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,
};

const GLuint indices[] = {
    1, 2, 3,
    0, 1, 3,
};

class BreakoutRunner : public Runner {
    Texture texture = Texture(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_FLOAT);

    public:
    BreakoutRunner(GLFWwindow *window) : Runner(window) {
        File vert = load_file(RES_PATH(shaders/basic.vert));
        File frag = load_file(RES_PATH(shaders/basic.frag));
        Shader shader;
        shader.load((const char *)vert.buffer, vert.size, (const char *)frag.buffer,
                frag.size);
        shader.use();

        vao.createAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
        vao.createAttribute(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void *)(12 * sizeof(GLfloat)));

        texture.bind();
        texture.parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
        texture.parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
        texture.parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        texture.parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        const auto ball = m_registry.create();
        m_registry.emplace<Ball>(ball, -80, -80);
        m_registry.emplace<Position2D>(ball, 220, 250);
        m_registry.emplace<Sprite>(ball, 10, glm::vec3(0, 1, 0));

        const auto player = m_registry.create();
        m_registry.emplace<Player>(player, 150);
        m_registry.emplace<Position2D>(player, 38, 50);
        m_registry.emplace<Sprite>(player, 150, 10, glm::vec3(0, 1, 1));

        for (auto row = 0, rows = 8; row < rows; row++) {
            for (auto col = 0, cols = 15; col < cols; col++) {
                const auto x = (col + 1.) / cols * m_width;
                const auto y = ((row + 1.) / rows * m_height) + 50;

                const auto brick = m_registry.create();
                m_registry.emplace<Block>(brick, 1);
                m_registry.emplace<Position2D>(brick, x, y);
                m_registry.emplace<Sprite>(brick, 25, 15, glm::vec3(.8, .5, .5));
                collideables.blocks.emplace_back(brick);
            }
        }

        // Assign events to systems.
        m_dispatcher.sink<KeyDown>().connect<&MoveSystem::on_key_down>(move_system);
        m_dispatcher.sink<KeyUp>().connect<&MoveSystem::on_key_up>(move_system);
        // m_dispatcher.sink<ViewportSizeChange>().connect<&RenderSystem::set_viewport>(render_system);

        render_system.init(m_dispatcher);
        ViewportSizeChange v(m_width, m_height);
        render_system.set_viewport(v);

        collideables.ball = ball;
        collideables.player = player;
        collideables.registry = &m_registry;
    }

    protected:
    void init(const RunnerContext& context) override {
    }

    void update(const RunnerContext& context) override {
        if (input::any_key_pressed()) {
            m_dispatcher.trigger<KeyDown>(input::last_key_pressed());
        }
        if (input::any_key_released()) {
            m_dispatcher.trigger<KeyUp>(input::last_key_released());
        }

        move_system.update(context.delta, m_registry, m_width, m_height);
        collision_system.update(context.delta, collideables);
    }

    void render() override {
        render_system.render(m_registry, m_width, m_height);
    }

    void windowSizeChanged(int width, int height) override {
        m_dispatcher.trigger<ViewportSizeChange>(width, height);
        m_width = width;
        m_height = height;
    }

    private:
    CollisionHolder collideables;
    CollisionSystem collision_system;
    MoveSystem move_system;
    RenderSystem render_system;

    Vao vao = Vao();
    Vbo vbo = Vbo(GL_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(vertices), vertices, &vao);
    Vbo ebo = Vbo(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, sizeof(indices), indices, &vao);
};
