#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "wordmanager.h"
#include "playerinput.h"

class GameLogic {
private:
    int attempts;
    int score;
    int difficulty;
    WordManager wordManager;
    std::string guessedLetters;

    void playRound();
    void displayStatus() const;
    int selectDifficulty();

public:
    GameLogic();
    void run();
};

#endif