#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int dup = n;
  int rev = 0;
  while (dup > 0) {
    rev = (rev * 10) + (dup % 10);
    dup /= 10;
  }
  if (n == rev) {
    cout << n << " is a palindrome";
  } else {
    cout << n << " is not a palindrome";
  }
}