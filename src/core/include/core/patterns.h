#ifndef CORE_PATTERNS_H
#define CORE_PATTERNS_H

#include <cmath>
#include <functional>

class Strategy {
    private:
        std::function<void()> strat;

    public:
        Strategy(std::function<void()> strat) : strat(strat) {}

        void execute() {
            return strat();
        }
};

class EmptyStrategy : public Strategy {
    public:
        EmptyStrategy() : Strategy([](){}) {}
};

#endif // CORE_PATTERNS_H
