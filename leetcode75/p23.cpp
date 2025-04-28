// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/?envType=study-plan-v2&envId=leetcode-75
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
class Solution {
  struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
  };

 public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode* ans = head;
    ListNode* ptr1 = head;
    ListNode* ptr2 = head;
    while (ptr2 != nullptr) {
      ptr2 = ptr2->next->next;
      if (ptr2->next == nullptr || ptr2 == nullptr) break;
      ptr1 = ptr1->next;
    }
    ptr1->next = ptr1->next->next;
    return ans;
  }
};

int main() {}