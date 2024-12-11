#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> arr1 = {2, 5, 8, 12};
  vector<int> arr2 = {1, 3, 7, 9, 15};
  
  for (int num : arr1) {
    cout << num << " ";
  }
  cout << endl;

    for (int num :arr2) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> merged_array;


  int i = 0, j = 0;

  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] <= arr2[j]) {
      merged_array.push_back(arr1[i]);
      i++;
    } else {
      merged_array.push_back(arr2[j]);
      j++;
    }
  }

  
  while (i < arr1.size()) {
    merged_array.push_back(arr1[i]);
    i++;
  }

  while (j < arr2.size()) {
    merged_array.push_back(arr2[j]);
    j++;
  }

  cout << "Объединенный отсортированный массив: ";
  for (int num : merged_array) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}