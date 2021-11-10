#ifndef CORE_FILE_H
#define CORE_FILE_H

#include "config.h"
#include <cmath>

struct File {
    char* buffer;
    size_t size;

    File(char* buffer, size_t size) : buffer(buffer), size(size) {}
};

File load_file(const char* path);

#endif // CORE_FILE_H
