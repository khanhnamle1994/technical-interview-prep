// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers
// along its path.

int minPathSum(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  vector<int> cur(m, grid[0][0]);

  for (int i = 1; i < m; i++)
      cur[i] = cur[i - 1] + grid[i][0];
  for (int j = 1; j < n; j++) {
      cur[0] += grid[0][j];
      for (int i = 1; i < m; i++)
          cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
  }
  return cur[m - 1];
}

// This is a typical DP problem. Suppose the minimum path sum of arriving at point (i, j) is S[i][j], then the state equation is
// S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j].

// Well, some boundary conditions need to be handled. The boundary conditions happen on the topmost row (S[i - 1][j] does not exist) and
// the leftmost column (S[i][j - 1] does not exist). Suppose grid is like [1, 1, 1, 1], then the minimum sum to arrive at each point is
// simply an accumulation of previous points and the result is [1, 2, 3, 4].
