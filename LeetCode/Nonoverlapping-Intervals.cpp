// Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals
// non-overlapping.

/* Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

Example 2:
Input: [ [1,2], [1,2], [1,2] ]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

Example 3:
Input: [ [1,2], [2,3] ]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping. */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

int eraseOverlapIntervals(vector<Interval>& intervals) {
  auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
  sort(intervals.begin(), intervals.end(), comp);
  int res = 0, pre = 0;
  for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start < intervals[pre].end) {
          res++;
          if (intervals[i].end < intervals[pre].end) pre = i;
      }
      else pre = i;
  }
  return res;
}
