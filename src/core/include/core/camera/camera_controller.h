#ifndef CORE_CAMERA_CONTROLLER_H
#define CORE_CAMERA_CONTROLLER_H

#include "camera.h"
#include "../controller.h"

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

    public:
        void init(); // TODO delete me
		void init(ControllerContext& context) override {}
		void update(ControllerContext& context) override;

        const glm::mat4 view() const noexcept;
        const glm::mat4 proj_ortho() const noexcept;
        const glm::mat4 proj_persp() const noexcept;
};

#endif // CORE_CAMERA_CONTROLLER_H
