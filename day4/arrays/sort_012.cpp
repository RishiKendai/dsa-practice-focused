#include <bits/stdc++.h>
using namespace std;

void sort_012(vector<int> &nums) {
  int low = 0, mid = 0;
  int high = nums.size() - 1;
  while (mid <= high) {
    if (nums[mid] == 0) {
      swap(nums[mid], nums[low]);
      low++;
      mid++;
    } else if (nums[mid] == 1) {
      mid++;
    } else {
      swap(nums[mid], nums[high]);
      high--;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  sort_012(arr);
  for (auto num : arr) cout << num << " ";

  return 0;
}