// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03
#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  int tryMatching(int number, vector<int>& tops, vector<int>& bottoms) {
    int count = 0;
    for (int i = 0; i < tops.size(); i++) {
      if (number == tops[i])
        continue;
      else if (number == bottoms[i])
        count++;
      else
        return INT_MAX;
    }
    return count;
  }

 public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int min_rotate = INT_MAX;
    for (int i = 1; i <= 6; i++) {
      int top_count = tryMatching(i, tops, bottoms);
      int bottom_count = INT_MAX;
      if (top_count != INT_MAX) bottom_count = tryMatching(i, bottoms, tops);
      min_rotate = min(min_rotate, min(top_count, bottom_count));
    }
    return min_rotate == INT_MAX ? -1 : min_rotate;
  }
};