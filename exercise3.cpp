#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

int main() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);
    
    std::vector<int> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(dis(gen));
    }

    auto write_start = std::chrono::high_resolution_clock::now();
    
    std::ofstream outFile("data.txt");
    if (!outFile.is_open()) {
        std::cerr << "Ошибка создания файла!" << std::endl;
        return 1;
    }
    for (const auto& num : numbers) {
        outFile << num << " ";
    }
    outFile.close();
    
    auto write_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> write_time = write_end - write_start;

    auto read_start = std::chrono::high_resolution_clock::now();
    
    std::ifstream inFile("data.txt");
    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }
    
    std::vector<int> readNumbers;
    int num;
    while (inFile >> num) {
        readNumbers.push_back(num);
    }
    inFile.close();
    
    auto read_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> read_time = read_end - read_start;

    if (readNumbers.size() != 10) {
        std::cerr << "Ошибка: некорректное количество элементов в файле!" << std::endl;
        return 1;
    }

    auto sort_start = std::chrono::high_resolution_clock::now();
    
    std::sort(readNumbers.begin(), readNumbers.end());
    
    auto sort_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sort_time = sort_end - sort_start;

    std::cout << "Исходные числа: ";
    for (const auto& n : numbers) std::cout << n << " ";
    
    std::cout << "\nОтсортированные числа: ";
    for (const auto& n : readNumbers) std::cout << n << " ";
    
    std::cout << "\n\nВремя выполнения операций:"
              << "\nЗапись в файл: " << write_time.count() << " сек"
              << "\nЧтение из файла: " << read_time.count() << " сек"
              << "\nСортировка: " << sort_time.count() << " сек"
              << std::endl;

    return 0;
}