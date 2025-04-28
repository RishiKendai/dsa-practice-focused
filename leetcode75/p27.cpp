// https://leetcode.com/problems/house-robber/submissions/1615793515/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int dp(vector<int>& nums, int index, vector<int>& memo) {
    if (index == 0) return nums[0];
    if (index < 0) return 0;
    if (memo[index] != -1) return memo[index];
    int left = dp(nums, index - 1, memo) + 0;
    int right = dp(nums, index - 2, memo) + nums[index];
    memo[index] = max(left, right);
    return max(left, right);
  }

  int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    int sum = dp(nums, nums.size() - 1, memo);
    return sum;
  }
};

int main() {
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  //   vector<int> nums = {1, 2, 3, 1};
  Solution sol;
  int ans = sol.rob(nums);
  cout << ans;
  return ans;
}