#include <core/camera/camera_controller.h>
#include <core/runner_context.h>
#include <core/input.h>

#include <iostream>
#include <string>

#include <spdlog/spdlog.h>

void CameraController::init() {
    m_camera.position = glm::vec3(0.0, 0.0, -3.0);
}

void CameraController::update(const RunnerContext &context) {
    if (input::key_down(CAMERA_KEY_FORWARD))
        m_camera.position += glm::vec3(0, 0, m_translation_speed * context.delta);
    if (input::key_down(CAMERA_KEY_BACKWARD))
        m_camera.position -= glm::vec3(0, 0, m_translation_speed * context.delta);
    if (input::key_down(CAMERA_KEY_LEFT))
        m_camera.position += glm::vec3(m_translation_speed * context.delta, 0, 0);
    if (input::key_down(CAMERA_KEY_RIGHT))
        m_camera.position -= glm::vec3(m_translation_speed * context.delta, 0, 0);

    if (input::key_down(CAMERA_KEY_UP))
        m_camera.position -= glm::vec3(0, m_translation_speed * context.delta, 0);
    if (input::key_down(CAMERA_KEY_DOWN))
        m_camera.position += glm::vec3(0, m_translation_speed * context.delta, 0);
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
