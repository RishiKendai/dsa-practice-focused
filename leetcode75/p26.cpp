// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<pair<int, int>, int>> q;
    int row = maze.size();
    int col = maze[0].size();
    q.push({{entrance[0], entrance[1]}, 0});
    maze[entrance[0]][entrance[1]] = '+';
    while (!q.empty()) {
      int r = q.front().first.first;
      int c = q.front().first.second;
      int t = q.front().second;

      cout << "q: " << r << c << t << endl;
      cout << row << " " << col << endl;

      q.pop();
      //   Neighbour directions
      int drow[] = {+1, -1, 0, 0};
      int dcol[] = {0, 0, +1, -1};

      for (int i = 0; i < 4; i++) {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];
        if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col &&
            maze[nrow][ncol] == '.') {
          if (nrow == 0 || nrow == row - 1 || ncol == 0 || ncol == col - 1) {
            return t+1;
          } else {
            q.push({{nrow, ncol}, t + 1});
            maze[nrow][ncol] = '+';
          }
        }
      }
    }
    return -1;
  }
};

int main() {
  vector<vector<char>> maze = {
      {'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
  vector<int> entrance = {1, 0};
  Solution sol;
  int ans = sol.nearestExit(maze, entrance);
  cout << ans;
  return 0;
}