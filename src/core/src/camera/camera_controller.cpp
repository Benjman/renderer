#include <core/camera/camera_controller.h>
#include <core/runner_context.h>
#include <core/input.h>

#include <iostream>
#include <string>

void CameraController::do_init(const RunnerContext& context) {
    m_camera.position = glm::vec3(0.0, 0.0, -3.0);
}

void CameraController::do_update(const RunnerContext &context) {
    input(context);
}

void CameraController::input(const RunnerContext &context) {
    if (input::key_down(TRANSLATE_KEY_FORWARD))
        m_camera.position += glm::vec3(0, 0, m_translation_speed * context.delta);
    if (input::key_down(TRANSLATE_KEY_BACKWARD))
        m_camera.position -= glm::vec3(0, 0, m_translation_speed * context.delta);
    if (input::key_down(TRANSLATE_KEY_LEFT))
        m_camera.position += glm::vec3(m_translation_speed * context.delta, 0, 0);
    if (input::key_down(TRANSLTE_KEY_RIGHT))
        m_camera.position -= glm::vec3(m_translation_speed * context.delta, 0, 0);

    if (input::key_down(TRANSLATE_KEY_UP))
        m_camera.position -= glm::vec3(0, m_translation_speed * context.delta, 0);
    if (input::key_down(TRANSLATE_KEY_DOWN))
        m_camera.position += glm::vec3(0, m_translation_speed * context.delta, 0);

    if (input::mouse_down(MOUSE_BUTTON_LEFT)) {
        m_camera.pitch += input::mouse_dy() * PITCH_SENSITIVITY;
        m_camera.yaw += input::mouse_dx() * YAW_SENSITIVITY;
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
