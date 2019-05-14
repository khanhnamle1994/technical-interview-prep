/* Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, vector<int>>> res_map;
    if(root == nullptr)
        return {};

    queue<tuple<TreeNode*, int, int>> q;
    q.emplace(root, 0, 0);

    while(!q.empty())
    {
        const auto& [node, x, y] = q.front();
        res_map[x][y].emplace_back(node->val);
        if(node->left != nullptr)
            q.emplace(node->left, x - 1, y + 1);
        if(node->right != nullptr)
            q.emplace(node->right, x + 1, y + 1);
        q.pop();
    }

    vector<vector<int>> res;
    res.reserve(res_map.size());
    for(auto& x : res_map)
    {
        auto& r = res.emplace_back();
        for(auto& y : x.second)
        {
            sort(begin(y.second), end(y.second));
            copy(make_move_iterator(begin(y.second)), make_move_iterator(end(y.second)), back_insert_iterator(r));
        }
    }

    return res;
}
