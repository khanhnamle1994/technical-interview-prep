// An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

// What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.

/* Examples:
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation:
One potential sequence of moves is shown below, from left to right:

0110     1010     1010
0110 --> 1010 --> 0101
1001     0101     1010
1001     0101     0101

The first move swaps the first and second column.
The second move swaps the second and third row.


Input: board = [[0, 1], [1, 0]]
Output: 0
Explanation:
Also note that the board with 0 in the top left corner,
01
10

is also a valid chessboard.

Input: board = [[1, 0], [1, 0]]
Output: -1
Explanation:
No matter what sequence of moves you make, you cannot end with a valid chessboard. */

int movesToChessboard(vector<vector<int>>& board) {
  int N = board.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) return -1;
    }
  }

  for (int i = 0; i < N; ++i) {
      rowSum += board[0][i];
      colSum += board[i][0];
      rowSwap += board[i][0] == i % 2;
      colSwap += board[0][i] == i % 2;
  }

  if (N / 2 > rowSum || rowSum > (N + 1) / 2) return -1;
  if (N / 2 > colSum || colSum > (N + 1) / 2) return -1;

  if (N % 2) {
      if (colSwap % 2) colSwap = N - colSwap;
      if (rowSwap % 2) rowSwap = N - rowSwap;
  } else {
      colSwap = min(N - colSwap, colSwap);
      rowSwap = min(N - rowSwap, rowSwap);
  }
  
  return (colSwap + rowSwap) / 2;
}
