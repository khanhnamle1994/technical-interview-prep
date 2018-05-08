// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

/* Example:

Input: 4

Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above. */

bool check(vector<int> & row, vector<int>& col, int x, int y){
    if(row[x]!=-1|| col[y]!=-1) return false;
    for(int i = 0; i < x; i++){
        if(abs(x-i)==abs(row[i]-y)) return false;
    }
    return true;
}

void dfs(vector<int> & row, vector<int>& col, int currentrow, int n, vector<vector<string>>& r){
    if(currentrow==n){
        vector<string> pr(n, string(n,'.'));
        for(int i = 0; i < n; i++){
            pr[i][row[i]] = 'Q';
        }
        r.push_back(pr);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!check(row, col, currentrow,i)) continue;
        row[currentrow] = i;
        col[i] = currentrow;
        dfs(row,col,currentrow+1,n,r);
        row[currentrow] = -1;
        col[i] = -1;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> row(n, -1);
    vector<int> col(n, -1);
    vector<vector<string>> r;
    dfs(row, col, 0, n, r);
    return r;
}
