#pragma once
#include <string>
#include <map>
#include "Zodis.h"

using namespace std;

int ReadFromFile(map<std::string, Zodis>& zodziai);
int splitWords(std::string str, int lineNumber, map<std::string, Zodis>& zodziai);
int WriteToFile(map<string, Zodis>& words);