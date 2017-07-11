/* Given a 2D array binaryMatrix of 0s and 1s, implement a function getNumberOfIslands that returns the number of islands of 1s in
binaryMatrix.

An island is defined as a group of adjacent values that are all 1s. A cell in binaryMatrix is considered adjacent to another cell if
they are next to each either on the same row or column. Note that two values of 1 are not part of the same island if they’re sharing only
a mutual “corner” (i.e. they are diagonally neighbors).

Explain and code the most efficient solution possible and analyze its time and space complexities. */

#include <iostream>
#include <queue>
using namespace std;

int getNumberOfIslands(vector< vector<int> >& binaryMatrix) {
  int islands = 0;
  int rows = binaryMatrix.size(); // number of rows
  int cols = binaryMatrix[0].size(); // number of columns

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(binaryMatrix[i][j] == 1) {
        markIslands(binaryMatrix, rows, cols, i, j);
        islands++;
      }
    }
  }

  return islands;
}

void markIslands(vector< vector<int> >& binaryMatrix, int rows, int cols, int i, int j) {
  std::queue<int> q;
  q.push([i, j]);
  while(!q.empty()) {
    auto item = q.front();
    q.pop();
    int x = item[0];
    int y = item[1];
    if(binaryMatrix[x][y] == 1) {
      binaryMatrix[x][y] = -1;
      pushIfValid(q, rows, cols, x - 1, y);
      pushIfValid(q, rows, cols, x, y - 1);
      pushIfValid(q, rows, cols, x + 1, y);
      pushIfValid(q, rows, cols, x, y + 1);
    }
  }
}

void pushIfValid(queue<int> q, int rows, int cols, int x, int y) {
  if(x >= 0 && x < rows && y >= 0 && y < cols) {
    q.push([x, y]);
  }
}

/* Solution:
This problem is very similar to counting the number of connected components in an Undirected Graph. However, Graph Theory isn’t necessary
to solve this problem or to understand its solution. In an undirected graph, a connected component is a group of vertices in which every
vertex is connected to at least one other vertex. In a similar way, an island in the matrix is a group of adjacent (connected) 1s.

To solve this problem, we’ll traverse binaryMatrix and every time we come across a cell of 1 we’ll do the following: Change that cell and
all its vertically and horizontally (but not diagonally) adjacent 1s into -1s. We do this “expansion” in order to avoid recounting of
islands. Increment islands - which is our counter for number of islands - by 1. Expanding from a cell whose value is 1 to other adjacent
1s in binaryMatrix is similar to running a Breadth-First Search (BFS) or a Depth-First Search (DFS).

In our case, we’ll avoid using a recursion and instead opt for an iterative approach to expand to all adjacent 1s. We do so by using queue
that holds the next indices to visit. We keep expanding to other adjacent 1s as long as the queue is not empty. Whenever we encounter a
value of -1 in our traversal, we ignore it since it is part on an island we’ve already counted. */

// Time Complexity:
// Let N and M be the numbers of columns and rows in binaryMatrix, respectively. Each cell in binaryMatrix is visited a constant number of
// times. Once during the iteration and up to 4 times during an island expansion. Therefore, the time complexity is linear in the size of
// the input, i.e. O(N⋅M).

// Space Complexity:
// Since we are allocating a queue in the algorithm, the space complexity is linear O(N⋅M). For instance, consider a matrix that is all 1s.
