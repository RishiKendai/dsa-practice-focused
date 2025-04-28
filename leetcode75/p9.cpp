// https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int compress(vector<char>& chars) {
    int pt1 = 0, pt2 = 1, count = 1;
    char ch = chars[0];
    while (pt2 <= chars.size()) {
      if (pt2 == chars.size() || ch != chars[pt2]) {
        chars[pt1++] = ch;
        if (count > 1) {
          string countStr = to_string(count);
          copy(countStr.begin(), countStr.end(), chars.begin() + pt1);
          pt1 += countStr.size();
        }
        count = 0;
        if (pt2 < chars.size()) ch = chars[pt2];
      }
      count++;
      pt2++;
    }
    chars.resize(pt1);
    return chars.size();
  }
};

int main() {
  //   vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  //   vector<char> chars = {'a'};
  vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b',
                        'b', 'b', 'b', 'b', 'b', 'b'};
  Solution sol;
  int ans = sol.compress(chars);
  cout << ans << endl;
  for (auto v : chars) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}