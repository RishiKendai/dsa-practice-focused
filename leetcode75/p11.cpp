// https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Method 1: 2-pointer
  // bool isSubsequence(string s, string t) {
  //     int i = 0;
  //     int j = 0;
  //     while (i < s.size() && j < t.size()) {
  //         if (s[i] == t[j])
  //             i++;
  //         j++;
  //     }
  //     return i == s.size();
  // }
  unordered_map<char, vector<int>> indexMap;
  void prePopulateString(string& t) {
    for (int i = 0; i < t.size(); i++) {
      indexMap[t[i]].push_back(i);
    }
  }
  bool isSubsequence(string s, string t) {
    int prevPos = -1;
    prePopulateString(t);
    for (char c : s) {
      if (indexMap.find(c) == indexMap.end()) return false;
      auto it = upper_bound(indexMap[c].begin(), indexMap[c].end(), prevPos);
      if (it == indexMap[c].end()) return false;
      prevPos = *it;
    }
    return true;
  }
};

int main() {
  string s = "abc", t = "ahbgdc";
  Solution obj;
  bool ans = obj.isSubsequence(s, t);
  cout << ans;
  return 0;
}