#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ifstream file("data.txt");
    
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл 'data.txt'." << std::endl;
        return 1; 
    }

    std::cout << "Строки, содержащие слово 'C++':" << std::endl;

    std::string line;
    
    while (std::getline(file, line)) {
        if (line.find("C++") != std::string::npos) {
            std::cout << line << std::endl;
        }
    }

    file.close();

    return 0;
}