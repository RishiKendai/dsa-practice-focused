// https://leetcode.com/problems/move-zeroes/submissions/1605091426/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int j = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        j = i;
        break;
      }
    }
    for (auto n : nums) cout << n << " ";

    cout << endl << j << endl;
    if (j != -1) {
      for (int i = j + 1; i < nums.size(); i++) {
        if (nums[i] != 0) {
          swap(nums[i], nums[j]);
          j++;
        }
      }
    }
  }
};

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution obj;
  obj.moveZeroes(nums);
  for (auto n : nums) cout << n << " ";
  return 0;
}
