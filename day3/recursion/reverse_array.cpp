#include <bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int start, int end) {
  if (start < end) {
    swap(arr[start], arr[end]);
    reverse_array(arr, start + 1, end - 1);
  }
}

int main() {
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) cin >> arr[i];
  reverse_array(arr, 0, size - 1);
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
}