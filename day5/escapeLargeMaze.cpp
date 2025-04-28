#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  const int BOUND = 1e6;
  const int MAX_VISIT = 20000;
  bool dfs(int i, int j, vector<int>& target, set<pair<int, int>>& blockedSet,
           set<pair<int, int>>& vis, int di[], int dj[]) {
    if (i == target[0] && j == target[1]) return true;
    // cout << "i " << i << " j " << j << endl;
    if (vis.size() > MAX_VISIT) return true;

    for (int ind = 0; ind < 4; ind++) {
      int nextI = i + di[ind];
      int nextJ = j + dj[ind];
      pair<int, int> next = {nextI, nextJ};

      if (nextI >= 0 && nextJ >= 0 && nextI < BOUND && nextJ < BOUND &&
          !vis.count(next) && !blockedSet.count(next)) {
        vis.insert(next);
        if (dfs(nextI, nextJ, target, blockedSet, vis, di, dj)) return true;
      }
    }
    return false;
  }

  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                        vector<int>& target) {
    if (blocked.empty()) return true;
    set<pair<int, int>> blockedSet;
    set<pair<int, int>> vis, vis2;
    vis.insert({source[0], source[1]});
    for (auto& b : blocked) {
      blockedSet.insert({b[0], b[1]});
    }
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    vis2.insert({target[0], target[1]});
    return dfs(source[0], source[1], target, blockedSet, vis, di, dj) &&
           dfs(target[0], target[1], source, blockedSet, vis2, di, dj);
  }
};

int main() {
  //   vector<vector<int>> blocked = {{0, 1}, {1, 0}};
  //   vector<vector<int>> blocked = {};
  vector<vector<int>> blocked = {{10, 9}, {9, 10}, {10, 11}, {11, 10}};
  vector<int> source = {0, 0}, target = {10, 10};
  Solution obj;
  bool ans = obj.isEscapePossible(blocked, source, target);
  cout << ans << endl;
  return 0;
}