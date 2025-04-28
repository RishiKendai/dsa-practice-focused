// https://leetcode.com/problems/unique-number-of-occurrences/?envType=study-plan-v2&envId=leetcode-75

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  //   bool uniqueOccurrences(vector<int>& arr) {
  //     unordered_set<int> unique;
  //     int occurrence[2001] = {0};
  //     for (int i = 0; i < arr.size(); i++) {
  //       occurrence[1000 + arr[i]]++;
  //     }
  //     for (int num : occurrence) {
  //       if (num > 0 && unique.count(num) > 0) return false;
  //       unique.insert(num);
  //     }
  //     return true;
  //   }
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> uniqueMap;
    for (int num : arr) {
      uniqueMap[num]++;
    }
    unordered_set<int> uniqueSet;
    for (auto num : uniqueMap) {
      cout << num.first << " " << num.second << endl;
    }
    for (auto num : uniqueMap) {
      cout << uniqueSet.count(num.second) << " : " << num.second << endl;
      if (uniqueSet.count(num.second) > 0) return false;
      uniqueSet.insert(num.second);
    }
    return true;
  }
};

int main() {
  //   vector<int> arr = {1, 2, 2, 1, 1, 3};
  vector<int> arr = {1, 2};
  Solution obj;
  bool ans = obj.uniqueOccurrences(arr);
  cout << ans;
  return 0;
}