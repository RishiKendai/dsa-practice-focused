// https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";
    auto gcd = [](int len1, int len2) {
      while (len2 != 0) {
        int temp = len1 % len2;
        len1 = len2;
        len2 = temp;
      }
      return len1;
    };

    int gcdLen = gcd(str1.length(), str2.length());
    return str1.substr(0, gcdLen);
  }
};

int main() {
  string str1 = "ABCABC", str2 = "ABC";
  Solution obj;
  string ans = obj.gcdOfStrings(str1, str2);
  cout << ans << endl;
  return 0;
}