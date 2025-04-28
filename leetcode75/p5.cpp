// https://leetcode.com/problems/reverse-vowels-of-a-string/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    int left = 0, right = s.length();
    while (left < right) {
      char leftChar = tolower(s[left]);
      char rightChar = tolower(s[right]);
      if (leftChar != 'a' && leftChar != 'e' && leftChar != 'i' &&
          leftChar != 'o' && leftChar != 'u') {
        left++;
        continue;
      }
      if (rightChar != 'a' && rightChar != 'e' && rightChar != 'i' &&
          rightChar != 'o' && rightChar != 'u') {
        right--;
        continue;
      }
      swap(s[left++], s[right--]);
    }
    return s;
  }
};

int main() {
  string s = "IceCreAm";
  Solution obj;
  string ans = obj.reverseVowels(s);
  cout << ans << endl;
  return 0;
}