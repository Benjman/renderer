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

        void add_child(Controller* child);
        void remove_child(Controller* child);

        [[nodiscard]] const std::vector<Controller*> children() const noexcept {
            return m_children;
        }

        void status(Status s) {
            m_status = s;
        }

    protected:
        virtual void do_init(const RunnerContext& context) {}

        virtual void do_pre_update(const RunnerContext& context) {}
        virtual void do_update(const RunnerContext& context) {}
        virtual void do_post_update(const RunnerContext& context) {}

        virtual void render(const RunnerContext& context) {}

        virtual void cleanup() {}

        virtual void child_added(Controller* child) {}
        virtual void child_removed(Controller* child) {}

    private:
        Controller* m_parent = nullptr;

        std::vector<Controller*> m_children;
        std::vector<Controller*> m_children_to_add;
        std::vector<Controller*> m_children_to_remove;

        Status m_status = Status::Dormant;

        void add_queued_children(const RunnerContext& context);
        void remove_queued_children(const RunnerContext& context);

};

#endif // CORE_CONTROLLER_H
