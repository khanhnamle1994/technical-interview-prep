// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

vector<vector<int>> levelOrder(Node* root) {
  if (root == NULL) return vector<vector<int>>(); // We could also "return {};" here thanks to C++ 11.
  vector<vector<int>> res; // define a vector of vector for storing values of nodes. Data type: int
  queue<Node*> q; // define the queue. Data type : pointers of the data structure Node
  q.push(root); // push the root node
  while (!q.empty()) // whenever the queue is not empty
  {
      int size = q.size(); // store the size of queue
      vector<int> level; // store the result per level
      for (int i = 0; i < size; i++) // for each node of the current level
      {
          Node* tmp = q.front(); // get the first node from the queue
          q.pop(); // pop this node
          level.push_back(tmp -> val); // store the val of the tmp node
          for (auto n : tmp -> children) // push every child node of the tmp node back to the queue. Remember the principle: FIFO(first in first out)
               q.push(n);
      }
      res.push_back(level); // push the result vector of the current level to res.
  }
  return res;
}
