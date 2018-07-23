// An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.
// Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has size at least 2.

/* Example 1:

Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
Output: 3

Explanation:
Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.

Example 2:

Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
Output: 5

Explanation:
An example of a minimum sized set is {1, 2, 3, 4, 5}. */

int intersectionSizeTwo(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
      return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
  });
  int n = intervals.size(), ans = 0, p1 = -1, p2 = -1;
  for (int i = 0; i < n; i++) {
      // current p1, p2 works for intervals[i]
      if (intervals[i][0] <= p1) continue;
      // Neither of p1, p2 works for intervals[i]
      // replace p1, p2 by ending numbers
      if (intervals[i][0] > p2) {
          ans += 2;
          p2 = intervals[i][1];
          p1 = p2-1;
      }
      // only p2 works;
      else {
          ans++;
          p1 = p2;
          p2 = intervals[i][1];
      }
  }
  return ans;
}
