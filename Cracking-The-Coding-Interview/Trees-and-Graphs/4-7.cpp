// You have 2 very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. Create an algorithm to decide if T2
// is a subtree of T1

#include<iostream>
using namespace std;

struct node {
    int data;
    node *right, *left;
};

void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root == NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createMinimalBst(root->left, arr, start, ind-1);
        createMinimalBst(root->right, arr, ind+1, end);
    }
}

bool identical(node* t1, node* t2) {
  if(t1 == NULL && t2 == NULL) return true;
  if(t1 != NULL && t2 != NULL) {
    if(t1->data == t2->data && identical(t1->left, t2->left) && identical(t1->right, t2->right)) {
      return true;
    }
  }
  return false;
}

bool isSubTree(node* t1, node* t2) {
  if(t2 == NULL) return true;
  if(t1 == NULL) return false;
  if(identical(t1, t2)) return true;

  return (isSubTree(t1->left, t2) || isSubTree(t1->right, t2));
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    // Bigger Tree
    int arr1[] = {1, 2, 3, 4};                  // Subtree
    node *root, *subRoot;
    root = subRoot = NULL;
    createMinimalBst(root, arr, 0, 8);
    createMinimalBst(subRoot, arr1, 0, 3);
    cout << isSubTree(root, subRoot);
    return 0;
}
