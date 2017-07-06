// Given a linked list, determine if it has a cycle in it.

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode * head) {
  if(head == NULL) return false;

  ListNode *slow = head;
  ListNode *fast = head;

  while(fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) { return true; }
    return false;
  }
}
