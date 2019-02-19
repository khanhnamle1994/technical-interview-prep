/* Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)

Example 1:
Input: [0,1,2,3,4,3,4]
Output: "dba"

Example 2:
Input: [25,1,3,1,3,0,2]
Output: "adz"

Example 3:
Input: [2,2,1,null,1,0,null,0]
Output: "abc" */

string smallestFromLeaf(TreeNode* root) {
    // leaf nodes
    if (!root->left && !root->right) return string(1, root->val+'a');
	   // two child nodes
    if (root->left && root->right) {
        string s1 = smallestFromLeaf(root->left);
        string s2 = smallestFromLeaf(root->right);
        return (s1<s2) ? s1.append(1, root->val+'a') : s2.append(1, root->val+'a');
    }
	   // one child nodes
    return (root->left) ? smallestFromLeaf(root->left).append(1, root->val+'a') : smallestFromLeaf(root->right).append(1, root->val+'a');
}
