// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

// Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

// Each node of each tree in the answer must have node.val = 0.

// You may return the final list of trees in any order.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> allPossibleFBT(int N) {
  return allFBT(N);
}

vector<TreeNode*> allFBT(int n) {
  vector<TreeNode*> ans;
  if (n==1) {
  	TreeNode* a = new TreeNode(0);
  	ans.push_back(a);
  	return ans;
  }
  if (n < 1 || n%2==0) return ans;
  for (int i = 1; i < n; i=i+2) {
  	vector<TreeNode*> lans = allFBT(i);
  	vector<TreeNode*> rans = allFBT(n-i-1);
  	for (int j = 0; j < lans.size(); j++) {
  		for (int k = 0; k < rans.size(); k++) {
  			TreeNode* r = new TreeNode(0);
  			r->left = lans[j];
  			r->right = rans[k];
  			ans.push_back(r);
  		}
  	}
  }
  return ans;
}
