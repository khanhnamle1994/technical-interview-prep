// Given preorder and inorder traversal of a tree, construct the binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    int findId(int n, vector<int> &inorder){
        for (int i=0;i<inorder.size();i++){
            if (inorder[i] == n) return i;
        }
    }

    TreeNode* bst(vector<int> &preorder, int &mid, vector<int> &inorder, int st, int ed){
        if (st>ed || preorder.size()==mid){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[mid]);
        int idx = findId(preorder[mid], inorder);
        mid++;
        root->left = bst(preorder, mid, inorder, st, idx-1);
        root->right = bst(preorder, mid, inorder, idx+1, ed);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int mid = 0;
        return bst(preorder, mid, inorder, 0, inorder.size());
    }
};
