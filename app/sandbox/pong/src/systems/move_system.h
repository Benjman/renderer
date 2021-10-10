#ifndef PONG_MOVESYSTEM_H
#define PONG_MOVESYSTEM_H

#include <entt/fwd.hpp>

#include <core/events.h>
#include "../components/player.h"

#define PADDLE_SPEED 150
#define BALL_SPEED 180

class MoveSystem final {
	public:
		MoveSystem() = default;
		~MoveSystem() = default;

		void on_key_down(const KeyDown &key_down) noexcept;
		void on_key_up(const KeyUp &key_up) noexcept;

		void update(const double time, entt::registry &registry);

		Player::MoveDirection player_movement;
};

#endif // PONG_MOVESYSTEM_H
