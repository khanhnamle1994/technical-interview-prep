// Given a singly linked list, return a random node's value from the linked list. Each node must have the same
// probability of being chosen.

/* Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom(); */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* head;

/** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution(ListNode* head) {
  this->head = head;
}

/** Returns a random node's value. */
int getRandom() {
  int res = head->val;
  ListNode* node = head->next;
  int i = 2;

  while(node){
      int j = rand()%i;
      if(j==0)
          res = node->val;
      i++;
      node = node->next;
  }
  return res;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
