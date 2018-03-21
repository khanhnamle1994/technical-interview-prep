// There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

// The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.

// If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

// You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

int leastBricks(vector<vector<int>>& wall) {
  unordered_map<int, int> edges;
  auto min_bricks = wall.size();
  for (auto row : wall)
      for (auto i = 0, width = 0; i < row.size() - 1; ++i) // skip last brick
          min_bricks = min(min_bricks, wall.size() - (++edges[width += row[i]]));
  return min_bricks;
}

// For each potential cut position - which is at the edge of any brick, I am counting the number of brick edges for all rows. Note that we need to use hash map to only track potential (not all) cuts. If bricks are very wide, you’ll get MLE if you store all cut positions.
