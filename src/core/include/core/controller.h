#ifndef CORE_CONTROLLER_H
#define CORE_CONTROLLER_H

#include <core/fwd.h>

#include <vector>
#include <entt/fwd.hpp>

class Controller {
    public:
        enum Status {
            Dormant = 0,
            Active = 1,
        };

        Controller(Controller* parent = nullptr, bool active = false);

        void init(const RunnerContext& context);

        void pre_update(const RunnerContext& context);
        void update(const RunnerContext& context);
        void post_update(const RunnerContext& context);

    protected:
        void add_child(Controller* child);

        void remove_child(Controller* child);

        virtual void do_init(const RunnerContext& context) {}

        virtual void do_pre_update(const RunnerContext& context) {}
        virtual void do_update(const RunnerContext& context) {}
        virtual void do_post_update(const RunnerContext& context) {}

        virtual void cleanup() {}

    private:
        Controller* parent = nullptr;

        std::vector<Controller*> children;
        std::vector<Controller*> children_to_add;
        std::vector<Controller*> children_to_remove;

        Status status = Status::Dormant;

        void add_queued_children(const RunnerContext& context);
        void remove_queued_children(const RunnerContext& context);

};

#endif // CORE_CONTROLLER_H
