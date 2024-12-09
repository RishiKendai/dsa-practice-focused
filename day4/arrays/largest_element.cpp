#include <bits/stdc++.h>
using namespace std;

int largest_element(vector<int> &arr) {
  if (arr.size() == 0) return -1;
  int largest = arr[0];
  for (int num : arr)
    if (num > largest) largest = num;
  return largest;
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
  int largest = largest_element(arr);
  cout << "largest element = " << largest << endl;

  return 0;
}