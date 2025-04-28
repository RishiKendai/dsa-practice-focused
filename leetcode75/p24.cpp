// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/?envType=study-plan-v2&envId=leetcode-75
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* second = nullptr;

    // Find Second Half
    while (fast && fast->next) {
      fast = fast->next->next;
      if (!fast) break;
      slow = slow->next;
    }
    second = slow->next;
    slow->next = nullptr;

    // Reverse the Second Half
    ListNode* nxt = second;
    ListNode* prev = nullptr;
    while (nxt) {
      ListNode* curr = nxt;
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
    }

    // Find twin
    int ans = 0;
    while (head) {
      int sum = head->val + prev->val;
      ans = max(ans, sum);
      head = head->next;
      prev = prev->next;
    }
    return ans;
  }
  void printVector(vector<int> nums) {
    cout << "___________________" << endl;
    for (int n : nums) {
      cout << n << " ";
    }
    cout << endl << "___________________" << endl;
  }
  void printList(ListNode* head) {
    while (head != nullptr) {
      cout << head->val;
      if (head->next) cout << " -> ";
      head = head->next;
    }
    cout << endl;
  }
};

void printList(ListNode* head) {
  while (head != nullptr) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  cout << "Original List: ";
  printList(head);

  Solution sol;
  int ans = sol.pairSum(head);
  cout << ans << endl;
  //   cout << "Reversed List: ";
  //   printList(reversedHead);

  return 0;
}