#include <bits/stdc++.h>
using namespace std;

int long_inc_dec(vector<int>& nums) {
  int maxLen = 1;
  int inc = 1, dec = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > nums[i - 1]) {
      inc++;
      dec = 1;
      maxLen = max(maxLen, max(inc, dec));
    } else if (nums[i] < nums[i - 1]) {
      dec++;
      inc = 1;
      maxLen = max(maxLen, max(inc, dec));
    } else {
      inc = 1;
      dec = 1;
    }
  }
  return maxLen;
}
int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  int res = long_inc_dec(nums);
  cout << "maxLen: " << res << endl;

  return 0;
}