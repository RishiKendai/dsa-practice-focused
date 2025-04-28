// https://leetcode.com/problems/count-largest-group/?envType=daily-question&envId=2025-04-23

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countLargestGroup(int n) {
    unordered_map<int, vector<int>> map;
    int max = 0, count = 0;
    for (int i = 1; i <= n; i++) {
      int sum = 0;
      int temp = i;
      while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
      }
      map[sum].push_back(i);
      cout << "temp " << sum << " i " << i << endl;
      if (map[sum].size() > max) {
        max = map[sum].size();
        count = 1;
      } else if (map[sum].size() == max) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  int n = 2;
  Solution sol;
  int ans = sol.countLargestGroup(n);
  cout << ans;
}