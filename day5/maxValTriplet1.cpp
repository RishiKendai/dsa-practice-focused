#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }
    long long ans = 0;
    int indexi = 0;
    int indexj = 1;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      // for I
      if (i < n - 2 && nums[i] > nums[indexi]) indexi = i;
      // for J
      //   cout << i << ":i- " << indexi << ":indexi- " << n - 1 << ":n-1- "
      //        << indexj << ":indexj- " << nums[i] << ":nums[i]- " <<
      //        nums[indexj]
      //        << ":nums[indexj]- " << endl;

      if (i > indexi && i < n - 1 && nums[i] < nums[indexj])
        indexj = i;
      else if (indexj < indexi)
        indexj = i + 1;
      // for K
      cout << "----------------------" << endl;
      cout << "i " << indexi << " j " << indexj << endl;
      if (i >= indexj) {
        for (int k = i+1; k < n; k++) {
          cout << "-------------------------------------" << endl;
          cout << "i " << indexi << " j " << indexj << " k " << k << endl;
          cout << indexi << " " << indexj << " " << " " << k << endl;
          long long curr = ((nums[indexi] - nums[indexj]) * 1LL) * nums[k];
          cout << "curr " << curr << " " << ans << endl;
          ans = max(ans, curr);
        }
      }
    }
    return ans;
  }
};
// 999999000000

int main() {
  //   vector<int> nums = {8, 6, 3, 13, 2, 12, 19, 5, 19, 6, 10, 11, 9};
  //   vector<int> nums = {6, 11, 12, 12, 7, 9, 2, 11, 12, 4, 19, 14, 16, 8,
  //   16};
  //   vector<int> nums = {15, 14, 17, 13, 18, 17, 10, 19, 2, 20, 12, 9};
  vector<int> nums = {10, 13, 6, 2};
  Solution obj;
  long long ans = obj.maximumTripletValue(nums);
  cout << "Answer: " << ans << endl;
  return 0;
}




class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;

    vector<int> prefixMax(n, 0);
    vector<int> suffixMax(n, 0);

    // Build prefix max: max to the left of j
    prefixMax[0] = nums[0];
    for (int i = 1; i < n; ++i) prefixMax[i] = max(prefixMax[i - 1], nums[i]);

    // Build suffix max: max to the right of j
    suffixMax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
      suffixMax[i] = max(suffixMax[i + 1], nums[i]);

    long long ans = 0;
    for (int j = 1; j < n - 1; ++j) {
      long long diff = 1LL * (prefixMax[j - 1] - nums[j]);
      long long val = diff * suffixMax[j + 1];
      ans = max(ans, val);
    }

    return max(ans, 0LL);
  }
};
