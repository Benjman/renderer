#ifndef CORE_CAMERA_CONTROLLER_H
#define CORE_CAMERA_CONTROLLER_H

#include <Core/Controller.h>
#include <Camera.h>

class CameraController : public Controller {
	public:
		CameraController(Camera::Type type);

		void init(ControllerContext &context) override;
		void update(ControllerContext &context) override;

	protected:
};

#endif // CORE_CAMERA_CONTROLLER_H
