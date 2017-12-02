#ifndef WORD_ITERATOR_H
#define WORD_ITERATOR_H

#include <vector>
#include "stddef.h"
#include <string>
#include "data/Pos.h"
#include "state/CharIterator.h"

namespace vm {

//TODO Make word iterator and make conversion to char iterator
class ConstWordIterator {

		ConstCharIterator it;
    ConstCharIterator fileEnd;

    // If pos is not at start of word, moves to next word beginning
		ConstWordIterator(const std::vector<std::string>& data, Pos filePos);

	public:
		bool operator!=(const ConstWordIterator &other) const;
		std::string operator*() const;
		ConstWordIterator operator++();

	friend class File;
};

}

#endif
