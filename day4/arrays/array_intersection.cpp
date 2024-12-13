#include <bits/stdc++.h>
using namespace std;

vector<int> array_union(vector<int>& nums1, vector<int>& nums2) {
  vector<int> res;
  int n = 0;
  int m = 0;

  int nums1_len = nums1.size();
  int nums2_len = nums2.size();

  while (n < nums1_len && m < nums2_len) {
    if (nums1[n] < nums2[m]) {
      n++;
    } else if (nums2[m] < nums1[n]) {
      m++;
    } else {
      res.push_back(nums1[n]);
      n++;
      m++;
    }
  }

  return res;
}
int main() {
  int n;
  int m;
  cin >> n;
  vector<int> arr1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr1.push_back(x);
  }
  vector<int> arr2;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    arr2.push_back(x);
  }

  vector<int> res = array_union(arr1, arr2);

  for (auto num : res) cout << num << " ";
  cout << endl;

  return 0;
}