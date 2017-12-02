#ifndef CHAR_ITERATOR_H
#define CHAR_ITERATOR_H

#include <vector>
#include "stddef.h"
#include <string>
#include "data/Pos.h"

namespace vm {

//TODO Make word iterator and make conversion to char iterator
class ConstCharIterator {

	private:
		const std::vector<std::string>& data;
		Pos filePos;

		ConstCharIterator(const std::vector<std::string>& data, Pos filePos);

	public:
		bool operator!=(const ConstCharIterator &other) const;
		const char& operator*() const;
		ConstCharIterator operator++();

	friend class File;
};

class CharIterator {

	private:
		std::vector<std::string>& data;
		Pos filePos;

		CharIterator(std::vector<std::string>& data, Pos filePos);

	public:
		bool operator!=(const CharIterator &other) const;
		char& operator*() const;
		CharIterator operator++();

	friend class File;
};

}

#endif
