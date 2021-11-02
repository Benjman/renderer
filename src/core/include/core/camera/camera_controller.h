#ifndef CORE_CAMERA_CONTROLLER_H
#define CORE_CAMERA_CONTROLLER_H

#include "camera.h"
#include "../controller.h"
#include "../input.h"

#include <glm/mat4x4.hpp>

class CameraController : public Controller {
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
        Camera m_camera;
        float_t m_translation_speed = 1.5; // units per second

        int CAMERA_KEY_FORWARD = KEY_E;
        int CAMERA_KEY_BACKWARD = KEY_D;
        int CAMERA_KEY_LEFT = KEY_S;
        int CAMERA_KEY_RIGHT = KEY_F;
        int CAMERA_KEY_UP = KEY_A;
        int CAMERA_KEY_DOWN = KEY_Z;

    public:
		void init() override;
		void update(const RunnerContext& context) override;

        const glm::mat4 view() const noexcept;
        const glm::mat4 proj_ortho() const noexcept;
        const glm::mat4 proj_persp() const noexcept;
};

#endif // CORE_CAMERA_CONTROLLER_H
