#include <iostream>
#include <entt/entt.hpp>

#include <GLFW/glfw3.h>

#include "../components/Ball.h"
#include "../components/Position.h"
#include "../Random.hpp"

#include "MoveSystem.h"

#define PADDLE_SPEED 30

[[nodiscard]] const double randomize_velocity_dir(const double vel) {
	return random(0, 1) ? -vel : vel;
}

void MoveSystem::on_key_down(const KeyDown& key_down) noexcept {
	switch (key_down.keycode) {
		case GLFW_KEY_W:
			player_movement = Player::MoveDirection::NORTH;
			break;

		case GLFW_KEY_S:
			player_movement = Player::MoveDirection::SOUTH;
			break;
	}
}

void MoveSystem::on_key_up(const KeyUp& key_up) noexcept {
	if (key_up.keycode == GLFW_KEY_W || key_up.keycode == GLFW_KEY_S) {
		player_movement = Player::MoveDirection::STOPPED;
	}
}

inline size_t player_score = 0;
inline size_t ai_score = 0;

void MoveSystem::update(const double time, entt::registry& registry) {
	// We only need to update the player position, since the ai wil be managed by the ai system.
	auto player_view = registry.view<Player, Position>();
	player_view.each([&](Player& plr, Position& pos) {
			plr.movement = player_movement;

			if (plr.movement == Player::MoveDirection::NORTH) {
				pos.m_y += PADDLE_SPEED * time;
			} else if (plr.movement == Player::MoveDirection::SOUTH) {
				pos.m_y -= PADDLE_SPEED * time;
			}

			// Lock to screen.
			if (pos.m_y < 0.0) {
				pos.m_y = 0.0;
			} else if (pos.m_y > (480.0 - 96.0)) { // screen width - sprite width
				pos.m_y = (480.0 - 96.0);
			}
	});

	// Next, we want to update the balls position and move it according to the directions its currently travelling.
	auto ball_view = registry.view<Ball, Position>();
	ball_view.each([&](Ball& ball, Position& pos) {
			// Allow the ball to move based on a fixed-timestep loop.
			pos.m_x += ball.vel_x * time;
			pos.m_y += ball.vel_y * time;

			// Ensure ball can be reset.
			if (pos.m_x < 0.0) {
				// Ball passed the player paddle, reset it.
				pos.m_x = (640.0 / 2.0) - 16.0;
				pos.m_y = (480.0 / 2.0) - 16.0;

				ball.vel_x = randomize_velocity_dir(ball.initial_x_vel());
				ball.vel_y = randomize_velocity_dir(ball.initial_y_vel());

				std::cout << "AI Scores!\tPlayer: " << player_score << "\tAI: " << ++ai_score << std::endl;
			} else if (pos.m_x > (640.0 - 16.0)) { // screen width - sprite width
				// Ball passed the ai paddle, reset it.
				pos.m_x = (640.0 / 2.0) - 16.0;
				pos.m_y = (480.0 / 2.0) - 16.0;

				ball.vel_x = randomize_velocity_dir(ball.initial_x_vel());
				ball.vel_y = randomize_velocity_dir(ball.initial_y_vel());

				std::cout << "Player Scores!\tPlayer: " << ++player_score << "\tAI: " << ai_score << std::endl;
			}

			// Lock to screen.
			if (pos.m_y < 0.0) {
				// Reverse ball, "bouncing" it.
				pos.m_y = 0.0;
				ball.vel_y *= -1;
			} else if (pos.m_y > (480.0 - 16.0)) { // screen height - sprite height
				// Reverse ball, "bouncing" it.
				pos.m_y = (480.0 - 16.0);
				ball.vel_y *= -1;
			}
	});
}
