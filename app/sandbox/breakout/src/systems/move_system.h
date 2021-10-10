#ifndef BREAKOUT_MOVESYSTEM_H
#define BREAKOUT_MOVESYSTEM_H

#include <entt/fwd.hpp>

#include <core/events.h>
#include "../components/player.h"

class MoveSystem final {
		Player::MoveDirection player_movement;

	public:
		MoveSystem() = default;

		void on_key_down(const KeyDown &key_down) noexcept;
		void on_key_up(const KeyUp &key_up) noexcept;

		void update(const double time, entt::registry &registry, int width, int height);

};

#endif // BREAKOUT_MOVESYSTEM_H
