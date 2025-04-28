#include "./headers.h"
using namespace std;

vector<int> alternateNumbers(vector<int> &nums) {
  int n = nums.size();
  vector<int> posArr, negArr;
  for (int num : nums) {
    if (num < 0) {  // negative
      negArr.push_back(num);
    } else {  // positive
      posArr.push_back(num);
    }
  }
  if (posArr.size() > negArr.size()) {
    for (int i = 0; i < negArr.size(); i++) {
      nums[i * 2] = posArr[i];
      nums[i * 2 + 1] = negArr[i];
    }

    int index = negArr.size() * 2;
    for (int i = negArr.size(); i < posArr.size(); i++) {
      nums[index++] = posArr[i];
    }
  } else {
    for (int i = 0; i < posArr.size(); i++) {
      nums[i * 2] = posArr[i];
      nums[i * 2 + 1] = negArr[i];
    }

    int index = posArr.size() * 2;
    for (int i = posArr.size(); i < negArr.size(); i++) {
      nums[index++] = negArr[i];
    }
  }
  return nums;
}

vector<int> rearrangeArray(vector<int> &nums) {
  int n = nums.size();
  vector<int> ans(n, 0);
  int pos = 0, neg = 1;

  for (int num : nums) {
    if (num < 0) {  // negative
      ans[neg] = num;
      neg += 2;
    } else {  // positive
      ans[pos] = num;
      pos += 2;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  //   vector<int> output = rearrangeArray(nums);
  vector<int> output = alternateNumbers(nums);
  cout << "Output:";
  for (int i : output) {
    cout << " " << i;
  }
  return 0;
}
