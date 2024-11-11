#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  cin >> num;
  int sum = 0;
  int dup = num;
  while (dup > 0) {
    int digit = dup % 10;
    sum += (digit * digit * digit);
    dup /= 10;
  }
  if (num == sum) {
    cout << num << " is an armstrong number";
  } else {
    cout << num << " is not an armstrong number";
  }
}