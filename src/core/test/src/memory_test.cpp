#include <cmath>
#include <gtest/gtest.h>

#include <core/memory/memory_allocator.h>

using T = float_t;
inline constexpr size_t MAX_SIZE = 32;

TEST(MemoryTest, initial_state) {
    MemoryAllocator<T> zone(nullptr, MAX_SIZE);
    ASSERT_TRUE(zone.ptr) << "Pointer should be allocated";
    ASSERT_EQ(MAX_SIZE, zone.max_size);
    ASSERT_EQ(0, zone.cursor);
    ASSERT_EQ(nullptr, zone.parent);
    ASSERT_EQ(0, zone.children.size());
}

TEST(MemoryTest, with_parent) {
    size_t size = 8;
    MemoryAllocator<T> parent(nullptr, MAX_SIZE);
    MemoryAllocator<T> child(&parent, size);
    ASSERT_EQ(parent.ptr, child.ptr) << "Paren't didn't allocate child pointer";
    ASSERT_EQ(size, parent.cursor);
}

TEST(MemoryTest, with_parent_many_children) {
    size_t size = 8;
    MemoryAllocator<T> parent(nullptr, MAX_SIZE);
    MemoryAllocator<T> child1(&parent, size);
    MemoryAllocator<T> child2(&parent, size);
    ASSERT_EQ(&parent.ptr[0], child1.ptr);
    ASSERT_EQ(&parent.ptr[size], child2.ptr);
    ASSERT_EQ(size * 2, parent.cursor);
}

TEST(MemoryTest, reclaim_tail) {
    MemoryAllocator<T> parent(nullptr, 24);
    MemoryAllocator<T> child1(&parent, 8);
    ASSERT_EQ(8, parent.cursor);
    MemoryAllocator<T> child2(&parent, 8);
    ASSERT_EQ(16, parent.cursor);
    MemoryAllocator<T> child3(&parent, 8);
    ASSERT_EQ(24, parent.cursor);

    // release and reclaim tail
    child3.release();
    ASSERT_EQ(16, parent.cursor) << "Cursor position should have reduced from tail buffer size";

    child1.release();
    ASSERT_EQ(16, parent.cursor) << "Cursor shouldn't have changed releasing buffer that wasn't the tail";
}

TEST(MemoryTest, ptr_null_after_release) {
    MemoryAllocator<T> zone(nullptr, MAX_SIZE);
    zone.release();
    ASSERT_FALSE(zone.ptr);
}

TEST(MemoryTest, ptr_null_after_release_with_parent) {
    size_t size = 8;
    MemoryAllocator<T> parent(nullptr, MAX_SIZE);
    MemoryAllocator<T> child(&parent, size);
    child.release();
    ASSERT_FALSE(child.ptr);
}

TEST(MemoryTest, parent_null_after_release) {
    size_t size = 8;
    MemoryAllocator<T> parent(nullptr, MAX_SIZE);
    MemoryAllocator<T> child(&parent, size);
    child.release();
    ASSERT_FALSE(child.parent);
}

