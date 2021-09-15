#include <Core/Camera2D.h>

void Camera2D::update(double dt) {
}

glm::mat4 Camera2D::getViewMatrix() const {
	return glm::mat4(1);
}
