#include <iostream>
#include <entt/entt.hpp>
#include <glm/vec4.hpp>

#include <core/components/position2d.h>

#include "../components/ball.h"
#include "../components/block.h"
#include "../components/sprite.h"

#include "./collision_system.h"

void CollisionSystem::update(const double time, CollisionHolder& holder) {
	// We use a collision holder instead of something like a Dynamic Tree /BVH / Quad Tree which is out of scope for this.
	auto& ball           = holder.registry->get<Ball>(holder.ball);
	const auto& ball_pos = holder.registry->get<Position2D>(holder.ball);
	const auto& ball_spr = holder.registry->get<Sprite>(holder.ball);

	const auto& player_pos = holder.registry->get<Position2D>(holder.player);
	const auto& player_spr = holder.registry->get<Sprite>(holder.player);

	// If the ball is currently immune we can count down the ticks and return.
	if (ball.bounce_immune_ticks > 0) {
		ball.bounce_immune_ticks--;
		return;
	}

	// Ball bounding box.
	const glm::vec4 ball_bb(
			ball_pos.x, ball_pos.y,
			ball_spr.radius, ball_spr.radius);

	// Player bounding box.
	const glm::vec4 player_bb(
			player_pos.x, player_pos.y,
			player_spr.width, player_spr.height);

	// Calculate collisions and act on them.
	if (player_bb.x < ball_bb.x + ball_bb.z
			&& player_bb.x + player_bb.z > ball_bb.x
			&& player_bb.y < ball_bb.y + ball_bb.w
			&& player_bb.y + player_bb.w > ball_bb.y) {

		// determine where on the paddle the ball hit
		double mag = ((ball_pos.x - player_pos.x) / player_spr.width) * 2 - 1;

		// Reverse ball, "bouncing" it.
		ball.vel_y *= -1.;
		ball.vel_x = mag * std::abs(ball.initial_x_vel);

		// Set bounce immunity for a few ticks to prevent ball from getting stuck inside the paddle.
		ball.bounce_immune_ticks = 5;
		return;
	}

	auto block_view = holder.registry->view<Position2D, Sprite>();
	block_view.each([&](const auto entity, const Position2D& pos, const Sprite& spr) {
		glm::vec4 block_bb(
				pos.x, pos.y,
				spr.width, spr.height);
		if (ball_bb.x < block_bb.x + block_bb.z
				&& ball_bb.x + ball_bb.z > block_bb.x
				&& ball_bb.y < block_bb.y + block_bb.w
				&& ball_bb.y + ball_bb.w > block_bb.y) {
			ball.vel_y *= -1.;
			holder.registry->destroy(entity);
		}
	});
}

