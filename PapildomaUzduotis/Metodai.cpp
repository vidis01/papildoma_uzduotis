#include "Metodai.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Zodis.h"

using namespace std;

void ReadFromFile(map<string, Zodis>& zodziai)
{
	ifstream inputStream("Tekstas.txt");

	if (inputStream.fail()) {
		cout << "Failas neegzistuoja" << endl;
	}
	else
	{
		string input;
		int lineNumber = 0;

		while (!inputStream.eof())
		{
			std::getline(inputStream, input);
			splitWords(input, ++lineNumber, zodziai);
		}
	}
}

void splitWords(std::string str, int lineNumber, std::map<string, Zodis>& zodziai)
{//meodai dar nepabaigtas
	std::string word = "";
	for (auto x : str)
	{
		if (x == ' ' || x == '.' || x == ',' || x == '-' || x == '?' || x == '!' || x == '"' || x == '\'' || x == ':' || x == ';')
		{
			cout << word << endl;
			word = "";
		}
		else {
			word = word + x;
		}
	}
	cout << word << endl;
}