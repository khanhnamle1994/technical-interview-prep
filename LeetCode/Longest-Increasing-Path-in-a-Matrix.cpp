// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

/* Example 1:

Input: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:

Input: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed. */

vector<vector<int>> path;
vector<pair<int, int>> dics{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int LIP(vector<vector<int>>& matrix, int i, int j) {
    int len = 0;
    for (auto p : dics) {
        int x = i + p.first, y = j + p.second;
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) continue;
        if (matrix[x][y] > matrix[i][j]) {
            if (path[x][y] == -1) path[x][y] = LIP(matrix, x, y);
            len = max(len, path[x][y]);
        }
    }
    path[i][j] = len + 1;
    return path[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    path = vector<vector<int>>(m, vector<int>(n, -1));
    int ans = -1;
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (path[i][j] == -1) LIP(matrix, i, j);
            ans = max(ans, path[i][j]);
        }
    }
    return ans;
}

/*
*   dynamic programing.
*   -Using a matrix named path which has the same size with original matrix and each cell initialized as -1
*    to store the length of LIP for each cell.
*   -For each cell in the matrix, use dfs to find the Longest Increasing Path and store it in current cell.
*   -During dfs, if the neighbor cell has bigger matrix-value and -1 path-value, then get its length of LIP
*    recursively.
*
*   Length of LIP for current cell (x, y), len initialized as 0;
*   for (x1, y1) in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)
*       if (matrix[x1][y1] > matrix[x][y]) {
*           if (path[x][y] == -1) get path[x1][y1] recursively;
*           len = max(len, path[x][y]);
*       }
*   // if all of the neighbor not larger than current cell then the length of current cell should be 1;
*   path[x][y] = 1 + len;
*/
