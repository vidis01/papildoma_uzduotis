#pragma once
#include <string>
using namespace std;

class Zodis {
private: 
	std::string word = "";
	int count = 0;
	int lineNumber = 0;
public:
	void setWord(std::string);
	std::string getWord();
	void incrementCount();
	int getCount();
	void setLineNumber(int);
	int getLineNumber();
};

