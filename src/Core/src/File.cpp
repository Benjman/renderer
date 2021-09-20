#include <Core/File.h>

#include "Config.h"

#include <cstring>
#include <fstream>

File::File(char* contents, uint32_t length)
	: contents(new char[length + 1]), length(length) {
	strncpy(this->contents, contents, length - 1);
}

File::~File() {
	delete[] contents;
}

File File::LOAD(const char* rel_path) {
	std::string path = find_path(rel_path);
	std::ifstream stream(path, std::ios::binary | std::ios::ate);
	if (stream.fail())
		throw std::runtime_error("Failed to load input stream from path '" + path + "'");

	std::streamsize length = stream.tellg();
	stream.seekg(0, std::ios::beg);
	char contents[length];
	stream.read(contents, length);

	File file(contents, length);
	return file;
}

std::string File::find_path(const char* rel_path) {
	std::string path = RES_DIR;
	path += rel_path;
	return path;
}
