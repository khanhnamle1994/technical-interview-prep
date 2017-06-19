// Design an algorithm and write code to find the first common ancestor of 2 nodes in a binary tree. Avoid storing additional nodes in
// a data structure. This is not necessarily a binary search tree

#include<iostream>
using namespace std;

struct node {
    int data;
    node *right, *left;
};

void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
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

node* commonAncestor(node *root, node *root1, node *root2) {
  if(root == NULL)
      return NULL;
  if(root == root1 || root == root2)
      return root;

  node* left = commonAncestor(root->left, root1, root2);
  node* right = commonAncestor(root->right, root1, root2);

  if(left != NULL && right != NULL)
      return root;
  if(left == NULL && right == NULL)
      return NULL;

  return left != NULL ? left : right;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    node *ancestor = commonAncestor(root, root->left->left, root->left->right->right);
    cout << ancestor->data;
}
