#include <core/file.h>
#include <fstream>

File load_file(const char *path) {
	std::ifstream stream(path, std::ios::binary | std::ios::ate);
	if (stream.fail())
		throw std::runtime_error("Failed to load input stream from path '" + std::string(path) + "'");

	std::streamsize size = stream.tellg();
	stream.seekg(0, std::ios::beg);
	auto* buffer = new char[size + 1];
	stream.read(buffer, size);
	buffer[size] = '\0';

	File file(buffer, size);
	return file;
}

