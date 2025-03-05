#include <iostream>
#include <random>
#include <chrono>

int main() {
    const int SIZE = 1000;
    int arr[SIZE];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = dis(gen);
    }

    auto start = std::chrono::high_resolution_clock::now();

    bool swapped;
    for (int i = 0; i < SIZE - 1; ++i) {
        swapped = false;
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < arr[i-1]) {
            std::cerr << "Ошибка сортировки!" << std::endl;
            return 1;
        }
    }

    std::cout << "Массив успешно отсортирован за " 
              << elapsed.count() << " секунд" << std::endl;
    std::cout << "Первые 100 элементов: ";
    for (int i = 0; i < 100; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nПоследние 10 элементов: ";
    for (int i = SIZE-10; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}