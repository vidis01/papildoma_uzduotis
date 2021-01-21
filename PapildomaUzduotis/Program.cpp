// Program.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Metodai.h"
#include <string>
#include "Zodis.h"
#include <map>

int main()
{
    std::map<string, Zodis> words;
    std::map<string, Zodis> webSites;

    int wordsCount = ReadFromFile(words, "Tekstas.txt", false);
    int reapeatedWordsMoreThan2 = WriteToFile(words, "Rezultatai.txt", false);

    std::cout << "Tekstinio failo Tekstas.txt nuskaitytu zodziu skaicius: " << wordsCount << "\n";
    std::cout << "Suskaiciuotas unikaliu zodziu skaicius: " << words.size() << "\n";
    std::cout << "Pasikartojantys 2 ir daugiau zodziu skaicius: " << reapeatedWordsMoreThan2 << "\n";
    std::cout << "Zodziai, pasikartojantys 2 ir daugiau kartu, issaugoti faile \"Rezultatai.txt\". \n\n\n";

    wordsCount = ReadFromFile(webSites, "Tekstas.txt", true);
    WriteToFile(webSites, "Nuorodos.txt", true);

    std::cout << "Tekstinio failo Tekstas.txt nuskaitytu nuorody skaicius: " << wordsCount << "\n";
    std::cout << "Rastos nuorodos, issaugotos faile \"Nuorodos.txt:\" \n";

}
