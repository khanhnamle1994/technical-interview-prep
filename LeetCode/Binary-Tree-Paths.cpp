// Given a binary tree, return all root-to-leaf paths.

/* Analysis:
This is a classic depth first search problem.
The idea is:
1> Starting from the root node (remember to check NULL)
2> Add current node into path (a string in function parameter)
3> Check if the current node is a leaf node: if yes, then save path
4> Keep searching the left and right child of current node. */

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
    void dfs(TreeNode* root, string str, vector<string>& res) {
        if(!root) {
            return;
        } else {
            if(str == "") {
                str += to_string(root->val);
            } else {
                str = str + "->" + to_string(root->val);
            }
            if(!root->left && !root->right) {
                if(str != "") {
                    res.push_back(str);
                }
            }
            dfs(root->left, str, res);
            dfs(root->right, str, res);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string str = "";
        vector<string> res;
        dfs(root, str, res);
        return res;
    }
};
