// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

/* Example 1:
Input:
0 0 0
0 1 0
0 0 0

Output:
0 0 0
0 1 0
0 0 0

Example 2:
Input:
0 0 0
0 1 0
1 1 1

Output:
0 0 0
0 1 0
1 2 1
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
  int h = matrix.size(), w = matrix[0].size();
  vector<vector<int>> dp(h,vector<int>(w,INT_MAX));

  for(int times = 0; times <= 1; times++) // two passes, first forward then backward
      for(int i = times ? h - 1 : 0; times ? i >= 0 : i < h; times ? i-- : i++)
          for(int j = times ? w - 1 : 0; times ? j >= 0: j < w; times ? j-- : j++)
                  if(matrix[i][j] == 0)
                      dp[i][j] = 0;
                  else {
                      if(i && dp[i - 1][j] != INT_MAX && dp[i][j] > dp[i - 1][j] + 1) // look up
                          dp[i][j] = dp[i - 1][j] + 1;
                      if(j && dp[i][j - 1] != INT_MAX && dp[i][j] > dp[i][j - 1] + 1) // look left
                          dp[i][j] = dp[i][j - 1] + 1;
                      if(i < h - 1 && dp[i + 1][j] != INT_MAX && dp[i][j] > dp[i + 1][j] + 1) // look down
                          dp[i][j] = dp[i + 1][j] + 1;
                      if(j < w - 1 && dp[i][j + 1] != INT_MAX && dp[i][j] > dp[i][j + 1] + 1) // look right
                          dp[i][j] = dp[i][j + 1] + 1;
                  }
  return dp;
}
