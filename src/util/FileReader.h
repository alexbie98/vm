#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <string>
#include <vector>

namespace util {

class FileReader {

	public:
		std::vector<std::string> readLines(const std::string& file);

};

}

#endif
