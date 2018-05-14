// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

/* Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
] */

int cnt;

void dfs(int n, int tempn, int queue[])
{
    if(n == tempn)
    {
        cnt++;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            int flag = 1;
            for(int j = 0; j < tempn; j++)
            {
                if(queue[j] == i || (abs(tempn - j) == abs(queue[j] - i)))
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                queue[tempn] = i;
                dfs(n, tempn + 1, queue);
            }
        }
    }
}

int totalNQueens(int n) {
  cnt = 0;
  int queue[n] = {-1};
  dfs(n, 0, queue);
  return cnt;
}
