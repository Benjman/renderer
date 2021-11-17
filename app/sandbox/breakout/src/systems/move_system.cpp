#include <GLFW/glfw3.h>
#include <entt/entt.hpp>
#include <iostream>

#include <core/components/position2d.h>

#include "../components/ball.h"
#include "../components/player.h"
#include "../components/sprite.h"

#include "./move_system.h"

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

void MoveSystem::update(const double time, entt::registry &registry, int width, int height) {
    auto ball_view = registry.view<Ball, Position2D, Sprite>();
    ball_view.each([&](Ball& ball, Position2D& pos, Sprite& sprite) {
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

    auto player_view = registry.view<Player, Position2D, Sprite>();
    player_view.each([&](Player &player, Position2D& pos, Sprite& sprite) {
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
