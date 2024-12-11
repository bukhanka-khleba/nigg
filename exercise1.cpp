#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers = {1, 2, 2, 3, 4, 4, 5, 1, 6, 3};

  for (int num : numbers) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> result;
  for (int i = 0; i < numbers.size(); i++) {
    bool found = false;
    for (int j = 0; j < result.size(); j++) {
      if (numbers[i] == result[j]) {
        found = true;
        break;
      }
    }
    if (!found) {
      result.push_back(numbers[i]);
    }
  }

  cout << "Массив с уникальными элементами: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}