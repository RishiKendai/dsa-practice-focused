#include <bits/stdc++.h>
using namespace std;

void rotate_array(vector<int>& arr) {
  int temp = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    arr[i - 1] = arr[i];
  }
  arr[arr.size() - 1] = temp;
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
  rotate_array(arr);
  for (int num : arr) cout << num << " ";

  return 0;
}