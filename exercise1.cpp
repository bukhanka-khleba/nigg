#include <iostream>

class Seconds {
public:
    int time;

    Seconds(int t) : time(t) {}

    void display() const {
        std::cout << "Time: " << time << " seconds" << std::endl;
    }
};

int main() {
    int n;
    std::cout << "Введите количество объектов: ";
    std::cin >> n;

    Seconds** arr = new Seconds*[n];

    
    for (int i = 0; i < n; ++i) {
        int t;
        std::cout << "Введите время в секундах для объекта " << i + 1 << ": ";
        std::cin >> t;
        arr[i] = new Seconds(t);
    }

    for (int i = 0; i < n; ++i) {
        arr[i]->display();
    }

    for (int i = 0; i < n; ++i) {
        delete arr[i];
    }
    delete[] arr;
    /*
    Seconds** arr = new Seconds*[n]; — выделяется память для массива указателей на объекты класса Seconds.
    Каждый элемент массива будет хранить указатель на объект Seconds.
    arr[i] = new Seconds(t); — для каждого элемента массива выделяется память под объект Seconds,
    инициализируемый значением t.
    */

    return 0;
}