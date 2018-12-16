/* In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3 */

int count, n;
vector<int> f;

int regionsBySlashes(vector<string>& grid) {
  n = grid.size();
  count = n * n * 4;
  for (int i = 0; i < n * n * 4; ++i)
      f.push_back(i);

  // top: 0, right: 1, bottom: 2, left: 3
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0));
          if (j > 0) uni(g(i , j - 1, 1), g(i , j, 3));
          if (grid[i][j] != '/') {
              uni(g(i , j, 0), g(i , j,  1));
              uni(g(i , j, 2), g(i , j,  3));
          }
          if (grid[i][j] != '\\') {
              uni(g(i , j, 0), g(i , j,  3));
              uni(g(i , j, 2), g(i , j,  1));
          }
      }
  }
  return count;
}

int find(int x) {
  if (x != f[x]) {
      f[x] = find(f[x]);
  }
  return f[x];
}

void uni(int x, int y) {
  x = find(x); y = find(y);
  if (x != y) {
      f[x] = y;
      count--;
  }
}

int g(int i, int j, int k) {
  return (i * n + j) * 4 + k;
}
