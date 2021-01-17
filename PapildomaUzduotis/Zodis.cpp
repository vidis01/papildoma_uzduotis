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

void Zodis::setLineNumber(int lineNumber) {
	this->lineNumber;
};

int Zodis::getLineNumber() {
	return lineNumber;
};