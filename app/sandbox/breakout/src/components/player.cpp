#include "player.h"

Player::Player(int velocity) noexcept : velocity(velocity) {
}

Player::Player(Player&& p) noexcept {
}

Player& Player::operator=(Player &&p) noexcept {
    return *this;
}
