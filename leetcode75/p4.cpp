// https://leetcode.com/problems/can-place-flowers/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int i = 0;
    while (i < flowerbed.size() && n > 0) {
      if (flowerbed[i] == 0) {
        if ((i - 1 < 0 || flowerbed[i - 1] == 0) &&
            (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0)) {
          flowerbed[i] = 1;
          n--;
        }
      }
      i++;
    }
    for (auto i : flowerbed) {
      cout << i << " ";
    }
    cout << endl << n << endl;
    return n == 0;
  }
};

int main() {
  Solution obj;
  vector<int> flowerbed = {1, 0, 0, 0, 1, 0, 0};
  int n = 2;
  bool ans = obj.canPlaceFlowers(flowerbed, n);
  cout << "ans: " << ans << endl;
  return 0;
}