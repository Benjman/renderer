#ifndef CAMERA_CAMERA_H
#define CAMERA_CAMERA_H

#include <math.h> // float_t
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Camera {
	public:
		Camera(void);
		Camera(const Camera& camera);
		Camera& operator=(const Camera& camera);
		~Camera(void) {}


	public:
		void update_perspective_matrix(const float_t angle, const float_t viewport_width, const float_t viewport_height, const float_t near_plane, const float_t far_plane);
		void update_orthogonal_matrix(const float_t viewport_width, const float_t viewport_height, const float_t near_plane, const float_t far_plane);
		void update_view_matrix();

		void on_resize(uint32_t width, uint32_t height);

		void rotate(const glm::vec3& axis, float_t degrees);
		const glm::vec3 target() const { return m_target; }
		const glm::vec3 up() const { return m_up - m_position; }
		glm::vec3 const look_at_target() { return m_target - m_position; }

		glm::mat4 m_view;
		glm::mat4 m_proj;
		glm::vec3 m_position = glm::vec3(0, 0, 1);
		glm::vec3 m_target = glm::vec3(0, 0, 0);
		glm::vec3 m_up = glm::vec3(0, 1, 0);
		float_t m_aspect_ratio;
		float_t m_far_plane;
		float_t m_near_plane;
		float_t m_radians; // angle between view frustum's upper plane and bottom plane in radians, projection angle
		float_t m_view_height; // orthogonal frustum
		float_t m_view_width; // orthogonal frustum
};

#endif // CAMERA_CAMERA_H
