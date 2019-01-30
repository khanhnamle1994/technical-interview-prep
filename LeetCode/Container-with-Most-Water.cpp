/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49 */

int maxArea(vector<int>& height) {
  int water = 0;
  int i = 0, j = height.size() - 1;
  while (i < j) {
      int h = min(height[i], height[j]);
      water = max(water, (j - i) * h);
      while (height[i] <= h && i < j) i++;
      while (height[j] <= h && i < j) j--;
  }
  return water;
}
