#include <bits/stdc++.h>
using namespace std;

int max_consecutive_one(vector<int>& nums) {
  int counter = 0;
  int maxi = 0;
  for (int num : nums) {
    if (num == 1) {
      counter++;
      maxi = max(counter, maxi);
    } else {
      counter = 0;
    }
  }
  return maxi;
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
  int num = max_consecutive_one(arr);
  cout << "max Consecutive one " << num << endl;
  return 0;
}