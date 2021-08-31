#include "Block.h"

Block::Block(const int hit_count) noexcept : hit_count(hit_count) {
}

Block::Block(Block&& b) noexcept {
	this->hit_count = b.hit_count;
}

Block &Block::operator=(Block&& b) noexcept {
	if (this != &b) {
		this->hit_count = b.hit_count;
	}

	return *this;
}


