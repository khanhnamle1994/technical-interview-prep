// Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

/* For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n));
    int k = 1, i = 0;
    while (k <= n * n) {
      int j = i;
      // 4 steps
      while(j < n - i) { // 1. horizonal, left to right
        ret[i][j++] = k++;
      }
      j = i + 1;

      while(j < n - i) { // 2. vertical, top to bottom
        ret[j++][n-i-1] = k++;
      }
      j = n - i - 2;

      while(j > i) { // 3. horizonal, right to left
        ret[n-i-1][j--] = k++;
      }
      j = n - i - 1;

      while (j > i) { // 4. vertical, bottom to top
        ret[j--][i] = k++;
      }
      i++; // next loop
    }
    return ret;
}
