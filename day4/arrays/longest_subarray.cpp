#include <bits/stdc++.h>
using namespace std;

// For positive & negative
int better(vector<long long>& nums, int k) {
  map<long long, int> preSum;
  int maxLen = 0;
  long long sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if (sum == k) {
      maxLen = max(maxLen, i + 1);
    }
    long long rem = sum - k;
    if (preSum.find(rem) != preSum.end()) {
      int len = i - preSum[rem];
      maxLen = max(maxLen, len);
    }
    if (preSum.find(sum) == preSum.end()) {
      preSum[sum] = i;
    }
  }
  return maxLen;
}

// For positive & zeros
int optimal(vector<long long>& nums, int k) {
  int left = 0;
  int right = 0;
  long long sum = nums[0];
  int maxLen = 0;
  int n = nums.size();
  while (right < n) {
    while (left <= right && sum > k) {
      sum -= nums[left];
      left++;
    }
    if (sum == k) {
      maxLen = max(maxLen, right - left + 1);
    }
    right++;
    if (right < n) sum += nums[right];
  }
  return maxLen;
}

int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<long long> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  //   int maxLen = better(arr, k);
  int maxLen = optimal(arr, k);
  cout << maxLen << endl;
  return 0;
}