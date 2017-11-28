#ifndef LINE_ITERATOR_H
#define LINE_ITERATOR_H

#include <vector>
#include "stddef.h"
#include <string>

namespace vm {

class ConstLineIterator {

	private:
		const std::vector<std::string>& data;
		size_t lineNumber;

		ConstLineIterator(const std::vector<std::string>& data, size_t lineNumber);

	public:
		bool operator!=(const ConstLineIterator &other) const;
		const std::string& operator*() const;
		ConstLineIterator operator++();

	friend class File;
};

class LineIterator {

	private:
		std::vector<std::string>& data;
		size_t lineNumber;

		LineIterator(std::vector<std::string>& data, size_t lineNumber);

	public:
		bool operator!=(const LineIterator &other) const;
		std::string& operator*() const;
		LineIterator operator++();

	friend class File;
};

}

#endif
