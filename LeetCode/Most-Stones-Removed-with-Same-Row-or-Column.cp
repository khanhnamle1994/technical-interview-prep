/* On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

Example 1:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5

Example 2:
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3

Example 3:
Input: stones = [[0,0]]
Output: 0 */

unordered_map<int, int> f;
int islands = 0;

int find(int x) {
    if (!f.count(x)) f[x] = x, islands++;
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void uni(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) f[x] = y, islands--;
}

int removeStones(vector<vector<int>>& stones) {
  for (int i = 0; i < stones.size(); ++i)
      uni(stones[i][0], ~stones[i][1]);
  return stones.size() - islands;
}
