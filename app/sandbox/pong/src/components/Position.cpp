#include "Position.h"

Position::Position(const double_t x, const double_t y) noexcept 
	: m_x(x), m_y(y) {
}

Position::Position(Position &&p) noexcept {
	this->m_x = p.m_x;
	this->m_y = p.m_y;
}

Position &Position::operator=(Position && p) noexcept {
	if (this != &p) {
		this->m_x = p.m_x;
		this->m_y = p.m_y;
	}
	return *this;
}
