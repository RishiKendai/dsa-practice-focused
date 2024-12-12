#include <bits/stdc++.h>
using namespace std;

void revArr(vector<int>& arr, int start, int end) {
  end--;
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

void rotate_right(vector<int>& nums, int n, int k) {
  k = k % nums.size();
  n = nums.size();
  // reverse(nums.begin(), nums.begin() + (n - k));
  // reverse(nums.begin() + (n - k), nums.begin() + nums.size());
  // reverse(nums.begin(), nums.begin() + nums.size());
  revArr(nums, 0, n - k);
  revArr(nums, n - k, n);
  revArr(nums, 0, n);
}
int main() {
  int d;
  int n;
  cin >> d >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  rotate_right(arr, n, d);
  cout << "After Rotating the k elements to right " << endl;
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}