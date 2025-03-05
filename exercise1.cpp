#include <iostream>
#include <cstdlib>

int main() {
#ifdef __linux__
    const char* home = std::getenv("HOME");
    if (home) {
        std::cout << home << std::endl;
    } else {
        std::cerr << "Ошибка" << std::endl;
        return 1;
    }
#else
    std::cerr << "Ошибка" << std::endl;
    return 1;
#endif
    return 0;
}