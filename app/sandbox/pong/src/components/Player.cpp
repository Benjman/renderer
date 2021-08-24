#include "Player.h"

Player::Player() noexcept : movement(MoveDirection::STOPPED) {
}

Player::Player(Player&& p) noexcept {
	this->movement = p.movement;
	p.movement = MoveDirection::STOPPED;
}

Player& Player::operator=(Player &&p) noexcept {
	if (this != &p) {
		this->movement = p.movement;
		p.movement = MoveDirection::STOPPED;
	}
	return *this;
}
