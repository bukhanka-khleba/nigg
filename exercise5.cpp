#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits> 

using namespace std;

int main() {
    
    double u, v, w, s, t_silage, f, k, p, q, r, t_feed;

    
    cout << "суточный рацион коровы (сено, силос, комбикорм - через пробел): ";
    cin >> u >> v >> w;
    cout << "количество кормов в хозяйстве (сено, силос, комбикорм - через пробел): ";
    cin >> s >> t_silage >> f;
    cout << "количество коров в стаде: ";
    cin >> k;
    cout << "процент ежедневной гибели коров: ";
    cin >> p;
    cout << "процент ежедневной порчи сена: ";
    cin >> q;
    cout << "процент ежедневного разворовывания силоса: ";
    cin >> r;
    cout << "процент ежедневной продажи комбикорма: ";
    cin >> t_feed;


    int days = 0;
    while (true) {
        
        if (s < u * k || t_silage < v * k || f < w * k) {
            cout << "Нельзя будет кормить коров по полному рациону через " << days << " дней." << endl;

            
            double days_hay = (s > 0) ? s / (u * k) : 0;
            double days_silage = (t_silage > 0) ? t_silage / (v * k) : 0;
            double days_feed = (f > 0) ? f / (w * k) : 0;

            if (days_hay < days_silage && days_hay < days_feed) {
                cout << "Сено кончится раньше." << endl;
            } else if (days_silage < days_hay && days_silage < days_feed) {
                cout << "Силос кончится раньше." << endl;
            } else {
                cout << "Комбикорм кончится раньше." << endl;
            }

            break; 
        }

    
        k *= (1.0 - p / 100.0);
        s *= (1.0 - q / 100.0);
        t_silage *= (1.0 - r / 100.0);
        f *= (1.0 - t_feed / 100.0);

        days++;

    
        if (k <= 0) {
            cout << "Все коровы померли в муках через " << days << " дней." << endl;
            break;
        }
    }


    return 0;
}