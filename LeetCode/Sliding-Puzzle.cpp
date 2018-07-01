// On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

// A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

// Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

/* Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

Input: board = [[3,2,4],[1,5,0]]
Output: 14 */

unordered_map<int, vector<int>> moves{{0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{3,5,1}},{5,{4,2}}};

int slidingPuzzle(vector<vector<int>>& board) {
  string s = to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2])
    + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);

  unordered_map<string, int> m({{s, 0}});
  queue<pair<string, int>> q({{s, s.find('0')}});

  for (;!q.empty() && q.front().first != "123450";q.pop()) {
    for (auto new_zero : moves[q.front().second]) {
      auto str = q.front().first;
      swap(str[q.front().second], str[new_zero]);
      if (m.insert({str, m[q.front().first] + 1}).second) q.push({ str, new_zero });
    }
  }
  return q.empty() ? -1 : m[q.front().first];
}
