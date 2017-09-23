/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British
mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors
(horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
1> Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2> Any live cell with two or three live neighbors lives on to the next generation.
3> Any live cell with more than three live neighbors dies, as if by over-population..
4> Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state. */

void gameOfLife(vector< vector<int> >& board) {
  const int m = board.size();
  const int n = m ? board[0].size() : 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int count = 0;
      // Count live cells in 3 x 3 block
      for (int I = max(i - 1, 0); I < min(i + 2, m); I++) {
        for (int J = max(j - 1, 0); J < min(j + 2, n); J++) {
          count += board[I][J] & 1;
        }
      }
      // if (count == 4 && board[i][j]) means:
      // Any live cell with three live neighbors lives.
      // if (count == 3) means:
      // Any live cell with two live neighbors.
      // Any dead cell with exactly three live neighbors lives.
      if ((count == 4 && board[i][j]) || count == 3) {
        board[i][j] |= 2;  // Mark as live.
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] >>= 1; // Upate to the next state.
    }
  }
}
