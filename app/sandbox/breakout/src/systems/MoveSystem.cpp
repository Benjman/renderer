#include <GLFW/glfw3.h>
#include <entt/entt.hpp>
#include <iostream>

#include "../components/Ball.h"
#include "../components/Player.h"
#include "../components/Position.h"
#include "../components/Sprite.h"

#include "./MoveSystem.h"

void MoveSystem::on_key_down(const KeyDown& key_down) noexcept {
	switch (key_down.keycode) {
		case GLFW_KEY_LEFT:
			player_movement = Player::MoveDirection::WEST;
			break;

		case GLFW_KEY_RIGHT:
			player_movement = Player::MoveDirection::EAST;
			break;
	}
}

void MoveSystem::on_key_up(const KeyUp& key_up) noexcept {
	player_movement = Player::MoveDirection::STOPPED;
}

const int PADDLE_SPEED = 20;

void MoveSystem::update(const double time, entt::registry &registry) {
	auto ball_view = registry.view<Ball, Position, Sprite>();
	ball_view.each([&](Ball& ball, Position& pos, Sprite& sprite) {
		// check for boarder collision
		if (pos.x + sprite.width + sprite.radius > width
			|| pos.x < 0) {
			ball.vel_x *= -1;
		}

		if (pos.y + sprite.height + sprite.radius > height
				|| pos.y < 0) {
			ball.vel_y *= -1;
		}

		pos.x += ball.vel_x * time;
		pos.y += ball.vel_y * time;
	});

	auto player_view = registry.view<Player, Position, Sprite>();
	player_view.each([&](Player &player, Position& pos, Sprite& sprite) {
		switch (player_movement) {
			case Player::MoveDirection::WEST:
				pos.x -= player.velocity * time;
			break;
			case Player::MoveDirection::EAST:
				pos.x += player.velocity * time;
			break;
			case Player::MoveDirection::STOPPED:
			break;
		};

		// constrain paddle to within screen space
		if (pos.x < 0) pos.x = 0;
		if (pos.x + sprite.width > width) pos.x = width - sprite.width;
		if (pos.y < 0) pos.y = 0;
		if (pos.y > height - 100) pos.y = height;
	});
}

void MoveSystem::setSize(int width, int height) {
	this->width = width;
	this->height = height;
}
