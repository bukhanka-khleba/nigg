#ifndef WORDMANAGER_H
#define WORDMANAGER_H

#include <vector>
#include <string>

class WordManager {
private:
    std::string secretWord;
    std::vector<std::string> words;
    std::vector<bool> guessedLetters;

    void loadWords(int difficulty);

public:
    WordManager(int difficulty = 1);
    bool checkLetter(char letter);
    std::string getHiddenWord() const;
    bool isWordGuessed() const;
    void reset(int difficulty);
};

#endif
