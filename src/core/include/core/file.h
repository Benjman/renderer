#ifndef CORE_FILE_H
#define CORE_FILE_H

#include "config.h"

struct File {
    char* buffer;
    int size;

    File(char* buffer, int size) : buffer(buffer), size(size) {}

    ~File() {
        delete[] buffer;
    }
};

File load_file(const char* path);

#endif // CORE_FILE_H
