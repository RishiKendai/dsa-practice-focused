#include <bits/stdc++.h>
using namespace std;

void allPermut(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans,
               bool freq[]) {
  if (ds.size() == nums.size()) {
    ans.push_back(ds);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (!freq[i]) {
      freq[i] = true;
      ds.push_back(nums[i]);
      allPermut(nums, ds, ans, freq);
      ds.pop_back();
      freq[i] = false;
    }
  }
}

void allPermutOpt(int index, vector<int>& nums, vector<vector<int>>& ans) {
  if (index == nums.size()) {
    ans.push_back(nums);
    return;
  }

  for (int i = index; i < nums.size(); i++) {
    swap(nums[i], nums[index]);
    allPermutOpt(index + 1, nums, ans);
    swap(nums[i], nums[index]);
  }
}

int main() {
  vector<vector<int>> ans = {};
  vector<int> nums = {1, 2, 3};
  bool freq[3] = {false};
  vector<int> ds;
  // allPermut(nums, ds, ans, freq);
  allPermutOpt(0, nums, ans);
  for (auto v : ans) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}