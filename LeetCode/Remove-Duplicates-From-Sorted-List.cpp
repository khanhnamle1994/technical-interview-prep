// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

// Because the list has been sorted, duplicate nodes will be adjacent. Since the linked list pointer is unidirectional, so that each access
// node, the node determines whether a node is repeated, if so, after deleting a node. Since I want to keep a repeating node, if the node
// encountered after duplication, need not be considered a special case of the head pointer deleted.

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
   ListNode *deleteDuplicates(ListNode *head){
     if(!head) return head;
     ListNode *cur = head;
     while(cur->next){
       if(cur->val == cur->next->val){
         ListNode *temp = cur->next;
         cur->next = temp->next;
         delete temp;
       } else {
         cur = cur->next;
       }
     }
     return head;
   }
 }
