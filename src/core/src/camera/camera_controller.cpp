#include <core/camera/camera_controller.h>
#include <core/runner_context.h>
#include <core/input.h>

#include <iostream>
#include <string>

#include <spdlog/spdlog.h>

void CameraController::init() {
    m_camera.position(glm::vec3(0.0, 0.0, -3.0));
}

void CameraController::update(const RunnerContext &context) {
    if (input::key_down(KEY_E)) {
        m_camera.position() += glm::vec3(1, 0, context.delta);
        spdlog::info("Camera pos: x({0:f}) y({1:f}) z({2:f})", m_camera.position().x, m_camera.position().y, m_camera.position().z);
    }
}

const glm::mat4 CameraController::view() const noexcept {
    return m_camera.view();
}

const glm::mat4 CameraController::proj_ortho() const noexcept {
    return m_camera.proj_ortho();
}

const glm::mat4 CameraController::proj_persp() const noexcept {
    return m_camera.proj_persp();
}
