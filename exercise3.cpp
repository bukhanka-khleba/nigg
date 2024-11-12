#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Client {
    int arrival_time;
    int service_time;
};

int main() {
    int t, l, num_clients = 0;
    long long work_time = 0;
    int shift_duration;

    cout << "Введите продолжительность смены (T): ";
    cin >> shift_duration;

    vector<Client> clients;

    cout << "Вводите время прихода (t) и продолжительность обслуживания (l) для каждого клиента (через пробел). Для завершения ввода введите любую букву" << endl;
    while (cin >> t >> l) {
        clients.push_back({t, l});
    }


    sort(clients.begin(), clients.end(), [](const Client& a, const Client& b) {
        return a.arrival_time < b.arrival_time;
    });

    int current_time = 0;

    for (const auto& client : clients) {

        if (client.arrival_time >= shift_duration) {
            break;

        current_time = max(current_time, client.arrival_time);


        if (current_time + client.service_time <= shift_duration) {
            num_clients++;
            work_time += client.service_time;
            current_time += client.service_time;
        } else {
            
            
            int remaining_shift_time = shift_duration - current_time;
            if (remaining_shift_time > 0) {
                num_clients++;
                work_time += remaining_shift_time;
                current_time += remaining_shift_time;

            }
             break; 

        }
    }

    cout << "Количество обслуженных клиентов: " << num_clients << endl;
    cout << "Затраченное рабочее время: " << work_time << endl;

    return 0;
}