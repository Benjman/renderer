#include "core/runner_context.h"
#include <gtest/gtest.h>

#define protected public
#define private public
#include <core/controller.h>

struct TestController : public Controller {
    bool cleaned_up = false,
         initted = false,
         pre_updated = false,
         updated = false,
         post_updated = false;

    explicit TestController(Controller* parent = nullptr, bool active = false) : Controller(parent) {
        if (active) status = Active;
    }

    void do_init(const RunnerContext &context) override {
        initted = true;
    }

    void do_post_update(const RunnerContext &context) override {
        post_updated = true;
    }

    void do_pre_update(const RunnerContext &context) override {
        pre_updated = true;
    }

    void do_update(const RunnerContext &context) override {
        updated = true;
    }

    void cleanup() override {
        cleaned_up = true;
    }
};

RunnerContext context;

TEST(Controller, constructor_null_parent_default) {
    TestController controller;
    ASSERT_EQ(nullptr, controller.parent);
}

TEST(Controller, constructor_sets_parent) {
    Controller parent;
    TestController child(&parent);
    ASSERT_EQ(&parent, child.parent);
}

TEST(Controller, dormant_by_default) {
    TestController controller;
    ASSERT_EQ(Controller::Status::Dormant, controller.status);
}

TEST(Controller, is_active) {
    TestController controller(nullptr, true);
    ASSERT_EQ(Controller::Status::Active, controller.status);
}

TEST(Controller, constructor_queues_child) {
    Controller parent;
    TestController child(&parent);
    ASSERT_EQ(1, parent.children_to_add.size());
    ASSERT_EQ(&child, parent.children_to_add.at(0));
}

TEST(Controller, initiates_self) {
    TestController controller;
    controller.init(context);
    ASSERT_TRUE(controller.initted);
}

TEST(Controller, child_initted) {
    Controller parent(nullptr, true);
    TestController child(&parent, true);
    RunnerContext context;

    ASSERT_FALSE(child.initted);
    parent.pre_update(context);
    ASSERT_TRUE(child.initted);
}

TEST(Controller, queued_children_added) {
    Controller parent(nullptr, true);
    TestController child(&parent, true);
    RunnerContext context;

    ASSERT_EQ(0, parent.children.size());
    ASSERT_EQ(1, parent.children_to_add.size());
    parent.pre_update(context);
    ASSERT_EQ(1, parent.children.size());
    ASSERT_EQ(0, parent.children_to_add.size());
    ASSERT_EQ(&child, parent.children.at(0));
}

TEST(Controller, parent_pre_updates) {
    TestController parent;
    TestController child(&parent);
    RunnerContext context;

    parent.pre_update(context);
    ASSERT_FALSE(parent.pre_updated) << "Dormant controllers should not pre_update.";
    parent.status = Controller::Active;
    parent.pre_update(context);
    ASSERT_TRUE(parent.pre_updated) << "Active controllers should pre_update.";
}

TEST(Controller, child_pre_updated) {
    Controller parent(nullptr, true);
    TestController child(&parent);
    RunnerContext context;

    ASSERT_FALSE(child.pre_updated);
    parent.pre_update(context);
    ASSERT_FALSE(child.pre_updated) << "Dormant controllers should not pre_update.";
    child.status = Controller::Active;
    parent.pre_update(context);
    ASSERT_TRUE(child.pre_updated) << "Active controllers should pre_update.";
}

TEST(Controller, children_added_dormant) {
    Controller parent;
    TestController child(&parent);
    parent.pre_update(context);

    ASSERT_EQ(Controller::Status::Dormant, child.status);
    parent.update(context);
    ASSERT_FALSE(child.updated) << "Dormant controllers should not update.";
}

TEST(Controller, active_children_update) {
    Controller parent(nullptr, true);
    TestController child(&parent);
    parent.pre_update(context);

    parent.update(context);
    ASSERT_FALSE(child.updated) << "Dormant controllers should not update.";
    child.status = Controller::Active;
    parent.update(context);
    ASSERT_TRUE(child.updated) << "Active controllers should update.";
}

TEST(Controller, updates) {
    TestController controller(nullptr, true);
    ASSERT_FALSE(controller.updated);
    controller.update(context);
    ASSERT_TRUE(controller.updated);
}

TEST(Controller, post_updates) {
    TestController controller(nullptr, true);
    ASSERT_FALSE(controller.post_updated);
    controller.post_update(context);
    ASSERT_TRUE(controller.post_updated);
}

TEST(Controller, add_child) {
    Controller parent;
    Controller child;

    ASSERT_EQ(0, parent.children_to_add.size());
    parent.add_child(&child);
    ASSERT_EQ(1, parent.children_to_add.size());
    ASSERT_EQ(&child, parent.children_to_add.at(0));
}

TEST(Controller, remove_child) {
    Controller parent;
    Controller child;

    ASSERT_EQ(0, parent.children_to_remove.size());
    parent.remove_child(&child);
    ASSERT_EQ(1, parent.children_to_remove.size());
    ASSERT_EQ(&child, parent.children_to_remove.at(0));
}

TEST(Controller, children_removed_after_post_update) {
    Controller parent(nullptr, true);
    Controller child(&parent);
    parent.pre_update(context);

    ASSERT_EQ(1, parent.children.size());
    ASSERT_EQ(&child, parent.children.at(0));

    parent.remove_child(&child);
    ASSERT_EQ(1, parent.children_to_remove.size());
    ASSERT_EQ(1, parent.children.size()) << "Child should not have been removed until post_update is called.";
    ASSERT_EQ(&child, parent.children.at(0)) << "Child should not have been removed until post_update is called.";

    parent.post_update(context);
    ASSERT_EQ(0, parent.children.size()) << "Child was expected to be removed from collection.";
}

