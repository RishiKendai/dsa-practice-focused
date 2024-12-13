#include <bits/stdc++.h>
using namespace std;

int missing_number(vector<int>& nums) {
  int xor1 = 0;
  int xor2 = 0;
  for (int i = 0; i < nums.size(); i++) {
    xor1 = xor1 ^ nums[i];
    xor2 = xor2 ^ (i + 1);
  }
  return xor1 ^ xor2;
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
  int num = missing_number(arr);
  cout << "missing " << num << endl;
  return 0;
}