#include <bits/stdc++.h>
using namespace std;

void move_zeros(vector<int>& nums) {
  int j = -1;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      j = i;
      break;
    }
  }
  cout<<j<<endl;

  for (int i = j + 1; i < nums.size(); i++) {
    if (nums[i] != 0) {
      swap(nums[i], nums[j]);
      j++;
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
  move_zeros(arr);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}