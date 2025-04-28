// https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string repeat(string s, int times) {
    string res = "";
    while (times > 0) {
      res += s;
      times--;
    }
    return res;
  }
  void print(stack<char> store) {
    while (!store.empty()) {
      cout << store.top() << " ";
      store.pop();
    }
    cout << endl;
  }
  string decodeString(string s) {
    string curr_str = "";
    int num = 0;
    vector<string> stack;
    for (char ch : s) {
      if (ch == '[') {
        stack.push_back(curr_str);
        stack.push_back(to_string(num));
        curr_str = "";
        num = 0;
      } else if (ch == ']') {
        int times = stoi(stack.back());
        stack.pop_back();
        string prev_str = stack.back();
        stack.pop_back();
        curr_str = prev_str + repeat(curr_str, times);
      } else if (isdigit(ch)) {
        num = num * 10 + (ch - '0');
      } else {
        curr_str += ch;
      }
    }
    return curr_str;
  }
};

int main() {
  Solution obj;
  //   string s = "2[abc]3[cd]ef";
  string s = "3[a2[c]]";
  string ans = obj.decodeString(s);
  cout << ans;
  return 0;
}