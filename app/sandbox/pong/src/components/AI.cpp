#include "AI.h"

AI::AI(const double x, const double y) noexcept : m_x{x}, m_y{y} {
}

AI::AI(AI&& ai) noexcept {
	m_x = ai.m_x;
	m_y = ai.m_y;
}

AI& AI::operator=(AI &&ai) noexcept {
	if (this != &ai) {
		m_x = ai.m_x;
		m_y = ai.m_y;
	}

	return *this;
}
