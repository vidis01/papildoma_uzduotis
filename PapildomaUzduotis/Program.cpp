// Program.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Metodai.h"
#include <string>
#include "Zodis.h"
#include <map>

int main()
{
    std::map<string, Zodis> words;

    int wordsCount = ReadFromFile(words);
    int reapeatedWordsMoreThan2 = WriteToFile(words);


    std::cout << "Tekstinio failo Tekstas.txt nuskaitytu zodziu skaicius: " << wordsCount << "\n";
    std::cout << "Suskaiciuotas unikaliu zodziu skaicius: " << words.size() << "\n";
    std::cout << "Pasikartojantys 2 ir daugiau zodziu skaicius: " << reapeatedWordsMoreThan2 << "\n";
    std::cout << "Zodziai, pasikartojantys 2 ir daugiau kartu, issaugoti faile Rezultatai.txt: \n";

}
