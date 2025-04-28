// https://leetcode.com/problems/rabbits-in-forest/?envType=daily-question&envId=2025-04-20

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> map;
    int count = 0;
    for (int ans : answers) {
      if (ans == 0) {
        count++;
      } else {
        cout << "found " << map.count(ans) << " ans " << ans << endl;
        if (map.count(ans)) {
          map[ans];
          if (map[ans] == 0) {
            map.erase(ans);
          }
        } else {
          cout << "in else " << endl;
          count = count + ans + 1;
          map[ans] = ans;
          cout << count << endl;
        }
      }
    }
    return count;
  }
};

int main() {
  vector<int> answers = {10, 10, 10};
  Solution sol;
  int ans = sol.numRabbits(answers);
  cout << ans;
}