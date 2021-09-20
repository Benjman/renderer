#ifndef CORE_FILE_H
#define CORE_FILE_H

#include <cstdint>
#include <string>

#endif // CORE_FILE_H

struct File {
	static File LOAD(const char* rel_path);
	static std::string find_path(const char* rel_path);

	char* contents;
	uint32_t length;

	File(char* contents, uint32_t length);

	~File();

};
