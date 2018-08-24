// Given an n-ary tree, return the preorder traversal of its nodes' values.

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

vector<int> preorder(Node* root) {
  if(root==NULL) return {};
  stack<Node*> stk;
  vector<int> res;
  stk.push(root);
  while(!stk.empty()) {
      Node* temp=stk.top();
      stk.pop();
      for(int i=temp->children.size()-1;i>=0;i--) stk.push(temp->children[i]);
      res.push_back(temp->val);
  }
  return res;
}
