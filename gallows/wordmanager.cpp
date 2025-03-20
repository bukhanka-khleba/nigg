#include "wordmanager.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

WordManager::WordManager(int difficulty) {
    loadWords(difficulty);
    srand(time(0));
    reset(difficulty);
}

void WordManager::loadWords(int difficulty) {
    std::ifstream file("words.txt");
    std::string word;
    words.clear();

    while (std::getline(file, word)) {
        if (difficulty == 1 && word.length() <= 5) words.push_back(word);
        else if (difficulty == 2 && word.length() > 5 && word.length() <= 8) words.push_back(word);
        else if (difficulty == 3 && word.length() > 8) words.push_back(word);
    }
}

void WordManager::reset(int difficulty) {
    loadWords(difficulty);
    if (!words.empty()) {
        secretWord = words[rand() % words.size()];
        guessedLetters.assign(secretWord.length(), false);
    }
}

bool WordManager::checkLetter(char letter) {
    bool found = false;
    if (letter >= 'À' && letter <= 'ß') letter += 32; 
    for (size_t i = 0; i < secretWord.length(); ++i) {
        char currentChar = secretWord[i];
        if (currentChar >= 'À' && currentChar <= 'ß') currentChar += 32;
        if (currentChar == letter) {
            guessedLetters[i] = true;
            found = true;
        }
    }
    return found;
}

std::string WordManager::getHiddenWord() const {
    std::string hidden;
    for (size_t i = 0; i < secretWord.length(); ++i) {
        hidden += guessedLetters[i] ? secretWord[i] : '_';
        hidden += ' ';
    }
    return hidden;
}

bool WordManager::isWordGuessed() const {
    return std::all_of(guessedLetters.begin(), guessedLetters.end(), [](bool b) { return b; });
}