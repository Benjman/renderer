#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

class Player final {
	public:
		enum class MoveDirection : short {
			STOPPED,
			NORTH,
			SOUTH
		};

		Player() noexcept;
		Player(Player&&) noexcept;
		Player& operator=(Player&&) noexcept;

	public:
		MoveDirection movement;
};

#endif // PONG_PLAYER_H
