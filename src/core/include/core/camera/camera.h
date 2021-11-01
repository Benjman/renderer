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

    private:
        glm::vec3 m_position;
        float_t m_dist;
        float_t m_pitch;
        float_t m_yaw;

    public:
        Camera() = default;
        Camera(const Camera& camera);
        Camera operator=(const Camera& camera);

        const glm::mat4 view() const noexcept;
        const glm::mat4 proj_ortho() const noexcept;
        const glm::mat4 proj_persp() const noexcept;

        [[nodiscard]] glm::vec3 position() const noexcept { return m_position; }
        void position(glm::vec3 position) noexcept { m_position = glm::vec3(position); }

        [[nodiscard]] const float_t dist() const noexcept { return m_dist; }
        void dist(float_t& dist) noexcept { m_dist = dist; }

        [[nodiscard]] const float_t pitch() const noexcept { return m_pitch; }
        void pitch(float_t& pitch) noexcept { m_pitch = pitch; }

        [[nodiscard]] const float_t yaw() const noexcept { return m_yaw; }
        void yaw(float_t& yaw) noexcept { m_yaw = yaw; }

};

#endif // CORE_CAMERA_H

