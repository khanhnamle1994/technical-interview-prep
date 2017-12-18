// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

/* For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X */

void check(vector<vector<char> >&vec,int i,int j,int row,int col){
		if(vec[i][j]=='O'){
			vec[i][j]='1';
			if(i>1)
				check(vec,i-1,j,row,col);
			if(j>1)
				check(vec,i,j-1,row,col);
			if(i+1<row)
				check(vec,i+1,j,row,col);
			if(j+1<col)
				check(vec,i,j+1,row,col);
		}
	}

void solve(vector<vector<char>>& board) {
  int i, j;
  int row = board.size();
  if (!row) return;
  int col = board[0].size();

  for (int i = 0; i < row; i++) {
    check(board, i, 0, row, col);
    if (col > 1) {
      check(board, i, col - 1, row, col);
    }
  }

  for (int j = 1; j + 1 < col; j++) {
    check(board, 0, j, row, col);
    if (row > 1) {
      check(board, row - 1, j, row, col);
    }
  }

  for (int i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      if (board[i][j] == '0') {
        board[i][j] = 'X';
      }
    }
  }

  for (int i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      if (board[i][j] == '1') {
        board[i][j] = '0';
      }
    }
  }
}

// Solution:
// First, check the four border of the matrix. If there is a element is 'O', alter it and all its neighbor 'O'
// elements to '1'. Then, alter all the 'O' to 'X'. At last,alter all the '1' to 'O'
