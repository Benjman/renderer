#ifndef BREAKOUT_PLAYER_H
#define BREAKOUT_PLAYER_H

struct Player final {
    enum class MoveDirection : short {
        STOPPED,
        EAST,
        WEST
    };

    int velocity;

    Player(int velocity) noexcept;
    Player(Player&&) noexcept;
    Player& operator=(Player&&) noexcept;

};

#endif // BREAKOUT_PLAYER_H
