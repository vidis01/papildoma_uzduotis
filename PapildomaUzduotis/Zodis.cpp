#include "Zodis.h"

void Zodis::setWord(std::string word) {
	this->word = word;
};

std::string Zodis::getWord() {
	return word;
};

void Zodis::incrementCount() {
	++count;
};

int Zodis::getCount() {
	return count;
};

void Zodis::addLineNumber(int lineNumber) {
	lineNumbers.push_back(lineNumber);
};

std::list<int>& Zodis::getLineNumbers() {
	return lineNumbers;
};