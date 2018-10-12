// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

// Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

/* Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid. */

vector<vector<int>> dir;

bool check(vector<vector<int>>& grid, int x, int y) {
	if (grid[x][y] != 5) {
		return false;
	}
	for (auto it : dir) {
		if (grid[x + it[0]][y + it[1]] < 1 || grid[x + it[0]][y + it[1]]>9 || grid[x + it[0]][y + it[1]] + grid[x + it[2]][y + it[3]] != 10) {
			return false;
		}
	}
	return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
  int res = 0;
	dir = { {-1,0,1,0},{-1,-1,1,1},{-1,1,1,-1},{0,-1,0,1} };
	for (int i = 1; i < grid.size() - 1; i++) {
		for (int j = 1; j < grid[0].size() - 1; j++) {
			if (check(grid, i, j)) {
				res++;
			}
		}
	}
	return res;
}
