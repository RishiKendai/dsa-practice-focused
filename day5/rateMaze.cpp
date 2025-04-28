#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void solve(int i, int j, vector<vector<int>>& a, int n, vector<string>& ans,
             string move, vector<vector<int>>& vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      cout << "move " << move;
      ans.push_back(move);
      return;
    }

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nextI = i + di[ind];
      int nextJ = j + dj[ind];
      if (nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n &&
          a[nextI][nextJ] == 1 && !vis[nextI][nextJ]) {
        vis[nextI][nextJ] = 1;
        solve(nextI, nextJ, a, n, ans, move + dir[ind], vis, di, dj);
        vis[nextI][nextJ] = 0;
      }
    }
  }
  vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
  }
};

int main() {
  Solution obj;
  vector<vector<int>> m = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1},
  };
  vector<string> ans = obj.findPath(m, 4);
  for (auto v : ans) {
    cout << v << endl;
  }
  return 0;
}