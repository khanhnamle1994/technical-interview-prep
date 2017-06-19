// Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height

#include<iostream>
using namespace std;

struct node {
    int data;
    node *right, *left;
    node(int x): data(x), left(NULL), right(NULL) {}
};

/* Algorithm:
1. Initialize start = 0, end = length of the array - 1
2. Set mid = (start+end)/2
3. Create a tree node with mid as root (lets call it A).
4. Recursively do following steps:
   a). Calculate mid of left subarray and make it root of left subtree of A.
   b). Calculate mid of right subarray and make it root of right subtree of A. */

void createBST(node* &root, int arr[], int start, int end) {
  if(start > end)
      return;

  if(root == NULL) {
    int mid = start + (end - start) / 2;
    root = new node(arr[mid]);

    createBST(root->left, arr, start, mid - 1);
    createBST(root->right, arr, mid + 1, end);
  }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createBST(root, arr, 0, 8);
    cout << root->left->data << " " << root->data << " " << root->right->data << '\n';
}
