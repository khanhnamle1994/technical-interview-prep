// Given a binary tree, return an array consisting of the keys at the same level. Keys should appear in the order of the corresponding
// nodes' depths, breaking ties from left to right.

/* Solution:
A brute-force approach might be to write the nodes into an array while simultaneously computing their depth. We can use pre-order traversal
to compute this array - by traversing a node's left child first we can ensure that nodes at the same depth are sorted from left to right.
Now we can sort this array using a stable sorting algorithm with node depth being the sort key. The time complexity is dominated by the
time taken to sort, O(n log n), and the space complexity is O(n), which is the space to store the node depths.

Intuitively, since nodes are already presented in a somewhat ordered fashion in the tree, it should be possible to avoid a full-blow sort,
thereby reducing time complexity. Furthermore, by processing nodes in order of depth, we do not need to label every node with its depth.

In the following, we use a queue of nodes to store nodes at depth i and a queue of nodes at depth i + 1. After all nodes at depth i are
processed, we are done with that queue, and can start processing the queue with nodes at depth i + 1, putting the depth i + 2 nodes in a
new queue. */

vector<vector<int>> BinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>>& tree) {
  queue<BinaryTreeNode<int>*> curr_depth_nodes({tree.get()});
  vector<vector<int>> result;

  while(!curr_depth_nodes.empty()) {
    queue<BinaryTreeNode<int>*> next_depth_nodes;
    vector<int> this_level;
    while(!curr_depth_nodes.empty()) {
      auto curr = curr_depth_nodes.front();
      curr_depth_nodes.pop();
      if(curr) {
        this_level.emplace_back(curr->data);

        // Defer the null checks to the null test above
        next_depth_nodes.emplace(curr->left.get());
        next_depth_nodes.emplace(curr->right.get());
      }
    }

    if(!this_level.empty()) {
      result.emplace_back(this_level);
    }
    curr_depth_nodes = next_depth_nodes;
  }
  return result;
}

// Since each node is enqueued and dequeued exactly once, the time complexity is O(n). The space complexity is O(m), where m is the maximum
// number of nodes at any single depth.
