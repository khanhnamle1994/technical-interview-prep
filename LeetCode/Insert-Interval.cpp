// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.

/* Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10]. */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  intervals.push_back(newInterval);
  sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
    return a.start < b.start;
  });

  vector<Interval> res = {intervals[0]};
  for(int i = 1; i < intervals.size(); i++) {
    if (res.back().end < intervals[i].start) {
      res.push_back(intervals[i]);
    } else {
      res.back().end = max(res.back().end, intervals[i].end);
    }
  }
  return res;
}
