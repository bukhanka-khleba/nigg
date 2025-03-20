#include <windows.h>
#include <locale.h>
#include "gamelogic.h"
#include <iostream>

int main() {
    SetConsoleCP(1251);              
    SetConsoleOutputCP(1251);        
    setlocale(LC_ALL, "Russian");     

    std::cout << "Добро пожаловать в игру 'Виселица'!\n";
    GameLogic game;
    game.run();
    return 0;
}