#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  cin >> num;
  set<int> my_set = {};
  for (int i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      my_set.insert(i);
      my_set.insert((num / i));
    }
  }
  for (auto value : my_set) {
    cout << value << " ";
  }
}