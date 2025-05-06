// https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int newVal = nums[nums[i]] % n;
      nums[i] += newVal * n;
    }
    for (int i = 0; i < n; i++) {
      nums[i] /= n;
    }

    return nums;
  }
};