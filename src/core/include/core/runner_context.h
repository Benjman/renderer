#ifndef CORE_RUNNER_CONTEXT_H
#define CORE_RUNNER_CONTEXT_H

#include <entt/fwd.hpp>
#include <cmath>

struct RunnerContext {
	double_t delta;
    double_t running;
	entt::registry& registry;
	entt::dispatcher& dispatcher;

    RunnerContext(entt::registry& registry, entt::dispatcher& dispatcher) : registry(registry), dispatcher(dispatcher) { }
};

#endif // CORE_RUNNER_CONTEXT_H
