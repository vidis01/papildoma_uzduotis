#include "Metodai.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include "Zodis.h"

using namespace std;

int ReadFromFile(map<string, Zodis>& words, std::string fileName, bool isWebsites) {
	int wordsCount = 0;
	ifstream inputStream(fileName);

	if (inputStream.fail()) {
		std::cout << "Failas neegzistuoja" << endl;
	}
	else
	{
		string input;
		int lineNumber = 0;		

		while (!inputStream.eof())
		{
			std::getline(inputStream, input);
			wordsCount += splitWords(input, ++lineNumber, words, isWebsites);
		}
	}
	return wordsCount;
}

void addWordToMap(std::string word, int lineNumber, std::map<string, Zodis>& zodziai) {
	if (zodziai.count(word) == 0 && word != "") {
		Zodis zodis;
		zodis.addLineNumber(lineNumber);
		zodis.setWord(word);
		zodis.incrementCount();
		zodziai.insert(std::pair<std::string, Zodis>(word, zodis));
	}
	else if (word != "") {
		zodziai[word].incrementCount();
		zodziai[word].addLineNumber(lineNumber);
	}
}

int findWords(std::string str, int lineNumber, std::map<string, Zodis>& zodziai) {

	std::string word = "";
	int wordsCount = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		auto x = str[i];
		if (x == ' ' || x == '.' || x == ',' || x == '-' || x == '?' || x == '!' || x == '"' || x == '\'' || x == ':' || x == ';' || x == '(' || x == ')')
		{
			addWordToMap(word, lineNumber, zodziai);
			++wordsCount;
			word = "";
		}
		else {
			word = word + x;

			if (i == str.size() - 1 && word != "")
			{
				addWordToMap(word, lineNumber, zodziai);
				++wordsCount;
			}
		}
	}
	return wordsCount;
}

bool isWebsite(string word) {

	if (word.rfind("http", 0) == 0 || word.rfind("www", 0) == 0) {
		return true;
	}
	else
		return false;
}

int findWebsites(std::string str, int lineNumber, std::map<string, Zodis>& zodziai) {

	std::string word = "";
	int wordsCount = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		auto x = str[i];
		if (x == ' ')
		{
			if (isWebsite(word))
			{
				addWordToMap(word, lineNumber, zodziai);
				++wordsCount;
			}			
			word = "";
		}
		else {
			word = word + x;

			if (i == str.size() - 1 && word != "")
			{
				if (isWebsite(word))
				{
					addWordToMap(word, lineNumber, zodziai);
					++wordsCount;
				}
			}
		}
	}
	return wordsCount;
}

int splitWords(std::string str, int lineNumber, std::map<string, Zodis>& zodziai, bool isWebsites) {

	if (isWebsites)
	{
		return findWebsites(str, lineNumber, zodziai);

	}
	else {
		return findWords(str, lineNumber, zodziai);
	}
}

int WriteToFile(map<string, Zodis>& words, std::string fileName, bool writeAll) {

	int wordsCount = 0;
	string eilutes = "";

	ofstream outputStream(fileName);

	for (auto word : words) {
		
		if (writeAll)
		{
			eilutes = "";

			for (auto number : word.second.getLineNumbers()) {
				eilutes = eilutes + " " + std::to_string(number);
			}
			outputStream << left << setw(15) << word.second.getWord() << "\t" << "Pasikartoja:\t" << word.second.getCount() << "     Siose eilutese:\t" << eilutes << endl;
			
			++wordsCount;
		}
		else {
			if (word.second.getCount() >= 2)
			{
				eilutes = "";

				for (auto number : word.second.getLineNumbers()) {
					eilutes = eilutes + " " + std::to_string(number);
				}
				outputStream << left << setw(15) << word.second.getWord() << "\t" << "Pasikartoja:\t" << word.second.getCount() << "     Siose eilutese:\t" << eilutes << endl;
				
				++wordsCount;
			}
		}	
	}
	return wordsCount;
}
