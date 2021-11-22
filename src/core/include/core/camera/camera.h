#ifndef CORE_CAMERA_H
#define CORE_CAMERA_H

#include <cmath>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Camera {
    public:
        static constexpr glm::vec3 WORLD_UP = glm::vec3(0, 1, 0);
        static constexpr glm::vec3 WORLD_RIGHT = glm::vec3(1, 0, 0);
        static constexpr float_t DIST_SENSITIVITY = 0.0;
        static constexpr float_t PITCH_SENSITIVITY = 0.0;
        static constexpr float_t TRANSLATION_SENSITIVITY = 0.0;
        static constexpr float_t YAW_SENSITIVITY = 0.0;
        static constexpr float_t NEAR_PLANE = 0.1;
        static constexpr float_t FAR_PLANE = 10.0;
        static constexpr float_t FOV = 45.0;

    public:
        glm::vec3 position;

        float_t dist = 0;
        float_t pitch = 0;
        float_t yaw = 0;

        Camera() = default;
        Camera(const Camera& camera);
        Camera& operator=(const Camera& camera);

        const glm::mat4 view() const noexcept;
        const glm::mat4 proj_ortho() const noexcept;
        const glm::mat4 proj_persp() const noexcept;

};

#endif // CORE_CAMERA_H

