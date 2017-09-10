// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root) {
      pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
      TreeNode *tmpNode = myStack.top();
      myStack.pop();
      pushAll(tmpNode->right);
      return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
      while (node != NULL) {
        myStack.push(node);
        node = node->left;
      }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
