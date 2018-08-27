// On a N * N grid, we place some 1 * 1 * 1 cubes.
// Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
// Return the total surface area of the resulting shapes.

/* Example 1:
Input: [[2]]
Output: 10

Example 2:
Input: [[1,2],[3,4]]
Output: 34

Example 3:
Input: [[1,0],[0,2]]
Output: 16

Example 4:
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32

Example 5:
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46 */

int surfaceArea(vector<vector<int>>& grid) {
  int res = 0, n = grid.size();
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          if (grid[i][j]) res += grid[i][j] * 4 + 2;
          if (i) res -= min(grid[i][j], grid[i - 1][j]) * 2;
          if (j) res -= min(grid[i][j], grid[i][j - 1]) * 2;
      }
  }
  return res;
}
