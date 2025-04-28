// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/submissions/1609971570/?envType=daily-question&envId=2025-04-17

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countPairs(vector<int>& nums, int k) {
    int ans = 0;
    if (nums.size() == 1) return ans;
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        cout << " i | j " << i << " " << j << endl;
        cout << " [i] | [j] " << nums[i] << " " << nums[j] << endl;
        cout << boolalpha << (nums[i] == nums[j]) << endl;
        cout << "___________________" << endl;
        if (nums[i] == nums[j] && (i * j) % k == 0) {
          ans++;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {3, 2, 3, 10, 2, 9, 10, 2, 6, 8, 3, 8, 1, 9, 10, 6, 4, 4};
  int k = 1;
  int ans = sol.countPairs(nums, k);
  cout << ans;
}