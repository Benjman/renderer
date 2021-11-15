#ifndef CORE_MEMORY_MEMORY_SPACE
#define CORE_MEMORY_MEMORY_SPACE

#include <cstddef>
#include <cstdlib>
#include <vector>

inline constexpr size_t KILOBYTE = 1024;
inline constexpr size_t MEGABYTE = KILOBYTE * 1024;

inline size_t KILOBYTES(size_t n) {
    return KILOBYTE * n;
}

inline size_t MEGABYTES(size_t n) {
    return MEGABYTE * n;
}

template<typename T>
class MemoryAllocator {
    public:
        T* ptr = nullptr;

        const size_t max_size;
        size_t cursor = 0;

        MemoryAllocator<T>* parent = nullptr;
        std::vector<MemoryAllocator*> children;

        MemoryAllocator(MemoryAllocator<T>* parent, size_t max_size) : parent(parent), max_size(max_size) {
            if (parent) {
                ptr = parent->request(this);
            } else {
                ptr = (T*) malloc(max_size);
            }
        }

        ~MemoryAllocator() {
            release();
        }

        T* request(MemoryAllocator* space) {
            if (cursor + space->max_size > max_size) {
                // TODO throw overflow exception
            }

            children.emplace_back(space);
            cursor += space->max_size;

            return &ptr[cursor - space->max_size];
        }

        void release() {
            if (parent) {
                parent->release_child(this);
            } else {
                delete[] ptr;
                ptr = nullptr;
            }
        }

        void release_child(MemoryAllocator<T>* c) {
            MemoryAllocator<T>* child = nullptr;
            for (typename std::vector<MemoryAllocator<T>*>::iterator it = children.begin() ; it != children.end(); ++it) {
                if (*it == c) {
                    child = *it;
                    children.erase(it);
                    break;
                }
            }

            if (child == nullptr) {
                // TODO warn that space not found in children
                return;
            }

            // if this is the tail, reclaim the space
            if (child->ptr == &ptr[cursor - child->max_size]) {
                cursor -= child->max_size;
            }

            child->ptr=nullptr;
            child->parent = nullptr;

            // TODO tightly pack the buffer?
        }

};

#endif // CORE_MEMORY_MEMORY_SPACE
