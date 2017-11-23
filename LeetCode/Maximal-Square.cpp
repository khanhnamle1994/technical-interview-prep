// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

/* For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. */

/* A square with '1' means any '0' will interrupt counting of it's right/down/right-down, and '1' will 'inherit' the
existing counting result.

Since the target is a square, we shall take the smallest counting result from up/left/up-left.

So for each element '0', it doesn't inherit previous accumulated counting; and for each element '1', it takes the smallest
number from left/up/left-up and add 1 to it
*/

int maximalSquare(vector<vector<char>>& matrix) {
  int rst = 0;
  for(int ii = 0; ii < matrix.size(); ++ii)
  {
    for(int jj = 0; jj < matrix[0].size(); ++jj)
    {
        int a = (ii && jj) ? matrix[ii - 1][jj - 1] : 0;
        int b = (ii) ? matrix[ii - 1][jj] : 0;
        int c = (jj) ? matrix[ii][jj - 1] : 0;

        matrix[ii][jj] = (matrix[ii][jj] > '0') ? (min(a, min(b, c)) + 1) : 0;

        rst = max(rst, matrix[ii][jj] * matrix[ii][jj]);
    }
  }
  return rst;
}
