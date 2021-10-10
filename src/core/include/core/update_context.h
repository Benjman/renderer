#ifndef CORE_UPDATE_STATE_H
#define CORE_UPDATE_STATE_H

#include <math.h> // double_t
#include <entt/fwd.hpp>

struct UpdateContext {
	double_t delta;
	entt::registry& registry;
	entt::dispatcher& dispatcher;

};


#endif // CORE_UPDATE_STATE_H
