// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
// Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become
// 1 -> 2 -> 4 after calling your function.

/* Analysis:

To solve this problem, the key point is "overwrite" !

Usually we are thinking "skip" the node we want to delete by:
1 -> 2 -> 3 -> 4 -> Null, delete 3, we have:
1 -> 2--------> 4 -> Null.

However in this problem, the previous node is unknown.
So, what we should do is to overwrite the node  "3" by node "4":
1 -> 2 -> 3 -> 4->Null, delete 3, we have:
1 -> 2 -> 4->Null.

Just pay attention to the case that the node is the last node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 class Solution {
 public:
   void deleteNode(ListNode* node){
     if(node->next) {
       node->val = node->next->val;
       node->next = node->next->next;
     } else {
       node = NULL;
     }
   }
 }
