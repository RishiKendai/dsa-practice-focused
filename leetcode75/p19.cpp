// https://leetcode.com/problems/asteroid-collision/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void print(vector<int>& nums) {
    cout << "------------------------" << endl;
    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl << "------------------------" << endl;
  }
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for (int num : asteroids) {
      if (ans.empty() || num > 0)
        ans.push_back(num);
      else {
        if (ans.back() > 0) {  // Current -ve
          while (!ans.empty()) {
            cout << "loop " << endl;
            print(ans);
            if (ans.back() == -num) {
              cout << "if" << endl;
              ans.pop_back();
            } else if (ans.back() < -num) {
              cout << "else if" << endl;
              ans.pop_back();
            } else {
              cout << "here " << endl;
              ans.push_back(num);
              break;
            }
          }
        } else
          ans.push_back(num);
      }
    }
    return ans;
  }
};

int main() {
  // vector<int> asteroids = {5, 10, -5};
  // vector<int> asteroids = {8, -8};
  // vector<int> asteroids = {10, 2, -5};
  // vector<int> asteroids = {-2, -1, 1, 2};
  // vector<int> asteroids = {-2, -2, 1, -2};
  // vector<int> asteroids = {-2, 1, -2, -1};
  // vector<int> asteroids = {-2, 1, 1, -2};
  vector<int> asteroids = {-2, 2, 1, -2};
  // vector<int> asteroids = {1, -1, -2, -2};
  Solution obj;
  vector<int> ans = obj.asteroidCollision(asteroids);
  cout << "-------------" << endl;
  for (int num : ans) cout << num << " ";
  cout << endl << "-------------" << endl;
  return 0;
}