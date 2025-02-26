#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string filename;

    std::cout << "Введите имя файла: ";
    std::cin >> filename;


    std::ofstream file(filename);

    
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл для записи." << std::endl;
        return 1; 
    }

    
    std::string line;

    std::cout << "Введите 5 строк текста:" << std::endl;

    
    for (int i = 0; i < 5; ++i) {
        std::cout << "Строка " << i + 1 << ": ";
        std::cin.ignore(); 
        std::getline(std::cin, line); 
        file << line << std::endl; 
    }

    file.close();

    std::cout << "Данные успешно записаны в файл." << std::endl;

    std::ifstream readFile(filename);


    if (!readFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения." << std::endl;
        return 1; //
    }

    std::cout << "\nСодержимое файла:" << std::endl;


    while (std::getline(readFile, line)) {
        std::cout << line << std::endl;
    }

    readFile.close();

    return 0;
}