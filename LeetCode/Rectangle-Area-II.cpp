// We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the ith rectangle.

// Find the total area covered by all rectangles in the plane.  Since the answer may be too large, return it modulo 10^9 + 7.

/* Example 1:

Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.

Example 2:

Input: [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 = (-7)^2 = 49. */

int rectangleArea(vector<vector<int>>& rectangles) {
  int mod = 1000000000 + 7;
  vector<int> x = {0};
  for (auto r : rectangles) {
      x.push_back(r[0]);
      x.push_back(r[2]);
  }
  sort(x.begin(), x.end());
  vector<int>::iterator end_unique = unique(x.begin(), x.end());
  x.erase(end_unique, x.end());
  unordered_map<int, int> x_i;
  for (int i = 0; i < x.size(); ++i) {
      x_i[x[i]] = i;
  }
  vector<int> count(x.size(), 0);
  vector<vector<int>> L;
  for (auto r : rectangles) {
      int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
      L.push_back({y1, x1, x2, 1});
      L.push_back({y2, x1, x2, -1});
  }
  sort(L.begin(), L.end());
  long long cur_y = 0, cur_x_sum = 0, area = 0;
  for (auto l : L) {
      long long  y = l[0], x1 = l[1], x2 = l[2], sig = l[3];
      area = (area + (y - cur_y) * cur_x_sum) % mod;
      cur_y = y;
      for (int i = x_i[x1]; i < x_i[x2]; i++)
          count[i] += sig;
      cur_x_sum = 0;
      for (int i = 0; i < x.size(); ++i) {
          if (count[i] > 0)
              cur_x_sum += x[i + 1] - x[i];
      }
  }
  return area;
}
