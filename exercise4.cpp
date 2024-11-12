#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    
    double alpha, v0, beta;
    int n;

    
    cout << "угол (в радианах): ";
    cin >> alpha;
    cout << "начальная скорость (м/с): ";
    cin >> v0;
    cout << "коэффициент уменьшения энергии (beta): ";
    cin >> beta;
    cout << "количество точек касания (n): ";
    cin >> n;

    
    double vx = v0 * cos(alpha);
    double vy = v0 * sin(alpha);

    
    vector<double> x_coords;

    const double g = 9.81;

    double t = (2 * vy) / g;


    double x = vx * t;
    x_coords.push_back(x);

    
    for (int i = 1; i < n; ++i) {
        
        vy *= sqrt(beta);

        t = (2 * vy) / g;

        x += vx * t;
        x_coords.push_back(x);
    }

    
    cout << fixed << setprecision(2); 
    cout << "Абсцисс точек касания:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x_coords[i] << " м" << endl;
    }

    return 0;
}