/* A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:
>> Players take turns placing characters into empty squares (" ").
>> The first player always places "X" characters, while the second player always places "O" characters.
>> "X" and "O" characters are always placed into empty squares, never filled ones.
>> The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
>> The game also ends if all squares are non-empty.
>> No more moves can be played if the game is over.

Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true */

bool validTicTacToe(vector<string>& board) {
    bool wony = false, wonx = false;
    int rows = board.size();
    int cols = rows ? board[0].size() : 0;
    int diax = 0, diay = 0, xdiax = 0, xdiay = 0, x_count = 0, y_count = 0;

    for(int i = 0; i < rows; i++) {
        int rowsx = 0, rowsy = 0;
        int colsx = 0, colsy = 0;
        for(int j = 0; j < cols; j++) {
            // see current row
            if(board[i][j] == 'X')
                rowsx++,x_count++;
            if(board[i][j] == 'O')
                rowsy++, y_count++;
            // see ith column
            if(board[j][i] == 'X')
                colsx++;
            if (board[j][i] == 'O')
                colsy++;
        }

        // see both the diagonals
        if(board[i][i] == 'X')
            diax++;
        if(board[i][i] == 'O')
            diay++;
        if(board[i][cols - 1 - i] == 'X')
            xdiax++;
        if(board[i][cols - 1 - i] == 'O')
            xdiay++;

        if(rowsx == 3 || colsx == 3 || diax == 3 || xdiax == 3)
            wonx = true;

         if(rowsy == 3 || colsy == 3 || diay == 3 || xdiay == 3)
            wony = true;
    }

    if(!(x_count == y_count || x_count == y_count + 1))
        return false;

    if((wonx && wony) || (wonx && x_count == y_count) || (wony && x_count != y_count))
        return false;

    return true;
}
