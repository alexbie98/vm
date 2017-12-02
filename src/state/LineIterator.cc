#include "state/LineIterator.h"

using namespace std;
namespace vm {

// ConstLineIterator implementations ----------------------------------------

ConstLineIterator::ConstLineIterator(const vector<string>& data,
	size_t lineNumber): data{data}, lineNumber{lineNumber} {}

bool ConstLineIterator::operator!=(const ConstLineIterator &other) const {
	return lineNumber != other.lineNumber;
}

const string& ConstLineIterator::operator*() const {
	return data[lineNumber];
}

ConstLineIterator ConstLineIterator::operator++(){
	lineNumber++;
	return *this;
}

size_t ConstLineIterator::getLineNumber() const{
	return lineNumber;
}

// LineIterator implementations ----------------------------------------

LineIterator::LineIterator(vector<string>& data, size_t lineNumber):
	data{data}, lineNumber{lineNumber} {}

bool LineIterator::operator!=(const LineIterator &other) const {
	return lineNumber != other.lineNumber;
}

string& LineIterator::operator*() const {
	return data[lineNumber];
}

LineIterator LineIterator::operator++(){
	lineNumber++;
	return *this;
}

size_t LineIterator::getLineNumber() const{
	return lineNumber;
}

}
