#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include <string>

class PlayerInput {
public:
    static char getValidGuess(const std::string& guessedLetters);
};

#endif