#ifndef CHAR_ITERATOR_H
#define CHAR_ITERATOR_H

#include <vector>
#include "stddef.h"
#include <string>
#include "data/Pos.h"

namespace vm {

class ConstWordIterator;

//TODO add copy?
//TODO update code to use getPos()
class ConstCharIterator {

		const std::vector<std::string>& data;
		Pos filePos;

		ConstCharIterator(const std::vector<std::string>& data, Pos filePos);

	public:
		ConstCharIterator(const ConstCharIterator &other);
		bool operator!=(const ConstCharIterator &other) const;
		const char& operator*() const;
		ConstCharIterator operator++();
		// minusOne returns an iterator one char before.  If this
		// points to the first element of the file, returns an
		// identical iterator.
		ConstCharIterator minusOne() const;
		// Overload cast from WordIterator
		ConstCharIterator(const ConstWordIterator &wordIt);
		Pos getPos() const;

	friend class File;
	friend class ConstWordIterator;
};

class CharIterator {

	private:
		std::vector<std::string>& data;
		Pos filePos;

		CharIterator(std::vector<std::string>& data, Pos filePos);

	public:
		CharIterator(const CharIterator &other);
		bool operator!=(const CharIterator &other) const;
		char& operator*() const;
		CharIterator operator++();
		CharIterator minusOne() const;
		Pos getPos() const;

	friend class File;
	friend class WordIterator;
};

}

#endif
