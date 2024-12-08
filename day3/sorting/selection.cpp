#include <bits/stdc++.h>
using namespace std;

void selection(int arr[], int size) {
  for (int i = 0; i < size - 2; i++) {
    int min = i;
    for (int j = i; j < size - 1; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "before sorting: " << endl;
  for (int num : arr) cout << num << " ";
  cout << endl;
  selection(arr, n);
  cout << endl;
  cout << endl << "after sorting: " << endl;
  for (int num : arr) cout << num << " ";
}