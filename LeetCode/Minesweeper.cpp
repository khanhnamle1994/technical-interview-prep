// Let's play the minesweeper game!

/* You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

1> If a mine ('M') is revealed, then the game is over - change it to 'X'.
2> If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
3> If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
4> Return the board when no more squares will be revealed. */

/* Example 1:
Input:

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']] */

/* Example 2:
Input:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']] */

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
  if(board[click[0]][click[1]] == 'M'){
      board[click[0]][click[1]] = 'X';
      return board;
  }
  reveal(board,click[0],click[1]);
  return board;
}

bool inboard(const vector<vector<char>>& board, int x, int y){
  return ( x>=0 && x<board.size() && y>=0 && y<board[0].size() );
}

void reveal(vector<vector<char>>& board, int x, int y){
    if(!inboard(board,x,y)) return;
    if(board[x][y] == 'E'){
        //search 8 adjacent squares
        int count = 0;
        if(inboard(board,x-1,y-1) && board[x-1][y-1] == 'M') count++;
        if(inboard(board,x-1,y  ) && board[x-1][y  ] == 'M') count++;
        if(inboard(board,x-1,y+1) && board[x-1][y+1] == 'M') count++;
        if(inboard(board,x  ,y-1) && board[x  ][y-1] == 'M') count++;
        if(inboard(board,x  ,y+1) && board[x  ][y+1] == 'M') count++;
        if(inboard(board,x+1,y-1) && board[x+1][y-1] == 'M') count++;
        if(inboard(board,x+1,y  ) && board[x+1][y  ] == 'M') count++;
        if(inboard(board,x+1,y+1) && board[x+1][y+1] == 'M') count++;

        if(count>0)
            board[x][y] = '0'+count;
        else{
            board[x][y] = 'B';
            reveal(board,x-1,y-1);
            reveal(board,x-1,y  );
            reveal(board,x-1,y+1);
            reveal(board,x  ,y-1);
            reveal(board,x  ,y+1);
            reveal(board,x+1,y-1);
            reveal(board,x+1,y  );
            reveal(board,x+1,y+1);
        }
    }
}
