// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    int pt1 = 0, pt2 = 0;
    string ans = "";
    int order = 0;
    while (pt1 < len1 && pt2 < len2) {
      if (order++ % 2 == 0) {
        ans += word1[pt1++];
      } else {
        ans += word2[pt2++];
      }
    }

    while (pt1 < len1) {
      ans += word1[pt1++];
    }

    while (pt2 < len2) {
      ans += word2[pt2++];
    }

    return ans;
  }
};

int main() {
  string word1 = "ab", word2 = "pqrs";
  Solution obj;
  string ans = obj.mergeAlternately(word1, word2);
  cout << "ANS: " << ans << endl;
}