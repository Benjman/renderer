#include <core/camera/camera.h>
#include <core/window.h>

#include <cmath>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <spdlog/spdlog.h>

Camera::Camera(const Camera& camera) {
    *this = camera;
}

Camera Camera::operator=(const Camera &camera) {
    dist = camera.dist;
    pitch = camera.pitch;
    position = camera.position;
    yaw = camera.yaw;
    return *this;
}

const glm::mat4 Camera::view() const noexcept {
    glm::mat4 view = glm::rotate(glm::mat4(1), glm::radians(pitch), WORLD_RIGHT);
    view = glm::rotate(view, glm::radians(yaw), WORLD_UP);
    view = glm::translate(view, position);
    return view;
}

const glm::mat4 Camera::proj_ortho() const noexcept {
    return glm::ortho(-2.0f, 2.0f, 2.0f, 2.0f, NEAR_PLANE, FAR_PLANE);
}

const glm::mat4 Camera::proj_persp() const noexcept {
    return glm::perspective(glm::radians(FOV), window::aspect_ratio(), NEAR_PLANE, FAR_PLANE);
}
