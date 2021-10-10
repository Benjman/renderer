#ifndef PONG_AI_H
#define PONG_AI_H

class AI final {
	public:
		AI(const double x, const double y) noexcept;
		AI(AI&&) noexcept;
		~AI() noexcept = default;
		AI& operator=(AI&&) noexcept;

	public:
		double x;
		double y;
};

#endif // PONG_AI_H
