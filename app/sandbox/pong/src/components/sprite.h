#ifndef PONG_SPRITE_H
#define PONG_SPRITE_H

#include <glm/vec3.hpp>

class Sprite final {
    public:
        Sprite(const int w, const int h, const glm::vec3 color) noexcept;
        Sprite(const int radius, glm::vec3 color) noexcept;
        Sprite(Sprite&&) noexcept;
        ~Sprite() noexcept = default;
        Sprite& operator=(Sprite&&) noexcept;

    public:
        int width;
        int height;
        int radius;
        glm::vec3 color;

};

#endif // PONG_SPRITE_H
