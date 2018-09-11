// We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.

// Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

// Your task is to use a quad tree to represent a given grid.

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

Node* buildNode(vector<vector<int>>& grid, int x, int y, int length) {
  if (length == 1) {
      return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
  }

  int newLength = length / 2;
  Node* topLeft = buildNode(grid, x, y, newLength);
  Node* topRight = buildNode(grid, x, y + newLength, newLength);
  Node* botLeft = buildNode(grid, x + newLength, y, newLength);
  Node* botRight = buildNode(grid, x + newLength, y + newLength, newLength);

  if (topLeft -> isLeaf && topRight -> isLeaf && botRight -> isLeaf && botLeft -> isLeaf &&
      ((topLeft -> val && topRight -> val && botLeft -> val && botRight -> val) ||
      !(topLeft -> val || topRight -> val || botLeft -> val || botRight -> val))) {
      bool val = topLeft -> val;
      delete topLeft;
      topLeft = nullptr;
      delete topRight;
      topRight = nullptr;
      delete botLeft;
      botLeft = nullptr;
      delete botRight;
      botRight = nullptr;
      return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
  }
  return new Node(true, false, topLeft, topRight, botLeft, botRight);
}

Node* construct(vector<vector<int>>& grid) {
  int N = grid.size();
  if (N == 0) {
      return nullptr;
  }
  return buildNode(grid, 0, 0, N);
}
