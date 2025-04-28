// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int i = 0, l = 0, count = 0, maxCount = 0, zeros = 1;
    // while (i < nums.size()) {
    //   cout << "-----------------------------" << endl;
    //   cout << "Before: i " << i << "| l " << l << "| Count " << count <<
    //   endl; if (nums[i] != 0) {
    //     count++;
    //     i++;
    //   } else if (ignore > 0) {
    //     ignore--;
    //     i++;
    //   } else if (nums[l] != 0) {
    //     count--;
    //     l++;
    //   } else if (nums[l] == 0) {
    //     ignore = 1;
    //     l++;
    //   }
    //   maxCount = max(maxCount, count);
    //   cout << "After: i " << i << "| l " << l << "| Count " << count << endl;
    // }
    // return maxCount == nums.size() ? maxCount - 1 : maxCount;
    while (i < nums.size()) {
      if (nums[i] == 0) zeros--;
      
    }
  }
};

int main() {
  //   vector<int> nums = {1, 1, 0, 0, 1, 0, 1, 0, 0, 1}; // 2
  //   vector<int> nums = {1, 1, 1};  // 2
  //   vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1}; // 5
  vector<int> nums = {1, 1, 0, 1};  // 3
  Solution obj;
  int ans = obj.longestSubarray(nums);
  cout << ans;
  return 0;
}