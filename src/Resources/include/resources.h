#ifndef RESOURCES_RESOURCES_H
#define RESOURCES_RESOURCES_H

#include <cstddef>

void loadResource(const char *relativePath, void *buffer, size_t *outSize);

#endif // RESOURCES_RESOURCES_H
