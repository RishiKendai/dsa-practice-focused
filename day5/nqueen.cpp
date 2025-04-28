#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void solve(int col, vector<string>& board, vector<vector<string>>& ans,
             vector<int>& leftRow, vector<int>& lowerDiagonal,
             vector<int>& upperDiagonal, int n) {
    if (col == n) {
      ans.push_back(board);
      return;
    }

    for (int row = 0; row < n; row++) {
      if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
          upperDiagonal[n - 1 + col - row] == 0) {
        board[row][col] = 'Q';
        leftRow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiagonal[n - 1 + col - row] = 1;
        solve(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
        board[row][col] = '.';
        leftRow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiagonal[n - 1 + col - row] = 0;
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    // cout << board << endl;
    for (auto v : board) {
      cout << v;
    }
    string s(n, '.');
    for (int i = 0; i < n; i++) {
      board[i] = s;
    }
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0),
        upperDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
    return ans;
  }

  void solve2(int col, vector<string>& board, int& ans, vector<int>& leftRow,
              vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n) {
    if (col == n) {
      ans++;
      return;
    }

    for (int row = 0; row < n; row++) {
      if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
          upperDiagonal[n - 1 + col - row] == 0) {
        board[row][col] = 'Q';
        leftRow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiagonal[n - 1 + col - row] = 1;
        solve2(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
        board[row][col] = '.';
        leftRow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiagonal[n - 1 + col - row] = 0;
      }
    }
  }

  int solveNQueens2(int n) {
    int ans = 0;
    vector<string> board(n);
    // cout << board << endl;
    for (auto v : board) {
      cout << v;
    }
    string s(n, '.');
    for (int i = 0; i < n; i++) {
      board[i] = s;
    }
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0),
        upperDiagonal(2 * n - 1, 0);
    solve2(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
    return ans;
  }
};

int main() {
  int n = 4;
  Solution queen;
  //   vector<vector<string>> ans = queen.solveNQueens(n);
  int ans = queen.solveNQueens2(n);
  //   for (const auto& board : ans) {
  //     for (const auto& row : board) {
  //       cout << row << endl;
  //     }
  cout << ans << endl;
}