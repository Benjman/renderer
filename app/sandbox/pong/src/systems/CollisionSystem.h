#ifndef PONG_COLLISIONSYSTEM_H
#define PONG_COLLISIONSYSTEM_H

#include <entt/fwd.hpp>

struct CollisionHolder {
	entt::entity player;
	entt::entity ai;
	entt::entity ball;
	entt::registry *registry;
};

class CollisionSystem final {
	public:
		CollisionSystem() = default;
		~CollisionSystem() = default;

		void update(const double time, CollisionHolder &holder);
};

#endif // PONG_COLLISIONSYSTEM_H
