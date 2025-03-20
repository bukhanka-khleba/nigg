#include "playerinput.h"
#include <iostream>
#include <limits>
#include <cctype>

char PlayerInput::getValidGuess(const std::string& guessed) {
    char guess;
    while (true) {
        std::cout << "Введите букву: ";
        std::string input;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input.length() == 1) {
            char c = input[0];
            if ((c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
                guess = (c >= 'А' && c <= 'Я') ? c + 32 : c;
                if (guessed.find(guess) == std::string::npos) {
                    return guess;
                }
                else {
                    std::cout << "Вы уже вводили эту букву. Попробуйте снова.\n";
                }
            }
            else {
                std::cout << "Некорректный ввод. Введите одну русскую букву.\n";
            }
        }
        else {
            std::cout << "Некорректный ввод. Введите одну букву.\n";
        }
    }
}