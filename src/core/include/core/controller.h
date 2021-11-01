#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

#include <core/fwd.hpp>

#include <cmath> // double_t
#include <entt/fwd.hpp>

class Controller {
	public:
		virtual void init() = 0;
		virtual void update(const RunnerContext& context) = 0;
};

#endif // CORE_CONTROLLER_H
