#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  cin >> num;
  int n = num;
  int rev = 0;
  while (n > 0) {
    rev = (rev * 10) + (n % 10);
    n /= 10;
  }
  cout << "Reverse of " << num << " is: " << rev;
}