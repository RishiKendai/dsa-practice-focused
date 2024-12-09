#include <bits/stdc++.h>
using namespace std;

int second_largest_element(vector<int> &arr) {
  if (arr.size() == 0) return -1;
  int largest = arr[0];
  int second_largest = -1;
  for (int num : arr) {
    if (num > largest) {
      second_largest = largest;
      largest = num;
    } else {
      if (num != largest && num > second_largest) {
        second_largest = num;
      }
    }
  }
  return second_largest;
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
  int second_largest = second_largest_element(arr);
  cout << "largest element = " << second_largest << endl;

  return 0;
}