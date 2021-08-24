#include <entt/entt.hpp>

#include "../components/Ball.h"
#include "../components/Position.h"
#include "../components/Sprite.h"

#include "CollisionSystem.h"

#include <glm/vec4.hpp>

void CollisionSystem::update(const double time, CollisionHolder& holder)
{
	// We use a collision holder instead of something like a Dynamic Tree /BVH / Quad Tree which is out of scope for this.
	auto& ball           = holder.registry->get<Ball>(holder.ball);
	const auto& ball_pos = holder.registry->get<Position>(holder.ball);
	const auto& ball_spr = holder.registry->get<Sprite>(holder.ball);

	const auto& ai_pos = holder.registry->get<Position>(holder.ai);
	const auto& ai_spr = holder.registry->get<Sprite>(holder.ai);

	const auto& player_pos = holder.registry->get<Position>(holder.player);
	const auto& player_spr = holder.registry->get<Sprite>(holder.player);

	// If the ball is currently immune we can count down the ticks and return.
	if (ball.bounce_immune_ticks > 0)
	{
		ball.bounce_immune_ticks--;
	}
	else
	{
		// Ball bounding box.
		const glm::vec4 ball_bb(
				ball_pos.m_x - ball_spr.radius,
				ball_pos.m_y - ball_spr.radius,
				ball_spr.radius * 2, ball_spr.radius * 2);

		// Player bounding box.
		const glm::vec4 player_bb(
				player_pos.m_x,
				player_pos.m_y,
				player_spr.width,
				player_spr.height);

		// AI bounding box
		const glm::vec4 ai_bb(
				ai_pos.m_x,
				ai_pos.m_y,
				ai_spr.width,
				ai_spr.height);

		// Calculate collisions and act on them.
		if (player_bb.x < ball_bb.x + ball_bb.z
				&& player_bb.x + player_bb.z > ball_bb.x
				&& player_bb.y < ball_bb.y + ball_bb.w
				&& player_bb.y + player_bb.w > ball_bb.y) {

			// Reverse ball, "bouncing" it.
			ball.vel_x *= -1;

			// Set bounce immunity for a few ticks to prevent ball from getting stuck inside the paddle.
			ball.bounce_immune_ticks = 5;
		}

		if (ai_bb.x < ball_bb.x + ball_bb.z
				&& ai_bb.x + ai_bb.z > ball_bb.x
				&& ai_bb.y < ball_bb.y + ball_bb.w
				&& ai_bb.y + ai_bb.w > ball_bb.y) {
			// Reverse ball, "bouncing" it.
			ball.vel_x *= -1;

			// Set bounce immunity for a few ticks to prevent ball from getting stuck inside the paddle.
			ball.bounce_immune_ticks = 5;
		}
	}
}

