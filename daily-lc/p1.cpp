// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> roman;
    roman.insert({'I', 1});
    roman.insert({'V', 5});
    roman.insert({'X', 10});
    roman.insert({'L', 50});
    roman.insert({'C', 100});
    roman.insert({'D', 500});
    roman.insert({'M', 1000});
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      cout << "Count " << count << endl;
      char ch = s[i];
      if (i + 1 < s.size() && ch == 'I' &&
          (s[i + 1] == 'V' || s[i + 1] == 'V')) {
        count += (roman[s[i + 1]] - 1);
        i++;

      } else if (i + 1 < s.size() && ch == 'X' &&
                 (s[i + 1] == 'L' || s[i + 1] == 'C')) {
        count += (roman[s[i + 1]] - 10);
        i++;

      } else if (i + 1 < s.size() && ch == 'C' &&
                 (s[i + 1] == 'D' || s[i + 1] == 'M')) {
        count += (roman[s[i + 1]] - 100);
        i++;
      } else {
        count += roman[ch];
      }
    }
    return count;
  }
};

int main() {
  string s = "IX";
  Solution obj;
  int ans = obj.romanToInt(s);
  cout << ans;
}