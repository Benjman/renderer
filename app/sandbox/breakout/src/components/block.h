#ifndef BREAKOUT_BRICK_H
#define BREAKOUT_BRICK_H

struct Block final {
	int hit_count;

	Block(const int hit_count) noexcept;
	Block(Block&&) noexcept;
	~Block() noexcept = default;
	Block &operator=(Block&&) noexcept;

};

#endif // BREAKOUT_BRICK_H
