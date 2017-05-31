// Write code to remove duplicates from an unsorted linked list

#include <iostream>
#include <cstring>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

bool hash[100];

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i < n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

/* If you can use additional storage space, we will open an array to save the
appearance of an element. For this situation, the best solution is of course
using the hash table, but it is very uncomfortable is the C + + standard is no
hash table (java there). Some people use extix hash_map, but after all, not in
the C + + standard, with the strange, do not change the environment will not run
 up (like Linux and Windows use is not the same). So, generally use an array to
 simulate just fine. However, here to pay attention to a problem, that is, the
 boundaries of the elements, such as the list is stored int variable. So, if
 there is a negative value, this method will not work. And if the maximum value
 of the element is very large, then the array should be very large, and most of
 the space in the array is not on, will cause a lot of space waste. */

// The following code can traverse the list can be, if an element in the array
// is recorded in the already appeared, then delete the element.
// Time complexity O (n):

void removeDuplicate(node *head) {
  if(head == NULL) return;
  node *p = head;
  node *q = head->next;
  hash[head->data] = true;
  while(q) {
    if(hash[q->data]) {
      node *t = q;
      p->next = q->next;
      q = p->next;
      delete t;
    } else {
      hash[q->data] = true;
      p = q;
      q = q->next;
    }
  }
}

// If you do not allow the use of temporary cache (that is, you can not use
// additional storage space), then the need for two pointers, when the first
// pointer to an element, the second pointer to the element behind it with the
// same elements to delete, time Complexity O (n ^ 2), the code is as follows:

void removeDuplicate1(node *head) {
  if(head == NULL) return;
  node *p, *q, *c = head;
  while(c) {
    p = c;
    q = c->next;
    int d = c->data;
    while(q) {
      if(q->data == d) {
        node *t = q;
        p->next = q->next;
        q = p->next;
        delete t;
      } else {
        p = q;
        q = q->next;
      }
    }
    c = c->next;
  }
}

void print(node *head) {
  while(head) {
    cout << head->data << " ";
    head = head->next;
  }
}

int main() {
  int n = 10;
  int a[] = {3, 2, 1, 3, 5, 6, 2, 6, 3, 1};
  memset(hash, false, sizeof(hash));
  node *head = init(a, n);
  removeDuplicate(head);
  // removeDuplicate1(head);
  print(head);
  return 0;
}
