#include <Core/File.h>

#include "Config.h"

#include <string> // std::string
#include <fstream>

File::File(const char* contents, uint32_t length_bytes)
	: contents(std::string(contents, length_bytes)), length_bytes(length_bytes) {
}

File::~File() {
}

File File::LOAD(const char* rel_path) {
	std::string path = RES_DIR;
	path += rel_path;

	std::ifstream stream(path, std::ios::binary | std::ios::ate);
	if (stream.fail())
		throw std::runtime_error("Failed to load input stream from path '" + path + "'");

	std::streamsize len = stream.tellg(); // get char count
	stream.seekg(0, std::ios::beg); // reset stream to head

	char contents[len];
	stream.read(contents, len);

	File file(contents, len);
	return {file};
}
