#include <bits/stdc++.h>
using namespace std;

bool check_is_sorted(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i - 1]) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  bool is_sorted = check_is_sorted(arr);
  cout << "Array is sorted ? " << boolalpha << is_sorted << endl;
}