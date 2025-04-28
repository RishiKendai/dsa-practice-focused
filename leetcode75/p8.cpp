// https://leetcode.com/problems/increasing-triplet-subsequence/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX;
    int second = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= first)
        first = nums[i];
      else if (nums[i] <= second)
        second = nums[i];
      else
        return true;
    }
    return false;
  }
};