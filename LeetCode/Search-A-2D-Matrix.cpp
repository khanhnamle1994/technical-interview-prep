// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// 1 - Integers in each row are sorted from left to right.
// 2 - The first integer of each row is greater than the last integer of the previous row.

/* For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true. */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if(matrix.empty() || matrix[0].empty()) {
      return false;
  }

  int m = matrix.size(), n = matrix[0].size();
  int start = 0, end = m*n - 1;

  while(start <= end) {
      int mid = start + (end - start)/2;
      int e = matrix[mid/n][mid%n];
      if(target < e) {
          end = mid - 1;
      } else if(target > e) {
          start = mid + 1;
      } else {
          return true;
      }
  }
  return false;
}

// Use binary search.
// n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
// an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
