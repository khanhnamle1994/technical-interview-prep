// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

// Keep track of the already safe level and the total water so far. In each step, process and discard the lower one of the leftmost or rightmost elevation. With left and right index

int trap(vector<int>& height) {
  int l = 0, r = height.size()-1, level = 0, water = 0;
  while (l < r) {
      int lower = height[height[l] < height[r] ? l++ : r--];
      level = max(level, lower);
      water += level - lower;
  }
  return water;
}
