#include <core/controller.h>

Controller::Controller(Controller* parent, bool active) : parent(parent), status(active ? Active : Dormant) {
    if (active)
        status = Active;

    if (parent)
        parent->add_child(this);
}

void Controller::init(const RunnerContext& context) {
    do_init(context);

    for (auto* child : children) {
        child->init(context);
    }
}

void Controller::pre_update(const RunnerContext& context) {
    if (status != Active)
        return;

    add_queued_children(context);
    do_pre_update(context);

    for (auto* child : children) {
        if (child->status == Active)
            child->pre_update(context);
    }
}

void Controller::update(const RunnerContext& context) {
    if (status != Active)
        return;

    do_update(context);

    for (auto* child : children) {
        if (child->status == Active)
            child->update(context);
    }
}

void Controller::post_update(const RunnerContext& context) {
    if (status != Active)
        return;

    remove_queued_children(context);

    for (auto* child : children) {
        if (child->status == Active)
            child->post_update(context);
    }

    do_post_update(context);
}

void Controller::add_child(Controller* child) {
    children_to_add.emplace_back(child);
}

void Controller::remove_child(Controller* child) {
    children_to_remove.emplace_back(child);
}

void Controller::remove_queued_children(const RunnerContext& context) {
    if (!children_to_remove.empty()) {
        std::vector<Controller*>::iterator it;
        for (auto* child : children_to_remove) {
            child->cleanup();
            child->parent = nullptr;

            it = std::find(children.begin(), children.end(), child);
            if (it == children.end())
                // TODO warning log
                continue;

            children.erase(it);
        }
        children_to_remove.clear();
    }
}

void Controller::add_queued_children(const RunnerContext& context) {
    // TODO check performance of checking if children_to_add is empty, versus just going into an iterator
    // whichever wins, also implement it in post_update
    for (auto* child : children_to_add) {
        child->parent = this;
        children.emplace_back(child);
        child->init(context);
    }
    children_to_add.clear();
}
