// Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

// Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

// Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.

/* Examples:

Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty  */

int minStep;

void dfs(string& board, unordered_map<char,int>& mp, int used) {
    if (board.empty()) {
        minStep = min(minStep, used);
        return;
    }

    for (int i = 0; i < board.size();) {
        int j = i;
        char c = board[i];
        while (j < board.size() && board[j] == c) j++;
        if (j - i < 3) {
            int miss = 3 - (j - i);
            if (mp[c] >= miss) {
                removeBoard(board, i, j);
                mp[c] -= miss;
                dfs(board, mp, used + miss);
                mp[c] += miss;
                restoreBoard(board, i, j - i, c);
            }
        } else {
            removeBoard(board, i, j);
            dfs(board, mp, used);
            restoreBoard(board, i, j - i, c);
        }
        i = j;
    }
}

void removeBoard(string& board, int start, int end) {
    board.erase(board.begin() + start, board.begin() + end);
}

void restoreBoard(string& board, int pos, int n, char c) {
    board.insert(pos, n, c);
}

int findMinStep(string board, string hand) {
  unordered_map<char,int> mp;
  for (auto c:hand) mp[c]++;

  minStep = INT_MAX;
  dfs(board, mp, 0);
  return minStep == INT_MAX ? -1 : minStep;
}
