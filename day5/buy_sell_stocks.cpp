#include <bits/stdc++.h>
using namespace std;

int buy_sell_stocks(vector<int> stocks, int n) {
  int min_price = stocks[0];
  int max_profit = 0;
  for (int i = 0; i < n; i++) {
    int cost = stocks[i] - min_price;
    max_profit = max(cost, max_profit);
    min_price = min(min_price, stocks[i]);
  }
  return max_profit;
}

int main() {
  int n;
  cin >> n;
  vector<int> stocks;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    stocks.push_back(x);
  }
  int max_profit = buy_sell_stocks(stocks, n);
  cout << "Max Profit: " << max_profit;
  return 0;
}