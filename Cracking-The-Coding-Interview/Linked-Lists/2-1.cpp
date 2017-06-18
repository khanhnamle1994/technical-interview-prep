// Write code to remove duplicates from an unsorted linked list

#include <iostream>
#include <map>
using namespace std;

typedef struct node{
    int val;
    node *next;
} node;

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i < n; ++i){
        node *nd = new node();
        nd->val = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

// The following code can traverse the list can be, if an element in the array
// is recorded in the already appeared, then delete the element.
// Time complexity O (n):

void removeDuplicate(node *head) {
  if(!head) return;
  node *cur = head;
  map<int, bool> map;
  map[head->val] = true;

  while(cur->next) {
    if(map.count(cur->next->val) == 0) {
      map[cur->next->val] = true;
      cur = cur->next;
    } else {
      node *temp = cur->next;
      cur->next = temp->next;
      delete temp;
    }
  }
}

void print(node *head) {
  while(head) {
    cout << head->val << " ";
    head = head->next;
  }
}

int main() {
  int n = 4;
  int a[] = {1, 2, 3, 2};
  node *head = init(a, n);
  removeDuplicate(head);
  print(head);
  return 0;
}
