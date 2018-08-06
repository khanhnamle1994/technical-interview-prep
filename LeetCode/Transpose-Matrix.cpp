// Given a matrix A, return the transpose of A.
// The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

/* Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]] */

vector<vector<int>> transpose(vector<vector<int>>& A) {
  int M = A.size(), N = A[0].size();
  vector<vector<int>> B(N, vector<int>(M, 0));
  for (int j = 0; j < N; j++)
      for (int i = 0; i < M; i++)
          B[j][i] = A[i][j];
  return B;
}
