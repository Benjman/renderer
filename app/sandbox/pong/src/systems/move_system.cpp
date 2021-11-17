#include <iostream>
#include <entt/entt.hpp>

#include <core/components/position2d.h>
#include <core/input.h>
#include <core/events.h>

#include "../components/ball.h"
#include "../random.hpp"
#include "move_system.h"

[[nodiscard]] const double randomize_velocity_dir(const double vel) {
    return random(0, 1) ? -vel : vel;
}

using namespace input;
void MoveSystem::on_key_down(const KeyDown& key_down) noexcept {
    switch (key_down.keycode) {
        case KEY_W:
            player_movement = Player::MoveDirection::NORTH;
            break;

        case KEY_S:
            player_movement = Player::MoveDirection::SOUTH;
            break;
    }
}

void MoveSystem::on_key_up(const KeyUp& key_up) noexcept {
    if (key_up.keycode == KEY_W || key_up.keycode == KEY_S) {
        player_movement = Player::MoveDirection::STOPPED;
    }
}

inline size_t player_score = 0;
inline size_t ai_score = 0;

void MoveSystem::update(const double time, entt::registry& registry) {
    // We only need to update the player position, since the ai wil be managed by the ai system.
    auto player_view = registry.view<Player, Position2D>();
    player_view.each([&](Player& plr, Position2D& pos) {
            plr.movement = player_movement;

            if (plr.movement == Player::MoveDirection::NORTH) {
            pos.y += PADDLE_SPEED * time;
            } else if (plr.movement == Player::MoveDirection::SOUTH) {
            pos.y -= PADDLE_SPEED * time;
            }

            // Lock to screen.
            if (pos.y < 0.0) {
            pos.y = 0.0;
            } else if (pos.y > (480.0 - 96.0)) { // screen width - sprite width
            pos.y = (480.0 - 96.0);
            }
            });

    // Next, we want to update the balls position and move it according to the directions its currently travelling.
    auto ball_view = registry.view<Ball, Position2D>();
    ball_view.each([&](Ball& ball, Position2D& pos) {
            // Allow the ball to move based on a fixed-timestep loop.
            pos.x += ball.vel_x * time;
            pos.y += ball.vel_y * time;

            // Ensure ball can be reset.
            if (pos.x < 0.0) {
            // Ball passed the player paddle, reset it.
            pos.x = (640.0 / 2.0) - 16.0;
            pos.y = (480.0 / 2.0) - 16.0;

            ball.vel_x = randomize_velocity_dir(ball.initial_x_vel());
            ball.vel_y = randomize_velocity_dir(ball.initial_y_vel());

            std::cout << "AI Scores!\tPlayer: " << player_score << "\tAI: " << ++ai_score << std::endl;
            } else if (pos.x > (640.0 - 16.0)) { // screen width - sprite width
            // Ball passed the ai paddle, reset it.
            pos.x = (640.0 / 2.0) - 16.0;
            pos.y = (480.0 / 2.0) - 16.0;

            ball.vel_x = randomize_velocity_dir(ball.initial_x_vel());
            ball.vel_y = randomize_velocity_dir(ball.initial_y_vel());

            std::cout << "Player Scores!\tPlayer: " << ++player_score << "\tAI: " << ai_score << std::endl;
            }

            // Lock to screen.
            if (pos.y < 0.0) {
                // Reverse ball, "bouncing" it.
                pos.y = 0.0;
                ball.vel_y *= -1;
            } else if (pos.y > (480.0 - 16.0)) { // screen height - sprite height
                // Reverse ball, "bouncing" it.
                pos.y = (480.0 - 16.0);
                ball.vel_y *= -1;
            }
    });
}
