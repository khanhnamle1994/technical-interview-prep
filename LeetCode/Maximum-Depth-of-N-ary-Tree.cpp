// Given a n-ary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

int maxDepth(Node* root) {
  if (!root) return 0;
  int res = 1;
  for(Node* child : root->children)
      res = max(res, maxDepth(child) + 1);
  return res;
}
