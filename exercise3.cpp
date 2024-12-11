#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};


  int max_so_far = arr[0];
  int max_ending_here = arr[0];
  int start_index = 0;
  int end_index = 0;
  int temp_start_index = 0;

  for (int i = 1; i < arr.size(); i++) {

    if (arr[i] > max_ending_here + arr[i]) {
      max_ending_here = arr[i];
      temp_start_index = i;

    } else {

      max_ending_here = max_ending_here + arr[i];

    }

    if (max_so_far < max_ending_here) {
      max_so_far = max_ending_here;
      start_index = temp_start_index;
      end_index = i;
    }
  }

  cout << "Максимальная сумма: " << max_so_far << endl;
  cout << "Подмассив: ";
  for (int i = start_index; i <= end_index; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}