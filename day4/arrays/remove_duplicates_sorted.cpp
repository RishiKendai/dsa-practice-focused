#include <bits/stdc++.h>
using namespace std;

void remove_duplicate(vector<int>& arr) {
  int index = 0;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] != arr[index]) {
      arr[++index] = arr[i];
    }
  }
  cout << index + 1 << endl;
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
  remove_duplicate(arr);
  for (int num : arr) cout << num << " ";
}