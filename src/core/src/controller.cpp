#include <core/controller.h>

Controller::Controller(Controller* parent, bool active) : m_parent(parent), m_status(active ? Active : Dormant) {
    if (active)
        m_status = Active;

    if (parent)
        parent->add_child(this);
}

void Controller::init(const RunnerContext& context) {
    add_queued_children(context);
    remove_queued_children(context);

    do_init(context);

    for (auto* child : m_children) {
        child->init(context);
    }
}

void Controller::pre_update(const RunnerContext& context) {
    if (m_status != Active)
        return;

    add_queued_children(context);
    do_pre_update(context);

    for (auto* child : m_children) {
        if (child->m_status == Active)
            child->pre_update(context);
    }
}

void Controller::update(const RunnerContext& context) {
    if (m_status != Active)
        return;

    do_update(context);

    for (auto* child : m_children) {
        if (child->m_status == Active)
            child->update(context);
    }
}

void Controller::post_update(const RunnerContext& context) {
    if (m_status != Active)
        return;

    remove_queued_children(context);

    for (auto* child : m_children) {
        if (child->m_status == Active)
            child->post_update(context);
    }

    do_post_update(context);
}

void Controller::add_child(Controller* child) {
    m_children_to_add.emplace_back(child);
}

void Controller::remove_child(Controller* child) {
    m_children_to_remove.emplace_back(child);
}

void Controller::remove_queued_children(const RunnerContext& context) {
    if (!m_children_to_remove.empty()) {
        std::vector<Controller*>::iterator it;
        for (auto* child : m_children_to_remove) {
            child->cleanup();
            child_removed(child);
            child->m_parent = nullptr;

            it = std::find(m_children.begin(), m_children.end(), child);
            if (it == m_children.end())
                // TODO warning log
                continue;

            m_children.erase(it);
        }
        m_children_to_remove.clear();
    }
}

void Controller::add_queued_children(const RunnerContext& context) {
    if (!m_children_to_add.empty()) {
        for (auto *child: m_children_to_add) {
            child->m_parent = this;
            m_children.emplace_back(child);
            child->init(context);
            child_added(child);
        }
        m_children_to_add.clear();
    }
}
