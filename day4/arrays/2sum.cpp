#include <bits/stdc++.h>
using namespace std;

pair<int, int> two_sum(vector<int> &nums, int target) {
  unordered_map<int, int> sumMap;
  for (int i = 0; i < nums.size(); i++) {
    int needed = target - nums[i];
    if (sumMap.find(needed) != sumMap.end()) {
        
      return {sumMap[needed], i};
    }
    sumMap[nums[i]] = i;
  }
}

int main() {
  int n;
  cin >> n;
  int target;
  cin >> target;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  pair<int, int> result = two_sum(arr, target);
  cout << result.first << " " << result.second << endl;
  //   for (auto num : arr) cout << num << " ";

  return 0;
}