#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

#include <math.h> // double_t
#include <entt/fwd.hpp>

struct ControllerContext {
	double_t delta = 0;
	entt::registry& registry;
	entt::dispatcher& dispatcher;

	ControllerContext(entt::registry& registry, entt::dispatcher& dispatcher) : registry(registry), dispatcher(dispatcher) {}
};

class Controller {
	public:
		virtual void init(ControllerContext& context) = 0;
		virtual void update(ControllerContext& context) = 0;
};

#endif // CORE_CONTROLLER_H
