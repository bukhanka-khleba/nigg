#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

    vector<int> detail_processing_times;

    
    cout << "Вводите время обработки каждой детали на трех станках (через пробел): и букву чтобы завешить" << endl;

    int time1, time2, time3;
    while (cin >> time1 >> time2 >> time3) {
        detail_processing_times.push_back(time1 + time2 + time3);
    }

    if (detail_processing_times.empty()) {
        cout << "Общее время обработки: 0" << endl;
        return 0;
    }


    int max_processing_time = 0;
    int current_time = 0;

    vector<int> machine_times(3, 0);

    for (int detail_time : detail_processing_times) {
        int min_machine_time = machine_times[0];
        for (int time : machine_times) {
            min_machine_time = min(min_machine_time, time);
        }

        current_time = max(current_time, min_machine_time);



        int time1, time2, time3;

        time1 = time2 = time3 = detail_time / 3;


        machine_times[0] = current_time + time1;
        machine_times[1] = max(machine_times[1], machine_times[0]) + time2; 
        machine_times[2] = max(machine_times[2], machine_times[1]) + time3;

        current_time = machine_times[2]; 

    }

    cout << "Общее время обработки: " << current_time << endl;
    /*Вводите как на примере снизу 
    1 21 23
    2 1 1
    23
    */
    return 0;
}