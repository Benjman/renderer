#ifndef PONG_MOVESYSTEM_H
#define PONG_MOVESYSTEM_H

#include <entt/fwd.hpp>

#include <core/events.h>
#include "../components/player.h"

class MoveSystem final {
    public:
        static constexpr size_t PADDLE_SPEED = 150;
        static constexpr size_t BALL_SPEED = 180;

        MoveSystem() = default;
        ~MoveSystem() = default;

        void on_key_down(const KeyDown &key_down) noexcept;
        void on_key_up(const KeyUp &key_up) noexcept;

        void update(const double time, entt::registry &registry);

        Player::MoveDirection player_movement;
};

#endif // PONG_MOVESYSTEM_H
