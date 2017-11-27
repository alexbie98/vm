#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace util {

class FileWriter {

	public:
		void writeLines(const std::string& file, 
				const std::vector<std::string>& lines);

};

}

#endif
