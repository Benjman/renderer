#ifndef BREAKOUT_RENDERSYSTEM_H
#define BREAKOUT_RENDERSYSTEM_H

#include <GL/gl.h>
#include <entt/fwd.hpp>
#include <vector>

#include <core/events.h>

class RenderSystem final {
    public:
        RenderSystem() = default;

        void init(entt::dispatcher& dispatcher);

        void render(entt::registry &registry, int width, int height);

        void set_viewport(const ViewportSizeChange &data);

    private:
        std::vector<GLfloat> m_texture;

};

#endif // BREAKOUT_RENDERSYSTEM_H
