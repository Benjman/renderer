#ifndef CORE_FILE_H
#define CORE_FILE_H

#include <cstdint>
#include <string>

struct File {
	static File LOAD(const char* rel_path);

	std::string contents;
	uint32_t length_bytes;

	File(const char* contents, uint32_t length_bytes);

	~File();

};

#endif // CORE_FILE_H
