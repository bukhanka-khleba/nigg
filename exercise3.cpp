#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {

    std::cout << "Введите имя файла: ";
    std::string filename;
    std::cin >> filename;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл '" << filename << "'." << std::endl;
        return 1;
    }

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    std::smatch matches;

    std::cout << "Найденные email-адреса:" << std::endl;

    std::string::const_iterator searchStart(fileContent.cbegin());
    while (std::regex_search(searchStart, fileContent.cend(), matches, emailPattern)) {
        std::cout << matches[0] << std::endl;
        searchStart = matches.suffix().first;
    }

    return 0;
}