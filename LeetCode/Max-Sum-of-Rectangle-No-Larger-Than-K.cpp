// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

/* Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2 */

// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
  if (matrix.empty()) return 0;
  int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;

  for (int l = 0; l < col; ++l) {
      vector<int> sums(row, 0);

      for (int r = l; r < col; ++r) {
          for (int i = 0; i < row; ++i) {
              sums[i] += matrix[i][r];
          }

          // Find the max subarray no more than K
          set<int> accuSet;
          accuSet.insert(0);
          int curSum = 0, curMax = INT_MIN;

          for (int sum : sums) {
              curSum += sum;
              set<int>::iterator it = accuSet.lower_bound(curSum - k);
              if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
              accuSet.insert(curSum);
          }
          res = std::max(res, curMax);
      }
  }
  return res;
}
