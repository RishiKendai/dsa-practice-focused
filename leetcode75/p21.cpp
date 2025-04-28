// https://leetcode.com/problems/number-of-recent-calls/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
 private:
  queue<int> q;

 public:
  RecentCounter() {}

  int ping(int t) {
    // 1. add it to queue.
    q.push(t);
    // 2. find current time_window of t.
    int time_window = t - 3000;
    // 3. look if first one fits in the time_window else remove it.
    // loop till the starting window fits the requests.
    while (!q.empty()) {
      if (q.front() >= time_window)
        break;
      else
        q.pop();
    }
    // 4. return the length of the queue.
    return q.size();
  }
};

int main() {
  RecentCounter* rc = new RecentCounter();
  cout << " Output | " << rc->ping(1) << endl;
  cout << " Output | " << rc->ping(100) << endl;
  cout << " Output | " << rc->ping(3001) << endl;
  cout << " Output | " << rc->ping(3002) << endl;
}