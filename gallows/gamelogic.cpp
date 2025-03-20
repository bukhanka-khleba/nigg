#include "gamelogic.h"
#include <iostream>

GameLogic::GameLogic() : score(0), difficulty(1) {}

void GameLogic::run() {
    char playAgain;
    do {
        difficulty = selectDifficulty();
        wordManager.reset(difficulty);
        playRound();
        std::cout << "Хотите сыграть еще? (y/n): ";
        std::cin >> playAgain;
    } while (tolower(playAgain) == 'y');
}

int GameLogic::selectDifficulty() {
    int level;
    std::cout << "Выберите уровень сложности (1-Новичок, 2-Средний, 3-Эксперт): ";
    std::cin >> level;
    return level;
}

void GameLogic::playRound() {
    attempts = 6;
    guessedLetters.clear();
    wordManager.reset(difficulty);

    while (attempts > 0 && !wordManager.isWordGuessed()) {
        displayStatus();
        char guess = PlayerInput::getValidGuess(guessedLetters);
        guessedLetters += guess;

        if (wordManager.checkLetter(guess)) {
            std::cout << "Буква '" << guess << "' есть в слове!\n";
        }
        else {
            std::cout << "Буквы '" << guess << "' нет в слове.\n";
            attempts--;
        }
    }

    displayStatus();
    if (wordManager.isWordGuessed()) {
        std::cout << "Поздравляем! Вы угадали слово: " << wordManager.getHiddenWord() << "\n";
        score += 10;
    }
    else {
        std::cout << "Вы проиграли. Загаданное слово было: " << wordManager.getHiddenWord() << "\n";
    }
    std::cout << "Ваш текущий счет: " << score << "\n";
}

void GameLogic::displayStatus() const {
    std::cout << "\nЗагаданное слово: " << wordManager.getHiddenWord() << "\n";
    std::cout << "Осталось попыток: " << attempts << "\n";
    std::cout << "Использованные буквы: " << guessedLetters << "\n";
}