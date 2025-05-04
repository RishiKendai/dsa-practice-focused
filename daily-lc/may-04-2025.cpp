// https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
      auto h1 = std::hash<T1>{}(p.first);
      auto h2 = std::hash<T2>{}(p.second);
      return h1 ^ (h2 << 1);  // Combine the two hashes
    }
  };
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    std::unordered_map<std::pair<int, int>, int, PairHash> mp;
    int counter = 0;
    for (auto& domino : dominoes) {
      std::pair<int, int> p = {std::min(domino[0], domino[1]),
                               std::max(domino[0], domino[1])};

      if (mp.count(p) > 0) {
        counter += mp[p];
        mp[p]++;
      } else {
        mp[p] = 1;
      }
    }
    return counter;
  }
};
