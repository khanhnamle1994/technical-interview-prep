// Given an n-ary tree, return the postorder traversal of its nodes' values.

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

vector<int> postorder(Node* root) {
  if(root == NULL) return {};
  vector<int> res;
  stack<Node*> stk;
  stk.push(root);
  while(!stk.empty())
  {
      Node* temp = stk.top();
      stk.pop();
      for(int i = 0; i < temp->children.size(); i++) stk.push(temp->children[i]);
      res.push_back(temp->val);
  }
  reverse(res.begin(), res.end());
  return res;
}
