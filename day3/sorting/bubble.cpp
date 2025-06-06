#include <bits/stdc++.h>
using namespace std;

void bubble(int arr[], int size) {
  for (int i = size - 1; i >= 0; i--) {
    int didSwap = 0;
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        didSwap = 1;
      }
    }
    if (didSwap == 0) break;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bubble(arr, n);
  cout << "after swap: " << endl;
  for (int num : arr) cout << num << " ";
  return 0;
}