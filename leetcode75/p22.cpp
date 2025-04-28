// https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string predictPartyVictory(string senate) {
    int r_plus = 0, d_plus = 0, r_minus = 0, d_minus = 0, n = senate.size();
    if (n == 1) {
      if (senate == "R")
        return "Radiant";
      else
        return "Dire";
    }
    while (n > 0) {
      r_plus = 0;
      d_plus = 0;
      for (char& ch : senate) {
        if (ch == 'D') {
          if (d_minus < 0) {
            d_minus++;
            ch = 'X';
            continue;
          }
          if (d_minus >= 0) {
            r_minus--;
            n--;
          }
          d_plus++;
        } else if (ch == 'R') {
          if (r_minus < 0) {
            r_minus++;
            ch = 'X';
            continue;
          }
          if (r_minus >= 0) {
            d_minus--;
            n--;
          }
          r_plus++;
        } else {
          continue;
        }
      }
    }
    cout << "r | d " << r_plus << " " << d_plus << endl;
    if (r_plus > d_plus) return "Radiant";
    return "Dire";
  }
};

int main() {
  Solution* obj = new Solution();
    // string senate = "RRDDD";
    string senate = "DRDRDR";
  //   string senate = "D";
  // string senate = "R";
  // string senate = "DR";
    // string senate = "DRRDRDRDRDDRDRDR";
//   string senate = "DDDRRRRR";
  string ans = obj->predictPartyVictory(senate);
  cout << "ans: " << ans;
  return 0;
}