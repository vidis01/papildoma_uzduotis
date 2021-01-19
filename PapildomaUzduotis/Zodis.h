#pragma once
#include <string>
#include <list>
using namespace std;

class Zodis {
private: 
	std::string word = "";
	int count = 0;
	std::list<int> lineNumbers;
public:
	void setWord(std::string);
	std::string getWord();
	void incrementCount();
	int getCount();
	void addLineNumber(int);
	std::list<int>& getLineNumbers();
};

