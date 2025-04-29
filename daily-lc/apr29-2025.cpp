// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2025-04-29
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    long long int max_num = *max_element(nums.begin(), nums.end()), count = 0;
    long long int left = 0, right = 0, ans = 0;
    while (right < nums.size()) {
      if (nums[right] == max_num) count++;

      while (count >= k) {
        if (nums[left] == max_num) count--;
        left++;
        ans += nums.size() - right;
      }
      right++;
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 3, 2, 3, 3};
  int k = 2;
  Solution sol;
  int ans = sol.countSubarrays(nums, k);
  cout << ans << endl;
  return 0;
}