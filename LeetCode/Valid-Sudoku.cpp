// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// 1> Check the rows and columns respectively, a mark array is used to check the numbers
// 2> Check the 3 x 3 blocks, also using a mark array

bool isValidSudoku(vector<vector<char>>& board) {
        //Check rows and columns
        for (int i = 0; i < 9; i++){
            vector<bool> marki(10, false);
            vector<bool> markj(10, false);

            for (int j = 0; j < 9; j++){

                if (board[i][j] != '.'){
                    if (marki[int(board[i][j]-'0')] == false) {
                      marki[int(board[i][j]-'0')] = true;
                    }
                    else {
                      return false;
                    }
                }

                if (board[j][i] != '.'){
                    if (markj[int(board[j][i]-'0')] == false) {
                      markj[int(board[j][i]-'0')] = true;
                    }
                    else {
                      return false;
                    }
                }
            }
        }

        //Check 3x3 blocks
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> mark(10, false);

                for (int p = 0; p < 3; p++){
                    for (int q = 0; q < 3; q++){
                        if (board[i + p][j + q] != '.') {
                           if (mark[int(board[i + p][j + q]-'0')] == false) {
                             mark[int(board[i + p][j + q]-'0')] = true;
                           }
                           else {
                             return false;
                           }
                        }
                    }
                }
            }
        }
        return true;
}
