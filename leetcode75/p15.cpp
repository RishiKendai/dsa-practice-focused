// https://leetcode.com/problems/max-consecutive-ones-iii/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int count = 0, maxCount = 0, i = 0;
    for (; i < nums.size(); i++) {
      if (nums[i] == 1)
        count++;
      else if (k > 0) {
        k--;
        count++;
      } else
        break;
    }
    maxCount = max(maxCount, count);
    cout << " i and l " << l << " " << i << endl;
    while (i < nums.size()) {
      if (nums[i] == 1) {
        i++;
        count++;
      } else if (k > 0) {
        i++;
        count++;
        k--;
      } else if (nums[l] == 0) {
        l++;
        k++;
        count--;
      } else {
        l++;
        count--;
      }
      maxCount = max(maxCount, count);
    }
    cout << " i and l " << i << " " << l << endl;
    return maxCount;
  }
};

int main() {
  //   vector<int> nums = {0, 0, 1, 1, 1, 0, 0};
  vector<int> nums = {0, 0, 1, 1};
  int k = 1;
  Solution obj;
  int ans = obj.longestOnes(nums, k);
  cout << ans << endl;
  return 0;
}