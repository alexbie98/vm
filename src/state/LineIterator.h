#ifndef LINE_ITERATOR_H
#define LINE_ITERATOR_H

#include <vector>
#include <cstddef>
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
		size_t getLineNumber() const;
		
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
		size_t getLineNumber() const;

	friend class File;
};

}

#endif
