#ifndef CORE_PATTERNS_STRATEGY_H
#define CORE_PATTERNS_STRATEGY_H

#include <cmath>
#include <functional>

class Strategy {
    public:
        Strategy(std::function<void()> strat) : strat(strat) {}

        void execute() {
            return strat();
        }

    private:
        std::function<void()> strat;

};

class EmptyStrategy : public Strategy {
    public:
        EmptyStrategy() : Strategy([](){}) {}
};

#endif // CORE_PATTERNS_STRATEGY_H
