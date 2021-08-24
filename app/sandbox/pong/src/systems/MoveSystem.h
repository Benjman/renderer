#ifndef PONG_MOVESYSTEM_H
#define PONG_MOVESYSTEM_H

#include <entt/fwd.hpp>
#include "../components/Player.h"
#include "../events/KeyDown.h"
#include "../events/KeyUp.h"

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
