#include <camera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(void) {
	m_position = glm::vec3(0, 0, -1);
	m_target = glm::vec3(0);
	m_up = glm::vec3(0, 1, 0);
	m_view_width = 0;
	m_view_height = 0;
	m_near_plane = 0;
	m_far_plane = 0;
	m_view = glm::mat4(1);
	m_proj = glm::mat4(1);
	m_proj = glm::mat4(1);

	update_view_matrix();
}

Camera::Camera(const Camera& camera) {
	*this = camera;
}

Camera& Camera::operator=(const Camera& camera) {
	m_position = camera.m_position;
	m_target = camera.m_target;
	m_up = camera.m_up;
	m_view_width = camera.m_view_width;
	m_view_height = camera.m_view_height;
	m_near_plane = camera.m_near_plane;
	m_far_plane = camera.m_far_plane;
	m_view = camera.m_view;
	m_proj = camera.m_proj;
	return *this;
}

void Camera::update_perspective_matrix(const float_t angle, const float_t viewport_width, const float_t viewport_height, const float_t near_plane, const float_t far_plane) {
	m_radians = glm::radians(angle);
	m_view_width = viewport_width;
	m_view_height = viewport_height;
	m_aspect_ratio = viewport_width / viewport_height;
	m_near_plane = near_plane;
	m_far_plane = far_plane;

	m_proj = glm::perspective(m_radians, m_aspect_ratio, m_near_plane, m_far_plane);
}

void Camera::update_orthogonal_matrix(const float_t viewport_width, const float_t viewport_height, const float_t near_plane, const float_t far_plane) {
	m_view_width = viewport_width;
	m_view_height = viewport_height;
	m_aspect_ratio = viewport_width / viewport_height;
	m_near_plane = near_plane;
	m_far_plane = far_plane;

	m_proj = glm::ortho(-2 * m_aspect_ratio, 2 * m_aspect_ratio, -2.0f, 2.0f, m_near_plane, m_far_plane);
}

void Camera::update_view_matrix() {
	m_view = glm::lookAt(m_position, m_target, m_up);
}
