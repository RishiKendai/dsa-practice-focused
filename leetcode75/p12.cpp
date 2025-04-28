// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int maxContainer = 0;
    while (i < j) {
      int area = min(height[i], height[j]) * (j - i);
      maxContainer = max(maxContainer, area);
      if (height[i] < height[j])
        i++;
      else
        j--;
    }
    return maxContainer;
  }
};

int main() {
  // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  // vector<int> height = {1, 5, 2, 8, 2, 2, 4, 4, 4, 5, 8};
  vector<int> height = {1, 1};
  Solution obj;
  int ans = obj.maxArea(height);
  cout << ans;
  return 0;
}