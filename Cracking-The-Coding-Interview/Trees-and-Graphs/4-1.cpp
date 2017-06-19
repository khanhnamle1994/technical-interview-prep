// Implement a function to check if a tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree
// such that no 2 leaf nodes differ in distance from the root by more than 1.

#include <iostream>
#include <cmath>

using namespace std;

// Node Constructor
struct node {
    int data;
    node *right, *left;
};

// Function to insert nodes into the tree
void insertNode(node* &head, int data){
    if(head==NULL){
        node *p = new node;
        p->data = data;
        p->left = NULL;
        p->right = NULL;
        head = p;
        return;
    }
    if(data<=head->data){
        if(head->left==NULL){
            node *p = new node;
            p->data = data;
            p->left = NULL;
            p->right = NULL;
            head->left = p;
            return;
        }
        insertNode(head->left, data);
    }
    else{
        if(head->right==NULL){
            node *p = new node;
            p->data = data;
            p->left = NULL;
            p->right = NULL;
            head->right = p;
            return;
        }
        insertNode(head->right,data);
    }
}

// Function to calculate the balanced height of the tree
int balancedHeight(node* n) {
  if(n == NULL) return 0; // base case
  int h1 = balancedHeight(n->left); // height of left subtree
  int h2 = balancedHeight(n->right); // height of right subtree

  if(h1 == -1 || h2 == -1) return -1; // there is unbalanced subtree, so pass the -1 up
  if(abs(h1 - h2) > 1) return -1; // check if the height difference is 1 or less

  // assuming the tree is balanced, return the greater of the 2 heights
  if(h1 > h2) {
    return h1 + 1;
  } else {
    return h2 + 1;
  }
}

// Function to check if the tree is balanced
bool isBalanced(node* n) {
  if (balancedHeight(n) > -1) return true; // as long as the height is a valid entry, it is a balanced tree
  return false;
}

int main() {
    node *root;
    root = NULL;
    int arr[] = {1, 2, 3, 4, 6, 7};
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        insertNode(root, arr[i]);
    cout << isBalanced(root);
}
