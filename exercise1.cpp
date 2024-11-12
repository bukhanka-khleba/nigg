#include <iostream>
using namespace std;

int main() {
    double k, p, r; 
    cout << "Введите сумму кредита (k): ";
    cin >> k;
    cout << "Введите процентную ставку (p): ";
    cin >> p;
    cout << "Введите годовую прибыль (r): ";
    cin >> r;

    int years = 0;
    double debt = k;

    while (debt > 0) {
        double interest = debt * (p / 100.0);
        if (r <= interest) {

            cout << "Лох не сможет погасить кредит." << endl;
            return 0;
        }
        debt += interest;  
        debt -= r;        
        years++;           
    }

    cout << "Предприниматель сможет погасить кредит через " << years << " лет." << endl;

    return 0;
}