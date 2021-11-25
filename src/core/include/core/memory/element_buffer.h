#ifndef CORE_MEMORY_ELEMENT_BUFFER_H
#define CORE_MEMORY_ELEMENT_BUFFER_H

#include "memory_allocator.h"

#include <cmath>
#include <cstdint>

struct ElementBuffer {
    MemoryAllocator<float_t> vert_buffer;
    MemoryAllocator<uint32_t> idx_buffer;

    ElementBuffer(size_t vert_buffer_size, size_t idx_buffer_size) : vert_buffer(nullptr, vert_buffer_size), idx_buffer(nullptr, idx_buffer_size) {}

};

#endif // CORE_MEMORY_ELEMENT_BUFFER_H
