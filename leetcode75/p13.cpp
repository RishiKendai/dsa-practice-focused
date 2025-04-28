// https://leetcode.com/problems/maximum-average-subarray-i/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double maxAvg = 0;
    int l = 0;
    int r = k - 1;
    double sum = 0;

    if (k == nums.size()) {
      for (int i = l; i < nums.size(); i++) {
        sum += nums[i];
      }
    } else {
      for (int i = l; i <= r; i++) {
        sum += nums[i];
      }
    }
    maxAvg = sum / k;
    while (r < nums.size() - 1) {
      sum -= nums[l++];
      sum += nums[++r];
      maxAvg = max(maxAvg, sum / k);
    }

    return maxAvg;
  }
};

int main() {
  //   vector<int> nums = {1, 12, -5, -6, 50, 3};
  vector<int> nums = {5};
  int k = 1;
  Solution obj;
  float avg = obj.findMaxAverage(nums, k);
  cout << avg;
  return 0;
}