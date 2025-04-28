// https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++) {
      res[i] = prefix;
      prefix *= nums[i];
    }
    int postfix = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      res[i] *= postfix;
      postfix *= nums[i];
    }
    return res;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  return 0;
}