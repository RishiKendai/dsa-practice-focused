#include <bits/stdc++.h>
using namespace std;

int appear_once(vector<int>& nums) {
  int xor1 = 0;
  for (auto num : nums) {
    xor1 = xor1 ^ num;
  }
  return xor1;
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
  int num = appear_once(arr);
  cout << num << endl;
  return 0;
}

// class Solution {
//  public
//   int singleNumber(int[] nums) {
//     int unique_element = 0;
//     for (int n : nums) unique_element = unique_element ^ n;
//     return unique_element;
//   }
// }