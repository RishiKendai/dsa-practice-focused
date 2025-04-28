// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());
    vector<bool> ans;
    for (int i = 0; i < candies.size(); i++) {
      if ((candies[i] + extraCandies) >= maxCandies)
        ans.push_back(true);
      else
        ans.push_back(false);
    }
    return ans;
  }
};

int main() {
  vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;
  Solution obj;
  vector<bool> ans = obj.kidsWithCandies(candies, extraCandies);
  return 0;
}