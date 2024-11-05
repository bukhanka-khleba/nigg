#include <iostream>
using namespace std;

int main() {
    // Задание 1
    double R1, R2, R3, R0;

    cout << "Задание 1: Расчет сопротивления" << endl;
    cout << "Введите R1: ";
    cin >> R1;
    cout << "Введите R2: ";
    cin >> R2;
    cout << "Введите R3: ";
    cin >> R3;

    if (R1 == 0 || R2 == 0 || R3 == 0) {
        cout << "Ошибка: Сопротивление не может быть равно нулю." << endl;
    } else {
        R0 = 1 / (1 / R1 + 1 / R2 + 1 / R3);
        cout << "R0 = " << R0 << endl;
    }

    // Задание 2
    double L, R, S, pi = 3.1415;

    cout << "\nЗадание 2: Расчет площади круга" << endl;
    cout << "Введите длину окружности L: ";
    cin >> L;

    R = L / (2 * pi);
    S = pi * R * R;

    cout << "Радиус R = " << R << endl;
    cout << "Площадь S = " << S << endl;

    // Задание 3
    double v, t, a, S_distance;

    cout << "\nЗадание 3: Расчет пройденного расстояния" << endl;
    cout << "Введите начальную скорость v: ";
    cin >> v;
    cout << "Введите время t: ";
    cin >> t;
    cout << "Введите ускорение a: ";
    cin >> a;

    S_distance = v * t + (a * t * t) / 2;

    cout << "Пройденное расстояние S = " << S_distance << endl;


    // Задание 4
    long long seconds;

    cout << "\nЗадание 4: Перевод секунд в часы, минуты и секунды" << endl;
    cout << "Введите время в секундах: ";
    cin >> seconds;

    int hours = seconds / 3600;
    seconds %= 3600;
    int minutes = seconds / 60;
    seconds %= 60;

    cout << hours << " часов, " << minutes << " минут, " << seconds << " секунд" << endl;


    // Задание 5
    double decimal_number;

    cout << "\nЗадание 5: Преобразование дробного числа в денежный формат" << endl;
    cout << "Введите дробное число: ";
    cin >> decimal_number;

    int dollars = static_cast<int>(decimal_number);
    int cents = static_cast<int>((decimal_number - dollars) * 100);

    cout << dollars << " долларов и " << cents << " центов" << endl;


    // Задание 6
    int days;

    cout << "\nЗадание 6: Преобразование дней в недели и дни" << endl;
    cout << "Введите количество дней: ";
    cin >> days;

    int weeks = days / 7;
    int remaining_days = days % 7;

    cout << weeks << " недель и " << remaining_days << " дней" << endl;


    // Задание 7
    double distance, time7, speed;

    cout << "\nЗадание 7: Расчет скорости бегуна" << endl;
    cout << "Calculating running speed." << endl;
    cout << "Enter the length of distance(meters) = ";
    cin >> distance;
    cout << "Enter the time taken (seconds) = ";
    cin >> time7;

    speed = distance / time7;

    cout << "Speed = " << speed << " m/s" << endl;

    return 0;
}