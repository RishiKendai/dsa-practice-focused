// https://leetcode.com/problems/count-and-say/?envType=daily-question&envId=2025-04-18

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string str = "1";
    int freq = 0;
    string temp = "";
    for (int i = 1; i < n; i++) {
      freq = 0;
      char c = str[0];
      for (char ch : str) {
        if (ch != c) {
          temp += to_string(freq) + c;
          freq = 1;
          c = ch;
        } else
          freq++;
      }
      if (freq > 0) temp += to_string(freq) + c;
      str = temp;
      temp = "";
    }
    return str;
  }
};

int main() {
  int n = 1;
  Solution sol;
  string ans = sol.countAndSay(n);
  cout << ans;
  return 0;
}