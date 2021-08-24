#ifndef PONG_AISYSTEM_H
#define PONG_AISYSTEM_H

#include <entt/fwd.hpp>

class AISystem final {
	public:
		AISystem() = default;
		~AISystem() = default;

		void update(const double time, entt::registry &registry);
};

#endif // PONG_AISYSTEM_H
