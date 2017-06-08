// Given a collection of intervals, merge all overlapping intervals.
// For example, given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18].

/* Analysis:
To check the intersections between interval [a,b] and [c,d],  there are four cases (equal not shown in the figures):
    a____b
c____d

a____b
     c____d

a_______b
    c___d

   a___b
c_______d

But we can simplify these into 2 cases when check the smaller (smaller start point) interval with the bigger interval.

For the problem, the idea is simple. First sort the vector according to the start value. Second, scan every interval, if it can be
merged to the previous one, then merge them, else push it into the result vector. */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 class Solution {
 public:
   static bool myfunc(const Interval & a, const Interval & b) {
     return (a.start < b.start);
   }

     vector<Interval> merge(vector<Interval>& intervals) {
         vector<Interval> res;
         if(intervals.size() == 0) { return res; }
         std::sort(intervals.begin(), intervals.end(), Solution::myfunc);
         res.push_back(intervals[0]);

         for(int i = 1; i < intervals.size(); i++) {
           if(res.back().end >= intervals[i].start) {
             res.back().end = max(res.back().end, intervals[i].end);
           } else {
             res.push_back(intervals[i]);
           }
         }
         return res;
     }
 };
