#include "Metodai.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
#include "Zodis.h"

using namespace std;

int ReadFromFile(map<string, Zodis>& words)
{
	int wordsCount = 0;
	ifstream inputStream("Tekstas.txt");

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
			wordsCount += splitWords(input, ++lineNumber, words);
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

int splitWords(std::string str, int lineNumber, std::map<string, Zodis>& zodziai)
{
	std::string word = "";
	int wordsCount = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		auto x = str[i];
		if (x == ' ' || x == '.' || x == ',' || x == '-' || x == '?' || x == '!' || x == '"' || x == '\'' || x == ':' || x == ';' || x == '(' || x ==')')
		{
			addWordToMap(word, lineNumber, zodziai);
			++wordsCount;
			word = "";
		}
		else {
			word = word + x;
			
			if (i == str.size()-1 && word != "")
			{
				addWordToMap(word, lineNumber, zodziai);
				++wordsCount;
			}
		}		
	}
	return wordsCount;
}

int WriteToFile(map<string, Zodis>& words) {

	int wordsCount = 0;

	ofstream outputStream("Rezultatai.txt");

	for (auto word : words) {

		if (word.second.getCount() >= 2)
		{
			string eilutes = "";
			for (auto number : word.second.getLineNumbers()) {
				eilutes = eilutes + " " + std::to_string(number);
			}
			outputStream << left << setw(15) << word.first << "\t"  << "Pasikartoja:\t" << word.second.getCount() << "     Siose eilutese:\t" << eilutes << endl;
			++wordsCount;
			eilutes = "";
		}		
	}
	return wordsCount;
}