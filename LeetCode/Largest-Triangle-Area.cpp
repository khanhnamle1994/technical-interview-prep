// You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

/* Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2 */

double largestTriangleArea(vector<vector<int>>& points) {
  double res = 0;
  for (auto &i : points)
      for (auto &j : points)
          for (auto &k : points)
      res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
  return res;
}
