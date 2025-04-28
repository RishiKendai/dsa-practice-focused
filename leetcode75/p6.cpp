// https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    string ans = "";
    int i = s.length() - 1, j = s.length() - 1;
    while (i >= 0) {
      if ((i == 0 || s[i - 1] == ' ') && i <= j) {
        if (s.substr(i, j - i + 1) != " ") {
          ans += s.substr(i, j - i + 1) + " ";
          j = i - 1;
        }
      }
      if (j > 0 && s[j] == ' ') j--;
      i--;
    }
    return ans.erase(ans.find_last_not_of(" \t\n\r\f\v") + 1);
  }
};

int main() {
  string s = "the sky is blue";
  //   string s = "  hello world ";
  // string s = "a good  a example";
  Solution obj;
  string ans = obj.reverseWords(s);
  cout << ans << endl;
  return 0;
}