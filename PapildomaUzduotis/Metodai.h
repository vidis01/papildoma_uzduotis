#pragma once
#include <string>
#include <map>
#include "Zodis.h"

using namespace std;

int ReadFromFile(map<std::string, Zodis>& zodziai, std::string fileName, bool isWebsites);
int splitWords(std::string str, int lineNumber, map<std::string, Zodis>& zodziai, bool isWebsites);
int WriteToFile(map<string, Zodis>& words, std::string fileName, bool writeAll);
void addWordToMap(std::string word, int lineNumber, std::map<string, Zodis>& zodziai);
int findWebsites(std::string str, int lineNumber, std::map<string, Zodis>& zodziai);
bool isWebsite(string word);