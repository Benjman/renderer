#ifndef CORE_CAMERA2D_H
#define CORE_CAMERA2D_H

#include <Core/components/Position2D.h>
#include <glm/mat4x4.hpp>

class Camera2D {
	Position2D position;
	double zoom = 1.0;

	public:
		void update(double dt);

		glm::mat4 getViewMatrix() const;
};

#endif // CORE_CAMERA2D_H
