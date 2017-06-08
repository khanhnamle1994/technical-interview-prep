// Sort a linked list using insertion sort.

/* Analysis:
The general idea is insert the current element A[i] into the proper position from A[0]...A[i-1], and A[0]...A[i-1] which is already sorted.

In this problem, we can use the same idea and linked list provides a more efficient way for insertion.  Details can be found in the code
below. Note that after the insertion, the position of P is unchanged but should not provide another p=p->next operation. */

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
     ListNode* insertionSortList(ListNode* head) {
         if (!head){ return NULL; }
         ListNode *p = new ListNode(0);
         p->next = head;
         head = p;
         ListNode *q;

         while (p->next != NULL){
             q = head;
             bool flag = false;
             while (q != p){
                 if (q->next->val > p->next->val){
                     ListNode* tmp1 = p->next;
                     p->next = p->next->next;
                     tmp1->next = q->next;
                     q->next = tmp1;
                     flag = true;
                     break;
                 } else {
                     q = q->next;
                 }
             }
             if (!flag){
                 p = p->next;
             }
         }
         return head->next;
     }
 };
