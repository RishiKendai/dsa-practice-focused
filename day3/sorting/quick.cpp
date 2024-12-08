#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right) {
  int pivot = arr[left];
  int i = left;
  int j = right;

  while (i < j) {
    while (i <= right - 1 && arr[i] <= pivot) i++;
    while (j >= left + 1 && arr[j] > pivot) j--;
    if (i < j) swap(arr[i], arr[j]);
  }
  swap(arr[left], arr[j]);
  return j;
}

void quick(vector<int> &arr, int low, int high) {
  if (low >= high) return;

  int pivot = partition(arr, low, high);
  quick(arr, low, pivot - 1);
  quick(arr, pivot + 1, high);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  quick(arr, 0, n - 1);
  cout << endl << "after sort" << endl;
  for (int num : arr) {
    cout << num << " ";
  }

  return 0;
}