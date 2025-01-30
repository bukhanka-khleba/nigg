#include <iostream>
#include <vector>

class Seconds {
private:
    int time;
public:
    Seconds(int t) : time(t) {}
    void setTime(int t) { time = t; }
    int getTime() const { return time; }
};

int main() {
    std::vector<Seconds> timeList = { Seconds(10), Seconds(20), Seconds(30), Seconds(40) };

    std::cout << "Список времени:" << std::endl;
    for (size_t i = 0; i < timeList.size(); ++i) {
        std::cout << "Элемент " << i << ": " << timeList[i].getTime() << " секунд" << std::endl;
    }

    size_t index;
    int newTime;
    std::cout << "Введите индекс элемента для изменения: ";
    std::cin >> index;
    
    if (index < timeList.size()) {
        std::cout << "Введите новое значение времени (в секундах): ";
        std::cin >> newTime;
        timeList[index].setTime(newTime);
    } else {
        std::cout << "Ошибка: некорректный индекс!" << std::endl;
    }

    std::cout << "Обновленный список времени:" << std::endl;
    for (size_t i = 0; i < timeList.size(); ++i) {
        std::cout << "Элемент " << i << ": " << timeList[i].getTime() << " секунд" << std::endl;
    }
    
    return 0;
}