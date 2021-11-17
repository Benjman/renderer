#include <entt/entt.hpp>

#include "../components/ai.h"
#include "../components/ball.h"
#include <core/components/position2d.h>

#include "ai_system.h"

void AISystem::update(const double time, entt::registry &registry) {
    // Center the ai to the ball so it is always in the right position.
    // we want to increase or decrese ai position based on if the ball is above or below it.
    // so something like:
    /*
       if ball position is above ai:
       move ai smoothly up towards ball so middle of ai paddle is at ball pos.
       */

    // Takes advantage of the fact that there is only 1 AI and 1 Ball.
    auto ai_view = registry.view<AI, Position2D>();
    auto ball_view = registry.view<Ball, Position2D>();

    ai_view.each([&](auto &ai, auto &ai_pos) {
        ai.x = ai_pos.x;
        ai.y = ai_pos.y;

        ball_view.each([&](auto &ball, auto &ball_pos) {
            if (ball_pos.y > ai_pos.y) {
                ai_pos.y += 5;
            } else if (ball_pos.y < ai_pos.y) {
                ai_pos.y -= 5;
            }
        });
    });
}

