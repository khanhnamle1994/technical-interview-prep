/* Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1]. */

int findLength(vector<int>& A, vector<int>& B) {
  int m = A.size(), n = B.size();
  if (!m || !n) return 0;
  vector<int> dp(n + 1);
  int res = 0;
  for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
          res = max(res, dp[j] = A[i] == B[j] ? 1 + dp[j + 1] : 0);
      }
  }
  return res;
}
