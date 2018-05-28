// Given a binary tree, return the postorder traversal of its nodes' values.

/* Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> postorderTraversal(TreeNode* root) {
  if(root == NULL) return vector<int>();
	deque<pair<TreeNode*,int>> deq;
	vector<int> ans;
	deq.push_back({root, 0});

	while(!deq.empty()){
		auto p = deq.back();
		deq.pop_back();

		if(p.second == 0){
				deq.push_back({p.first, 1});
				if(p.first->left != NULL){
						deq.push_back({p.first->left, 0});
				}
		}
		else if(p.second == 1){
				deq.push_back({p.first,2});
				if(p.first->right != NULL) {
						deq.push_back({p.first->right, 0});
				}
		}
		else {
				ans.push_back(p.first->val);
		}
	}
	return ans;
}
