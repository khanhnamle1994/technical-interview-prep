// There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

/* Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]

Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]] */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

static bool mycompare(Point& a, Point& b) {
   return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int orientation(Point& a, Point& b, Point& c) {
   return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
}

vector<Point> outerTrees(vector<Point>& points) {
   // Andrew's monotone chain method
   int n = points.size();
   if (n <= 3) return points;
   vector<Point> ans;
   sort(points.begin(), points.end(), mycompare);
   // left to right
   for (int i = 0; i < n; ++i) {
       while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0)
           ans.pop_back();
       ans.push_back(points[i]);
   }
   // if all points along a line, ans.size() is n after left to right procedure
   if (ans.size() == n) return ans;
   // right to left
   for (int i = n-2; i >= 0; --i) {
       while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0)
           ans.pop_back();
       ans.push_back(points[i]);
   }
   ans.pop_back();
   return ans;
}
