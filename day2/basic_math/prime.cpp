#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num) {
  int counter = 0;
  for (int i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      counter++;
      if ((num / i) != i) {
        counter++;
      }
    }
  }
  cout << counter << endl;
  return counter == 2;
}
int main() {
  int n;
  cin >> n;
  bool num_is_prime = is_prime(n);
  if (num_is_prime) {
    cout << n << " is a prime number";
  } else {
    cout << n << " is a not a prime number";
  }
}