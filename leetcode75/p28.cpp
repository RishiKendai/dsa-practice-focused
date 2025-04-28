// https://leetcode.com/problems/unique-paths/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int dp(int i, int j, int m, int n, vector<vector<int>>& memo2) {
    if (i == m && j == n) return 1;
    if (i < 0 || j < 0 || i >= m || j >= n) return 0;
    cout << " i: j " << i << " " << j << endl;
    if (memo2[i][j] != -1) return memo2[i][j];
    int left = dp(i, j + 1, m, n, memo2);
    int right = dp(i + 1, j, m, n, memo2);
    memo2[i][j] = left + right;
    cout << "---------------------------" << endl;
    cout << "left | right " << left << " " << right << endl;
    cout << "---------------------------" << endl;
    return left + right;
  }

  int uniquePaths(int m, int n) {
    vector<vector<int>> memo2(m, vector<int>(n, -1));
    return dp(0, 0, m, n, memo2);
  }
};

int main() {
  int m = 3;
  int n = 7;
  Solution sol;
  int ans = sol.uniquePaths(m, n);
  cout << ans;
}