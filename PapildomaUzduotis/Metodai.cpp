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

int splitWords(std::string str, int lineNumber, std::map<string, Zodis>& zodziai)
{
	std::string word = "";
	int wordsCount = 0;

	for (auto x : str)
	{
		if (x == ' ' || x == '.' || x == ',' || x == '-' || x == '?' || x == '!' || x == '"' || x == '\'' || x == ':' || x == ';' || x == '(' || x ==')')
		{
			if (word != "" && zodziai.count(word) == 0) {
				Zodis zodis;
				zodis.addLineNumber(lineNumber);
				zodis.setWord(word);
				zodis.incrementCount();
				zodziai.insert(std::pair<std::string, Zodis>(word, zodis));
				//std::cout << word << endl; //ispausdina i ekrana zodi, testavimosi tikslais
				++wordsCount;
			}
			else {
				zodziai[word].incrementCount();
				++wordsCount;
			}
			word = "";
		}
		else {
			word = word + x;
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
				eilutes += " " + number;
			}
			outputStream << left << setw(15) << word.first << "\t" << setw(20) << "Pasikartoja:\t" << word.second.getCount() << setw(20) << "Siose eilutese:\t" << eilutes << endl;
			++wordsCount;
		}		
	}
	return wordsCount;
}