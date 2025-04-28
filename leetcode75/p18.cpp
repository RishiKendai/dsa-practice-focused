// http://leetcode.com/problems/equal-row-and-column-pairs/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans = 0;
    map<vector<int>, int> rows;
    for (int i = 0; i < n; i++) rows[grid[i]]++;

    for (int i = 0; i < n * n; i++) {
      int row = i / n;
      int col = i % n;
      if (row < col) swap(grid[row][col], grid[col][row]);
    }
    for (auto row : grid)
      if (rows[row]) ans += rows[row];

    return ans;
  }
};

int main() {
  vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  Solution obj;
  int ans = obj.equalPairs(grid);
  cout << ans;
  return 0;
}