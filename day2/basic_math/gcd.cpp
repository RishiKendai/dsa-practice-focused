#include <bits/stdc++.h>
using namespace std;

int main() {
  int num1;
  int num2;
  cin >> num1 >> num2;
  int a = num1;
  int b = num2;
  while (a > 0 && b > 0) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }
  cout << a << " " << b << endl;
  if (a == 0) {
    cout << "GCD of " << num1 << " and " << num2 << " is " << b;
  } else {
    cout << "GCD of " << num1 << " and " << num2 << " is " << a;
  }
}