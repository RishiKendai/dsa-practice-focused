// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }
  int maxVowels(string s, int k) {
    int l = 0;
    int count = 0;
    int maxCount = 0;
    int r = k;
    for (int i = 0; i < r; i++) {
      if (isVowel(s[i])) count++;
    }
    maxCount = count;
    while (r < s.size()) {
      if (isVowel(s[l++])) count--;
      if (isVowel(s[r++])) count++;
      maxCount = max(count, maxCount);
    }
    return maxCount;
  }
};

int main() {
  string s = "abciiidef";
  int k = 3;
  Solution obj;
  int ans = obj.maxVowels(s, k);
  cout << ans << endl;
  return 0;
}