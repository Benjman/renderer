#include <core/camera/camera_controller.h>
#include <core/window.h>

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

void CameraController::init() {
    m_camera.position(glm::vec3(0, 0, -3));
}

void CameraController::update(ControllerContext &context) {}

const glm::mat4 CameraController::view() const noexcept {
    return m_camera.view();
}

const glm::mat4 CameraController::proj_ortho() const noexcept {
    return m_camera.proj_ortho();
}

const glm::mat4 CameraController::proj_persp() const noexcept {
    return m_camera.proj_persp();
}
