/* Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.) */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxAncestorDiff(TreeNode* root) {
    if (root == NULL)
        return 0;

    int max_diff = 0;
    stack<TreeNode *> st;
    map<TreeNode *, int> visited;
    st.push(root);
    stack<int> max_st, min_st;
    max_st.push(0);
    min_st.push(INT_MAX);

    while (!st.empty()) {
        TreeNode *top = st.top();
        if (visited[top] == 0) {
            if (top->val > max_st.top())
                max_st.push(top->val);
            else
                max_st.push(max_st.top());
            if (top->val < min_st.top())
                min_st.push(top->val);
            else
                min_st.push(min_st.top());
        }
        visited[top] = 1;

        if (top->left != NULL && visited[top->left] == 0) {
            st.push(top->left);
        } else if (top->right != NULL && visited[top->right] == 0) {
            st.push(top->right);
        } else if (top->left == NULL && top->right == NULL) {
            max_diff = max(max_diff, max_st.top() - min_st.top());
        }

        if ((top->left == NULL || visited[top->left] == 1) && (top->right == NULL || visited[top->right] == 1)) {
            st.pop();
            max_st.pop();
            min_st.pop();
        }
    }

    return max_diff;
}
