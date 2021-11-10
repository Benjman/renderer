#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

#include <core/fwd.h>

#include <cmath> // double_t
#include <entt/fwd.hpp>

class Controller {
    public:
        virtual void init(const RunnerContext& context) = 0;
        virtual void update(const RunnerContext& context) = 0;
        virtual void input(const RunnerContext& context) = 0;
};

#endif // CORE_CONTROLLER_H
