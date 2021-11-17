#ifndef BREAKOUT_COLLISIONSYSTEM_H
#define BREAKOUT_COLLISIONSYSTEM_H

#include <entt/fwd.hpp>
#include <vector>

struct CollisionHolder {
    entt::entity player;
    entt::entity ball;
    std::vector<entt::entity> blocks;
    entt::registry *registry;
};

class CollisionSystem final {
    public:
        CollisionSystem() = default;

        void update(double time, CollisionHolder& holder);

};


#endif // BREAKOUT_COLLISIONSYSTEM_H
