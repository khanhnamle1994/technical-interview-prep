// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution.

void solveSudoku(vector<vector<char>>& board) {
    if(board.size() != 9 || board[0].size() != 9) {
      return;
    }
    solveBoard(board);
}

bool solveBoard(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == '.') {
                for(char k = '1'; k <= '9'; k++) {
                    if(isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if(solveBoard(board) == true) { return true; }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(int row, int col, char target, vector<vector<char>>& board) {
    // check the row and column
    for(int i = 0; i < 9; i++) {
        if((board[row][i] == target) || (board[i][col] == target)) {
            return false;
        }
    }

    // check the block
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int x = row / 3 * 3 + i;
            int y = col / 3 * 3 + j;
            if(board[x][y] == target) {
                return false;
            }
        }
    }
    return true;
}
